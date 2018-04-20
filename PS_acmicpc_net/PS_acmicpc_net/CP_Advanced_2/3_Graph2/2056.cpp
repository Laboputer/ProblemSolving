#include <stdio.h>
#define MAXN 10005

int N;
int in[MAXN][101];
int cost[MAXN];
int d[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &cost[i]);
		scanf("%d", &in[i][0]);
		for (int j = 1; j <= in[i][0]; j++)
			scanf("%d", &in[i][j]);
	}

	d[1] = cost[1];
	for (int i = 2; i <= N; i++)
	{
		int mx = 0;
		for (int j = 1; j <= in[i][0]; j++) if (mx < d[in[i][j]]) mx = d[in[i][j]];
		d[i] = mx + cost[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) if (ans < d[i]) ans = d[i];
	printf("%d\n", ans);

	return 0;
}