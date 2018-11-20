#include <stdio.h>
#define MAXN 404

int V, E;
long long edge[MAXN][MAXN];
long long d[MAXN][MAXN];
int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++) for (int j = 1; j <= V; j++) edge[i][j] = d[i][j] = 2e9;
	for (int i = 0; i < E; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if (edge[a][b] > c) edge[a][b] = c;
	}

	for (int i = 1; i <= V; i++) for (int j = 1; j <= V; j++) d[i][j] = edge[i][j];
	for (int i = 1; i <= V; i++) d[i][i] = 0;
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++) for (int j = 1; j <= V; j++)
			if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];

	long long ans = 2e9;
	for (int s = 1; s <= V; s++) for (int e = 1; e <= V; e++)
	{
		if (s == e) continue;
		if (ans > d[s][e] + d[e][s]) ans = d[s][e] + d[e][s];
	}
	// 이 방법 말고 다른 방법은
	// d[i][i]=0 이 아니라 d[i][i]를 무한대로 두면 플로이드가 사이클을 찾게 된다.
	// 즉 d[i][i]를 무한대로 둔 후에 플로이드를 돌리고 d[i][i]를 봐도 정답을 구할 수 있다.
	printf("%lld", (ans == 2e9) ? -1 : ans);

	return 0;
}