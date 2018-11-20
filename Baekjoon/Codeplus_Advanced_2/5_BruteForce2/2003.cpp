#include <stdio.h>
#define MAXN 10005

int N, M;
int a[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	int ans = 0;
	int l = 0, r = 0, sum = 0;
	while (1)
	{
		if (sum <= M)
		{
			if (sum == M) ans++;
			if (r == N) break;
			sum += a[r++];
		}
		else sum -= a[l++];
	}

	printf("%d\n", ans);
	return 0;
}