#include <stdio.h>
#define MAXN 15

int a[MAXN];
int N,K;
int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);


	int ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		ans += K / a[i];
		K %= a[i];
	}

	printf("%d\n", ans);
	return 0;
}