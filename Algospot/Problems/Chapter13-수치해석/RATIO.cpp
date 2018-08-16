#include <stdio.h>

long long N, M, Z;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &N, &M);
		Z = M * 100ll / N;

		if (((M + (long long)2e9) * 100ll / (N + (long long)2e9)) <= Z)
		{
			printf("-1\n");
			continue;
		}

		long long l = 0, r = 2e9;
		long long ans = 0;
		while (l <= r)
		{
			long long x = (l + r) / 2;
			if (((M + x) * 100ll / (N + x)) >= Z + 1) ans = x, r = x - 1;
			else l = x + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}