#include <stdio.h>
#define MAXN 10005

int K, N;
long long a[MAXN];
int main()
{
	scanf("%d%d", &K, &N);
	for (int i = 0; i < K; i++) scanf("%lld", &a[i]);

	long long lo = 1, hi = 1e15;
	while (lo <= hi)
	{
		long long m = (lo + hi) / 2;
		long long cnt = 0;
		for (int i = 0; i < K; i++) cnt += a[i] / m;
		if (cnt >= (long long)N) lo = m + 1;
		else hi = m - 1;
	}

	printf("%lld\n", hi);

	return 0;
}