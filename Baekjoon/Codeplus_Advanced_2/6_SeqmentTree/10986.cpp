#include <stdio.h>
#define MAXN 1000005

int N, M;
long long a[MAXN];
long long sum[MAXN];

long long cnt[2005];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
	
	sum[0] = 0; 
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];
	
	for (int i = 0; i <= N; i++) cnt[sum[i] % M]++;
	long long ans = 0;
	for (int i = 0; i <= 2000; i++) if (cnt[i] >= 2) ans += (cnt[i] * cnt[i] - cnt[i]) / 2;
	
	printf("%lld\n", ans);
	return 0;
}