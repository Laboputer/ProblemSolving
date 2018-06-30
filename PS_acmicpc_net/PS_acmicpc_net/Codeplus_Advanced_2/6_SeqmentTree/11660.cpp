#include <stdio.h>
#define MAXN 1100

int N, M;
long long a[MAXN][MAXN];
long long sum[MAXN][MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &a[i][j]);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

	for (int i = 0, x1, y1, x2, y2; i < M; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
	}

	return 0;
}