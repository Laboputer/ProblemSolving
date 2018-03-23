#include <stdio.h>
#define MAXN 200005

int N, C;
int X[MAXN];

void SWAP(int i, int j) { if (i == j) return; int t = X[i]; X[i] = X[j]; X[j] = t; }

void SORT(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SWAP(m, r);

	int ll = l, rr = r - 1;
	while (ll <= rr)
	{
		while (ll <= rr && X[r] <= X[rr]) rr--;
		while (ll <= rr && X[ll] <= X[r]) ll++;
		if (ll < rr) SWAP(ll, rr);
	} 
	SWAP(ll, r);
	SORT(l, ll - 1);
	SORT(ll + 1, r);
}

bool P(int k)
{
	int c = C - 1;
	int p = X[0];
	
	for (int i = 1; i < N; i++)
	{
		if (k <= X[i] - p) p = X[i], c--;
		if (c <= 0) return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) scanf("%d", &X[i]);
	SORT(0, N - 1);
	int l = 1, r = X[N - 1] - X[0];

	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (P(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r);

	return 0;
}