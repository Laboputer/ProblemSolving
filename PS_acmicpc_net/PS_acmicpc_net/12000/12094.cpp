#include <stdio.h>
#define MAXN 20

int N;
int m[MAXN][MAXN];
int arr[MAXN];
int cnt;
int ans = 0;

void F(int n, int mx)
{
	if (ans >= (mx << (10 - n))) return; // 현재 dpeth에서 가장 큰수가 다 합쳐져도 이미 구한 최대값 못구하면 플러닝
	if (n == 10)
	{
		if (ans < mx) ans = mx;
		return;
	}

	int tmp[MAXN][MAXN];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) tmp[i][j] = m[i][j];

	// 왼쪽
	int val = 0;
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
				if (val < m[i][cur - 1]) val = m[i][cur - 1];
				if (k + 1 < cnt) m[i][cur++] = arr[k + 1], k++; // 합쳐지면 하나는 그냥넣고
			}
			else m[i][cur++] = arr[k];
		}
	}
	F(n + 1, mx < val ? val : mx);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// 오른쪽
	val = 0;
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
				if (val < m[i][cur + 1]) val = m[i][cur + 1];
				if (k + 1 < cnt) m[i][cur--] = arr[k + 1], k++;
			}
			else m[i][cur--] = arr[k];
		}
	}
	F(n + 1, mx < val ? val : mx);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// 위쪽
	val = 0;
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
				if (val < m[cur - 1][i]) val = m[cur - 1][i];
				if (k + 1 < cnt) m[cur++][i] = arr[k + 1], k++;
			}
			else m[cur++][i] = arr[k];
		}
	}
	F(n + 1, mx < val ? val : mx);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];

	// 아래쪽
	val = 0;
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
				if (val < m[cur + 1][i]) val = m[cur + 1][i];
				if (k + 1 < cnt) m[cur--][i] = arr[k + 1], k++;
			}
			else m[cur--][i] = arr[k];
		}
	}
	F(n + 1, mx < val ? val : mx);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) m[i][j] = tmp[i][j];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &m[i][j]);

	int val = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (val < m[i][j]) val = m[i][j];
	
	F(0, val);
	printf("%d\n", ans);

	return 0;
}