#include <stdio.h>
#define MAXN 105
#define MAX(a,b) (((a)<(b)) ? (b) : (a))

int N, M;
long long a[MAXN], b[MAXN];
long long d[MAXN][MAXN];

long long F(int i, int j)
{
	long long& ref = d[i][j];
	if (ref != -1) return ref;

	ref = 2;
	long long big = MAX(a[i], b[j]);
	for (int k = i + 1; k <= N; k++) if (big < a[k]) ref = MAX(ref, (F(k, j) + 1));
	for (int k = j + 1; k <= M; k++) if (big < b[k]) ref = MAX(ref, (F(i, k) + 1));
	return ref;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) scanf("%lld", &a[i]);
		for (int i = 1; i <= M; i++) scanf("%lld", &b[i]);
		a[0] = b[0] = -2e18;
		for (int i = 0; i <= N; i++) for (int j = 0; j <= M; j++) d[i][j] = -1;
		printf("%lld\n", F(0, 0) - 2);
	}

	return 0;
}