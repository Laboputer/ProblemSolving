#include <stdio.h>

long long N;
long long K;
int main()
{
	scanf("%lld%lld", &N, &K);
	long long ans;
	long long l = 1, r = 1e9;
	while (l <= r)
	{
		long long x = (l + r) >> 1;
		long long cnt = 0; // x 이하의 수의 개수

		for (long long i = 1; i <= N && i <= x; i++)
		{
			if (i*N <= x) cnt += N;
			else cnt += x / i;
		}

		if (K <= cnt) ans = x, r = x - 1;
		else l = x + 1;
	}
	printf("%lld\n", ans);

	return 0;
}