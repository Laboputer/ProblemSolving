#include <stdio.h>

int K, N;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &K, &N);

		long long p = 1983;
		long long cur = 1983;
		int sum = 0;
		
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			cur = (cur * 214013ll + 2531011ll) % (1ll << 32);
			int val = cur % 10000ll + 1;
			sum += val;
			
			while (sum >= K)
			{
				if (sum == K) ans++;
				p = (p * 214013ll + 2531011ll) % (1ll << 32);
				sum -= (p % 10000ll + 1);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}