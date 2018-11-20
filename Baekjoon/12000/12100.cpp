#include <stdio.h>
#define MAXN 20

int N;
int m[MAXN][MAXN];
int arr[MAXN];
int cnt;
int ans = 0;

void F(int n)
{
	if (n == 5)
	{
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			if (ans < m[i][j]) ans = m[i][j];
		return;
	}

	int tmp[MAXN][MAXN]; // tmp������ �������� �θ� ��Ϳ��� �ٲ��..?
	                               // stack �޸� ��� �ٿ����ϳ�..
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) tmp[i][j] = m[i][j];
	
	// ����
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = 0; k < N; k++)
			if (m[i][k] != 0) arr[cnt++] = m[i][k];
		for (int k = 0; k < N; k++) m[i][k] = 0;

		if (cnt == 0) continue;
		int cur = 0;
		m[i][cur++] = arr[0];
		for (int k = 1; k < cnt; k++)
		{
			if (m[i][cur - 1] == arr[k])
			{
				m[i][cur - 1] += arr[k];
				if (k + 1 < cnt) m[i][cur++] = arr[k + 1], k++; // �������� �ϳ��� �׳ɳְ�
			}
			else m[i][cur++] = arr[k];
		}
	}
	F(n+1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// ������
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = N - 1; k >= 0; k--)
			if (m[i][k] != 0) arr[cnt++] = m[i][k];
		for (int k = 0; k < N; k++) m[i][k] = 0;

		if (cnt == 0) continue;
		int cur = N - 1;
		m[i][cur--] = arr[0];
		for (int k = 1; k < cnt; k++)
		{
			if (m[i][cur + 1] == arr[k])
			{
				m[i][cur + 1] += arr[k];
				if (k + 1 < cnt) m[i][cur--] = arr[k + 1], k++;
			}
			else m[i][cur--] = arr[k];
		}
	}
	F(n+1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// ����
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = 0; k < N; k++)
			if (m[k][i] != 0) arr[cnt++] = m[k][i];
		for (int k = 0; k < N; k++) m[k][i] = 0;

		if (cnt == 0) continue;
		int cur = 0;
		m[cur++][i] = arr[0];
		for (int k = 1; k < cnt; k++)
		{
			if (m[cur - 1][i] == arr[k])
			{
				m[cur - 1][i] += arr[k];
				if (k + 1 < cnt) m[cur++][i] = arr[k + 1], k++;
			}
			else m[cur++][i] = arr[k];
		}
	}
	F(n+1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// �Ʒ���
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = N - 1; k >= 0; k--)
			if (m[k][i] != 0) arr[cnt++] = m[k][i];
		for (int k = 0; k < N; k++) m[k][i] = 0;

		if (cnt == 0) continue;
		int cur = N - 1;
		m[cur--][i] = arr[0];
		for (int k = 1; k < cnt; k++)
		{
			if (m[cur + 1][i] == arr[k])
			{
				m[cur + 1][i] += arr[k];
				if (k + 1 < cnt) m[cur--][i] = arr[k + 1], k++;
			}
			else m[cur--][i] = arr[k];
		}
	}
	F(n+1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &m[i][j]);

	F(0);
	printf("%d\n", ans);

	return 0;
}