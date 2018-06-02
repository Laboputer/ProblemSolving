#include <stdio.h>
#define MAXN 805
#define MIN(a,b) ((a<b) ? (a) : (b))

int N, E;
int dist[MAXN][MAXN];
int main()
{
	scanf("%d%d", &N, &E);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = 1e9;
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 0, a, b, c; i < E; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (dist[a][b] > c) dist[a][b] = c;
		if (dist[b][a] > c) dist[b][a] = c;
	}

	for (int x = 1; x <= N; x++)
	{
		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
			dist[i][j] = MIN(dist[i][j], dist[i][x] + dist[x][j]);
	}

	int a, b; scanf("%d%d", &a, &b);
	int x, y;
	if (dist[1][a] == 1e9 || dist[a][b] == 1e9 || dist[b][N] == 1e9) x = 2e9;
	else x = dist[1][a] + dist[a][b] + dist[b][N];
	if (dist[1][b] == 1e9 || dist[b][a] == 1e9 || dist[a][N] == 1e9) y = 2e9;
	else y = dist[1][b] + dist[b][a] + dist[a][N];

	printf("%d\n", (MIN(x, y) == 2e9) ? -1 : MIN(x, y));
	
	return 0;
}