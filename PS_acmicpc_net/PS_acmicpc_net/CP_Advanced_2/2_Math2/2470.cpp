#include <stdio.h>
#define MAXN 100005

int N;
int a[MAXN];

void SWAP(int i, int j) { int t = a[i]; a[i] = a[j]; a[j] = t; }
void SORT(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SWAP(m, r);
	int ll = l, rr = r - 1;
	while (ll <= rr)
	{
		while (ll <= rr && a[r] <= a[rr]) rr--;
		while (ll <= rr && a[ll] <= a[r]) ll++;
		if (ll < rr) SWAP(ll, rr);
	}
	SWAP(ll, r);
	SORT(l, ll - 1);
	SORT(ll + 1, r);
}

int main()
{
	scanf("%d", &N); 
	for (int i = 0; i < N; i++)scanf("%d", &a[i]);
	SORT(0, N - 1);

	int val = 2e9, l, r;
	int p1 = 0, p2 = N - 1;
	while (p1 < p2)
	{
		int v = a[p1] + a[p2];
		int abs = (v > 0) ? v : -v;
		if (val > abs) val = abs, l = p1, r = p2;

		if (v < 0) p1++;
		else if (v == 0) break;
		else p2--;
	}
	printf("%d %d\n", a[l], a[r]);

	return 0;
}