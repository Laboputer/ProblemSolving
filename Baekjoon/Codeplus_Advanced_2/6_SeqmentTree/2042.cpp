#include <stdio.h>
#define MAXN 1000005

long long tree[MAXN << 2];
long long arr[MAXN];
int N, M, K;

void update(int n, int l, int r, int idx, long long diff)
{
	if (idx < l || r < idx) return;
	tree[n] += diff;

	if (l != r)
	{
		update(n * 2, l, (l + r) / 2, idx, diff);
		update(n * 2 + 1, (l + r) / 2 + 1, r, idx, diff);
	}
}

long long qry(int n, int l, int r, int ll, int rr)
{
	if (rr < l || r < ll) return 0;
	if (ll <= l && r <= rr) return tree[n];

	return qry(n * 2, l, (l + r) / 2, ll, rr) + qry(n * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);

	for (int i = 1; i <= N; i++) update(1, 1, N, i, arr[i]);
	for (long long i = 0, a, b, c; i < M + K; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1)
		{
			update(1, 1, N, b, c - arr[b]);
			arr[b] = c;
		}
		else
		{
			printf("%lld\n", qry(1, 1, N, b, c));
		}
	}

	return 0;
}