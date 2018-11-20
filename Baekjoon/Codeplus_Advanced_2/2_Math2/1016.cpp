#include <stdio.h>

long long mn, mx;
int d[1000005];

int main()
{
	scanf("%lld%lld", &mn, &mx);
	for (int i = 0; i < 1000005; i++) d[i] = 1;

	for (long long i = 2; i*i <= mx; i++)
	{
		long long k = i*i;
		for (long long j = mn - mn%k; j <= mx; j += k)
			if (j - mn >= 0) d[j - mn] = 0;
	}

	int ans = 0; for (int i = 0; i <= mx - mn; i++) if (d[i]) ans++;
	printf("%d\n", ans);
	return 0;
}