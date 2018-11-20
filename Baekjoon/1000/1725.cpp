#include <stdio.h>
#define MAXN 100005
#define MAX(a,b) ((a<b) ? (b) : (a))
#define MIN(a,b) ((a<b) ? (a) : (b))

int N;
int h[MAXN];

int F(int l, int r)
{
	if (l == r) return h[l];

	int mid = (l + r) / 2;
	int ans = MAX(F(l, mid), F(mid + 1, r));

	int mn = MIN(h[mid], h[mid + 1]);
	int len = 2;
	int ll = mid - 1;
	int rr = mid + 2;
	ans = MAX(ans, mn*len);
	while (l <= ll || rr <= r)
	{
		while (l <= ll && mn <= h[ll]) len++, ll--;
		while (rr <= r && mn <= h[rr]) len++, rr++;

		ans = MAX(ans, mn*len);
		if (l > ll && rr > r) break;

		if (l > ll) len++, mn = h[rr], rr++;
		else if (rr > r) len++, mn = h[ll], ll--;
		else
		{
			if (h[ll] < h[rr]) len++, mn = h[rr], rr++;
			else len++, mn = h[ll], ll--;
		}
		ans = MAX(ans, mn*len);
	}

	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &h[i]);

	printf("%d", F(1, N));

	return 0;
}