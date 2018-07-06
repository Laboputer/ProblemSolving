#include <stdio.h>
#define MAXN 20005

int N;
int h[MAXN];

int MAX(int l, int r)
{
	return (l < r) ? r : l;
}

int MIN(int l, int r)
{
	return (l > r) ? r : l;
}

int F(int l, int r)
{
	if (l == r) return h[l];
	int m = (l + r) >> 1;

	int ans = MAX(F(l, m), F(m + 1, r));
	int mn = MIN(h[m], h[m + 1]);
	ans = MAX(ans, (2 * mn));
	int len = 2;
	int ll = m - 1, rr = m + 2;

	while (l<= ll || rr <= r)
	{
		len++;
		if ((ll < l) || ((rr <= r) && (h[ll] < h[rr]))) mn = MIN(mn, h[rr++]);
		else mn = MIN(mn, h[ll--]);
		ans = MAX(ans, len*mn);
	}
	return ans;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", &h[i]);
		printf("%d\n", F(0, N - 1));
	}
	return 0;
}