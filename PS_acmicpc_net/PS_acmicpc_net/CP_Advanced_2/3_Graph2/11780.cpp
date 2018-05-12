#include <stdio.h>
#define MAXN 105

int N, M;
int dist[MAXN][MAXN];
int m[MAXN][MAXN];

int path[MAXN];
int cnt;
void P(int a, int b)
{
	if (m[a][b] == -1) return;
	P(a, m[a][b]);
	path[cnt++] = m[a][b];
	P(m[a][b], b);
}
int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = 1e9, m[i][j] = -1;
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 0, a, b, c; i < M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (dist[a][b] > c) dist[a][b] = c;
	}

	for (int i = 1; i <= N; i++)
		for (int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
				if (dist[a][b] > dist[a][i] + dist[i][b]) dist[a][b] = dist[a][i] + dist[i][b], m[a][b] = i;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) printf("%d ", dist[i][j] == 1e9 ? 0 : dist[i][j]);
		printf("\n");
	}
	
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
	{
		cnt = 0;
		P(i, j);

		if (i==j)
		{
			printf("0\n");
			continue;
		}

		printf("%d ", cnt + 2);
		printf("%d ", i);
		for (int i = 0; i < cnt; i++) printf("%d ", path[i]);
		printf("%d\n", j);
	}

	return 0;
}