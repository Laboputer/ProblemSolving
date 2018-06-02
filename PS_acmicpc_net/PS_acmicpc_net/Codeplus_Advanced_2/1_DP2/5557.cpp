#include <stdio.h>
#define MAXN 105

int N;
int a[MAXN];
long long d[MAXN][21];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	d[0][a[0]] = 1;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (0 <= j - a[i] && j - a[i] <= 20) d[i][j] += d[i - 1][j - a[i]];
			if (0 <= j + a[i] && j + a[i] <= 20) d[i][j] += d[i - 1][j + a[i]];
		}
	}
	printf("%lld\n", d[N - 2][a[N - 1]]);

	return 0;
}