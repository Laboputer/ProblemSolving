#include <stdio.h>
#define MAXN 105
#define MOD 1000000007ll

int N;
long long d[MAXN];
long long sym[MAXN]; // ´ëÄª°ª

int main()
{
	d[1] = 1, d[2] = 2;
	for (int i = 3; i < MAXN; i++) d[i] = (d[i - 1] + d[i - 2]) % MOD;

	sym[0] = 1, sym[1] = 1, sym[2] = 2, sym[3] = 1;
	for (int i = 4; i <= MAXN; i++) sym[i] = (sym[i - 2] + sym[i - 4]) % MOD;

	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		printf("%lld\n", (d[N] - sym[N] + MOD) % MOD);
	}
	return 0;
}