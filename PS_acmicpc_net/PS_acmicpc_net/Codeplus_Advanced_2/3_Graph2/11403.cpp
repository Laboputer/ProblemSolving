#include <stdio.h>
#define MAXN 105
#define MIN(a,b) ((a<b) ? (a) : (b))

int N, M;
int dist[MAXN][MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
	{
		scanf("%d", &dist[i][j]);
		if (dist[i][j] == 0) dist[i][j] = 1e9;
	}

	for (int x = 1; x <= N; x++)
	{
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
			dist[i][j] = MIN(dist[i][j], dist[i][x] + dist[x][j]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) printf("%d ",  (dist[i][j] >= 1e5) ? 0 : 1);
		printf("\n");
	}
	return 0;
}