#include <stdio.h>
#define MAXN 100005

int N, M;
int a[MAXN];
int sum[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	sum[0] = 0;
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + a[i];

	for (int i = 0, a, b; i < M; i++) scanf("%d%d", &a, &b), printf("%d\n", sum[b] - sum[a - 1]);
	return 0;
}