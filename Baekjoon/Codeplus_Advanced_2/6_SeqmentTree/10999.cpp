#include <stdio.h>
#define MAXN 1000005

long long seg[MAXN << 2];
long long lazy[MAXN << 2];
long long arr[MAXN];
int N, M, K;

long long init(int n, int l, int r)
{
	if (l == r)
		return seg[n] = arr[l];
	else return seg[n] = init(n * 2, l, (l + r) / 2) + init(n * 2 + 1, (l + r) / 2 + 1, r);
}

void update_lazy(int n, int l, int r)
{
	if (lazy[n] != 0)
	{
		seg[n] += (r - l + 1)*lazy[n];
		if (l != r)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update_range(int n, int l, int r, int ll, int rr, long long diff)
{
	update_lazy(n, l, r);
	if (rr < l || r < ll) return;

	if (ll <= l && r <= rr)
	{
		lazy[n] += diff;
		update_lazy(n, l, r);
		return;
	}

	if (l != r)
	{
		update_range(n * 2, l, (l + r) / 2, ll, rr, diff);
		update_range(n * 2 + 1, (l + r) / 2 + 1, r, ll, rr, diff);
		seg[n] = seg[n * 2] + seg[n * 2 + 1];
	}
}

long long query_sum(int n, int l, int r, int ll, int rr)
{
	update_lazy(n, l, r);
	if (rr < l || r < ll) return 0;

	if (ll <= l && r <= rr) return seg[n];
	return query_sum(n * 2, l, (l + r) / 2, ll, rr) + query_sum(n * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
	for (int i = 1; i <= 4 * MAXN; i++) lazy[i] = 0;

	init(1, 1, N);
	int a, b, c;
	long long d;
	for (int i = 0; i < M + K; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d%d%lld", &b, &c, &d);
			update_range(1, 1, N, b, c, d);
		}
		else
		{
			scanf("%d%d", &b, &c);
			printf("%lld\n", query_sum(1, 1, N, b, c));
		}
	}
	return 0;
}