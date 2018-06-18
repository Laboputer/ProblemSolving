#include <stdio.h>
#define MAXN 10005

int N;
int ind[MAXN][105];
int cost[MAXN];
int dist[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &cost[i]);
		scanf("%d", &ind[i][0]);
		for (int j = 1; j <= ind[i][0]; j++) scanf("%d", &ind[i][j]);
	}

	for (int i = 0; i < MAXN; i++) dist[i] = 2e9;
	// K번 작업에 대해 선행 관계에 있는(즉, K번 작업을 시작하기 전에 반드시 먼저 완료되어야 하는) 
	// 작업들의 번호는 모두 1 이상 (K-1) 이하이다.
	// 위의 조건 때문에 Queue를 통한 선행관계를 체크하지 않아도 됨이 자명하다.
	for (int i = 1; i <= N; i++)
	{
		int mx = 0;
		for (int j = 1; j <= ind[i][0]; j++) if (mx < dist[ind[i][j]]) mx = dist[ind[i][j]];
		dist[i] = mx + cost[i];
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) if (ans < dist[i]) ans = dist[i];
	printf("%d\n", ans);

	return 0;
}