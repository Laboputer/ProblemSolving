#include <stdio.h>
#define MAXN 55

int N, M;
char name[MAXN][11];
int pcnt[MAXN], fcnt[MAXN];
int people[MAXN][MAXN], food[MAXN][MAXN]; // g1 �ش� ����� ���� �� �ִ� ����, g2 �ش� ������ ���� �� �ִ� ���
int ans;

// 1. void F(int n, long long state, int c) // ���� n��° ������� ó���߰�, state ������ ���� ���� (c������) 
// 2. void F(int m, long long state, int c) // ���� m��° ���ı��� ó���߰�, ����� �ʿ���� ���state (c�� ��������)
// �� �ΰ� ����ġ�� �ص� ����

void F(long long state, int c) // ���� ó���� ��� state�� �־����� c�� ������ ���� ����
{
	if (ans <= c) return;
	if (state == (1ll << N) - 1)
	{
		if (ans > c) ans = c;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (state & (1ll << i)) continue;

		for (int j = 0; j < pcnt[i]; j++)
		{
			long long f = 0;
			for (int k = 0; k < fcnt[people[i][j]]; k++)
				f += (1ll << food[people[i][j]][k]);
			F(state | f, c + 1);
		}
		return;
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) scanf("%s", name[i]);

		for (int i = 0; i < N; i++) pcnt[i] = 0;
		for (int i = 0; i < M; i++) fcnt[i] = 0;

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &fcnt[i]);
			char str[11];
			for (int j = 0; j < fcnt[i]; j++)
			{
				scanf("%s", str);
				for (int k = 0; k < N; k++)
				{
					bool flag = 1;
					for (int z = 0; (name[k][z] || str[z]) && flag; z++) if (name[k][z] != str[z]) flag = 0;
					if (flag)
					{
						people[k][pcnt[k]++] = i;
						food[i][j] = k;
						break;
					}
				}
			}
		}

		ans = 2e9;
		F(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}