#include <stdio.h>
#define MAXN 5005

long long N, K;
long long L[MAXN], M[MAXN], G[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &N, &K);
		for (int i = 0; i < N; i++) scanf("%lld%lld%lld", &L[i], &M[i], &G[i]);

		long long ans = 0;
		long long l = 0, r = 1ll << 31;
		while (l <= r)
		{
			long long m = (l + r) / 2;
			long long cnt = 0;
			for (int i = 0; i < N; i++)
			{
				if (L[i] - M[i] <= m && m <= L[i]) cnt += ((m - (L[i] - M[i])) / G[i]) + 1;
				else if (L[i] < m) cnt += M[i] / G[i] + 1;
			}
			
			if (cnt >= K) ans = m, r = m - 1;
			else l = m + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}