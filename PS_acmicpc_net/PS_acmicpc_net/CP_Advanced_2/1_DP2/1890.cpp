#include <stdio.h>
#define MAXN 105

int N;
long long a[MAXN][MAXN];
long long d[MAXN][MAXN];

int main()
{
	scanf("%d", &N); for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%lld", &a[i][j]);
	d[1][1] = 1;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
	{
		if (i == N && j == N) break;
		if (i + a[i][j] <= N) d[i + a[i][j]][j] += d[i][j];
		if (j + a[i][j] <= N) d[i][j + a[i][j]] += d[i][j];
	}

	printf("%lld\n", d[N][N]);

	return 0;
}