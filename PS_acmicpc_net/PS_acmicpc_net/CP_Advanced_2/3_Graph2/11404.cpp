#include <stdio.h>
#define MAXN 105
#define MIN(a,b) ((a<b) ? (a) : (b))

int N, M;
long long dist[MAXN][MAXN];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = 1e15;
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 0, a, b, c; i < M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = MIN(dist[a][b], c);
	}

	for (int x = 1; x <= N; x++)
	{
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
			dist[i][j] = MIN(dist[i][j], dist[i][x] + dist[x][j]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) printf("%lld ", (dist[i][j] == 1e15) ? 0 : dist[i][j]);
		printf("\n");
	}
	return 0;
}