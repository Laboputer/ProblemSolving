#include <stdio.h>
#define MAXN 105
#define MOD 1000000007ll

int N, L, R;
long long d[MAXN][MAXN][MAXN];

int main()
{
	scanf("%d%d%d", &N, &L, &R);
	d[1][1][1] = 1, d[2][1][2] = d[2][2][1] = 1;
	
	for (int i = 3; i <= N; i++) for (int j = 1; j <= L; j++) for (int k = 1; k <= R; k++)
		d[i][j][k] = (d[i - 1][j][k] * (i - 2) + d[i - 1][j - 1][k] + d[i - 1][j][k - 1]) % MOD;

	printf("%d\n", d[N][L][R]);

	return 0;
}