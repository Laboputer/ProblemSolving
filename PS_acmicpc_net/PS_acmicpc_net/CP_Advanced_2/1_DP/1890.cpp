#include <stdio.h>
#define MAXN 105

int N;
int a[MAXN][MAXN];
long long d[MAXN][MAXN];
int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &a[i][j]);
	d[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++) if (j + a[0][j] == i) d[0][i] += d[0][j];
		for (int j = 0; j < i; j++) if (j + a[j][0] == i) d[i][0] += d[j][0];
	}

	for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
	{
		for (int k = 0; k < i; k++) if (k + a[k][j] == i) d[i][j] += d[k][j];
		for (int k = 0; k < j; k++) if (k + a[i][k] == j) d[i][j] += d[i][k];
	}

	printf("%lld\n", d[N - 1][N - 1]);

	return 0;
}