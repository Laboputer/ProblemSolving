#include <stdio.h>
#define MAXN 11
#define MIN(a,b) ((a<b) ? (a) : (b))

int N;
int cost[MAXN][MAXN];
int dp[MAXN][1 << MAXN];

int S;
int F(int cur, int visited)
{
	if (visited == (1 << N) - 1)
		return cost[cur][S];

	int& ref = dp[cur][visited];
	if (ref != -1) return ref;

	ref = 2e9;
	for (int i = 0; i < N; i++)
	{
		if (visited & (1 << i)) continue;
		if (cost[cur][i] == 1e8) continue;

		visited |= (1 << i);
		ref = MIN(ref, cost[cur][i] + F(i, visited));
		visited &= ~(1 << i);
	}
	return ref;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		scanf("%d", &cost[i][j]);
		if (i != j && cost[i][j] == 0) cost[i][j] = 1e8;
	}

	int ans = 2e9;
	for (int i = 0; i < N; i++)
	{
		S = i;
		int space = (1 << N);
		for (int a = 0; a < N; a++) for (int b = 0; b < space; b++) dp[a][b] = -1;
		ans = MIN(ans, F(S, 1 << S));
	}
	printf("%d\n", ans);

	return 0;
}