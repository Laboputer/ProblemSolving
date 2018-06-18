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
	// K�� �۾��� ���� ���� ���迡 �ִ�(��, K�� �۾��� �����ϱ� ���� �ݵ�� ���� �Ϸ�Ǿ�� �ϴ�) 
	// �۾����� ��ȣ�� ��� 1 �̻� (K-1) �����̴�.
	// ���� ���� ������ Queue�� ���� ������踦 üũ���� �ʾƵ� ���� �ڸ��ϴ�.
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