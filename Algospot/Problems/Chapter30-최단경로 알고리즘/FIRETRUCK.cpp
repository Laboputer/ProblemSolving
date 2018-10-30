#include <stdio.h>
#define MAXN 1005
#define Q 100000
struct node
{
	int x;
	int dist;
};

int V, E, n, m;
int dist[MAXN];
bool v[MAXN];
node G[MAXN][MAXN];
int gcnt[MAXN];

int fire[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &V, &E, &n, &m);
		for (int i = 1; i <= V; i++) gcnt[i] = 0, v[i] = 0, dist[i] = 1e9;
		int a, b, t;
		for (int i = 0; i < E; i++)
		{
			scanf("%d%d%d", &a, &b, &t);
			G[a][gcnt[a]++] = { b,t };
			G[b][gcnt[b]++] = { a,t };
		}

		for (int i = 0; i < n; i++) scanf("%d", &fire[i]);
		for (int i = 0, x; i < m; i++)
		{
			scanf("%d", &x);
			dist[x] = 0;
		}

		for (int i = 1; i <= V; i++)
		{
			int mn = 1e9;
			int x = 0;
			for (int j = 1; j <= V; j++)
			{
				if (v[j]) continue;
				if (mn > dist[j]) mn = dist[j], x = j;
			}
			v[x] = 1;

			for (int j = 0; j < gcnt[x]; j++)
			{
				if (v[G[x][j].x]) continue;
				if (dist[G[x][j].x] > dist[x] + G[x][j].dist)
					dist[G[x][j].x] = dist[x] + G[x][j].dist;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) ans += dist[fire[i]];
		printf("%d\n", ans);
	}
	return 0;
}