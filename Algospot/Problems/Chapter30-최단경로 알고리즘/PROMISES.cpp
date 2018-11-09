#include <stdio.h>

inline int MIN(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int V, M, N;
int d[200][200];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &V, &M, &N);
		for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) d[i][j] = 1e8;
		for (int i = 0; i < V; i++) d[i][i] = 0;

		for (int i = 0, a, b, c; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			d[a][b] = MIN(d[a][b], c);
			d[b][a] = MIN(d[b][a], c);
		}

		for (int k = 0; k < V; k++)
			for (int i = 0; i < V; i++) for (int j = 0; j < V; j++)
				d[i][j] = MIN(d[i][j], d[i][k] + d[k][j]);

		int ans = 0;
		for (int i = 0, a, b, c; i < N; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (d[a][b] > c)
			{
				d[a][b] = c;
				d[b][a] = c;
				//for (int i = 0; i < V; i++) for (int j = 0; j < V; j++)
				//	d[i][j] = MIN(d[i][j], d[i][a] + d[a][j]);
				//for (int i = 0; i < V; i++) for (int j = 0; j < V; j++)
				//	d[i][j] = MIN(d[i][j], d[i][b] + d[b][j]);
				for (int i = 0; i < V; i++) for (int j = 0; j < V; j++)
				{
					d[i][j] = MIN(d[i][j], d[i][a] + d[a][b] + d[b][j]);
					d[i][j] = MIN(d[i][j], d[i][b] + d[b][a] + d[a][j]);
				}
			}
			else ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}