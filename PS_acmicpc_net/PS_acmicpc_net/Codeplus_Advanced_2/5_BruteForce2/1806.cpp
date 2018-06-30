#include <stdio.h>
#define MAXN 100005
#define MIN(a,b) ((a<b) ? (a) : (b))

int N, M;
int a[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	int ans = 2e9;
	int l = 0, sum = 0;
	
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
		while (sum >= M)
		{
			ans = MIN(ans, i - l + 1);
			sum -= a[l++];
		}
	}

	printf("%d\n", (ans == 2e9) ? 0 : ans);
	return 0;
}