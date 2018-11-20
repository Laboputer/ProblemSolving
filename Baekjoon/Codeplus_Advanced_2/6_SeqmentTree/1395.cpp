#include <stdio.h>
#define MAXN 100005

long long seg[MAXN << 2];
long long lazy[MAXN << 2];
int N, M;

void update_lazy(int n, int l, int r)
{
	if (lazy[n] != 0)
	{
		if (lazy[n] & 1) seg[n] = (r - l + 1) - seg[n];

		if (l != r)
		{
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update_range(int n, int l, int r, int ll, int rr)
{
	update_lazy(n, l, r);
	if (rr < l || r < ll) return;

	if (ll <= l && r <= rr)
	{
		lazy[n] += 1;
		update_lazy(n, l, r);
		return;
	}

	if (l != r)
	{
		update_range(n * 2, l, (l + r) / 2, ll, rr);
		update_range(n * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
		seg[n] = seg[n * 2] + seg[n * 2 + 1];
	}
}

long long query(int n, int l, int r, int ll, int rr)
{
	update_lazy(n, l, r);
	if (rr < l || r < ll) return 0;

	if (ll <= l && r <= rr) return seg[n];
	return query(n * 2, l, (l + r) / 2, ll, rr) + query(n * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0, a, b, c; i < M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) update_range(1, 1, N, b, c);
		else printf("%d\n", query(1, 1, N, b, c));
	}
	return 0;
}