#include <stdio.h>
#define MAXN 1000005

int N, M;
long long a[MAXN];

int main()
{
	scanf("%d%d", &N, &M); for (int i = 0; i < N; i++) scanf("%lld", &a[i]);

	int lo = 0, hi = 1e9;
	while (lo <= hi)
	{
		int m = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) if (a[i] > m) sum += (a[i] - m);
		if (sum >= (long long)M) lo = m + 1;
		else hi = m - 1;
	}
	printf("%d", hi);
	return 0;
}
