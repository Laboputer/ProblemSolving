#include <stdio.h>
#define MAXN 15

int N, M;
int G[MAXN][MAXN];
int V[MAXN];
int ans;
void F(int n)
{
	if (n == N)
	{
		ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!V[i])
		{
			V[i] = 1;
			for (int j = i + 1; j < N; j++)
			{
				if (!V[j] && G[i][j])
				{
					V[j] = 1;
					F(n + 2);
					V[j] = 0;
				}
			}
			V[i] = 0;
			break;
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) G[i][j] = 0;
		for (int i = 0; i < N; i++) V[i] = 0;
		for (int i = 0, a, b; i < M; i++) scanf("%d%d", &a, &b), G[a][b] = G[b][a] = 1;
		ans = 0;
		F(0);
		printf("%d\n", ans);
	}
	return 0;
}