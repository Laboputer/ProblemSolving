#include <stdio.h>
#define MAXN 105
#define MOD 10000000ll

int N;
long long d[MAXN][MAXN]; // i개를 사용하면서 j개가 밑줄에 있을때 개수
int main()
{
	for (int i = 1; i < MAXN; i++) d[i][i] = 1;
	for (int i = 2; i <= MAXN; i++) for (int j = 1; j < i; j++)
	{
		for (int k = 1; k <= (i - j); k++)
			d[i][j] = (d[i][j] + d[i - j][k] * (j + (k - 1))) % MOD;
	}

	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		long long ans = 0;
		for (int i = 1; i <= N; i++) ans = (ans + d[N][i]) % MOD;
		printf("%d\n", ans);
	}

	return 0;
}