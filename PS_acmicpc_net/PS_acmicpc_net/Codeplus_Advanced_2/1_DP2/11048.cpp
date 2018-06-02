#include <stdio.h>
#define MAXN 1005
#define MAX(a,b) ((a<b) ? (b) : (a))

int N, M;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &a[i][j]);
	
	dp[0][0] = a[0][0];
	for (int i = 1; i < M; i++) dp[0][i] = dp[0][i - 1] + a[0][i];
	for (int i = 1; i < N; i++) dp[i][0] = dp[i - 1][0] + a[i][0];
	for (int i = 1; i < N; i++) for (int j = 1; j < M; j++) dp[i][j] = MAX(MAX(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + a[i][j];
	
	printf("%d\n", dp[N - 1][M - 1]);
	return 0;
}