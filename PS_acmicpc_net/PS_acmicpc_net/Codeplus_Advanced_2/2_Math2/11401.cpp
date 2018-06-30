#include <stdio.h>
#define MAXN 4000005
#define MOD 1000000007ll

int N, K;
long long f[MAXN];

long long pow(long long n, long long r)
{
	if (r == 0) return 1;

	if (r & 1) return (n*pow(n, r - 1)) % MOD;
	long long p = pow(n, r / 2);
	return ((p*p) % MOD);
}

int main()
{
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; i++) f[i] = (f[i - 1] * (long long)i) % MOD;
	scanf("%d%d", &N, &K);

	printf("%lld\n", (f[N] * pow((f[N - K] * f[K]) % MOD, MOD - 2)) % MOD);
	return 0;
}