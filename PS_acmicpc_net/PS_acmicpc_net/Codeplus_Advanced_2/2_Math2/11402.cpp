#include <stdio.h>
#define MAXN 2005

long long f[MAXN];
long long N, K, M;
int main(void)
{
	scanf("%lld%lld%lld", &N, &K, &M);
	f[0] = f[1] = 1; for (int i = 2; i < MAXN; i++) f[i] = (f[i - 1] * i) % M;

	long long rst = 1;
	long long n = N, k = K;
	while (n != 0)
	{
		/* Lucas Theorem */
		int a = n % M, b = k % M;
		if (a < b) { rst = 0; break; }

		/*Fermat's little theorem*/
		rst = (rst*f[a]) % M;
		for (int i = 0; i < M - 2; i++) rst = (rst*f[b] * f[a - b]) % M;

		n /= M, k /= M;
	}

	printf("%lld\n", rst);

	return 0;
}