#include <stdio.h>
#define MIN(a,b) ((a<b) ?(a) : (b))
#define MAX(a,b) ((a<b) ? (b) : (a))
#define MAXN 100005

struct Node
{
	int mn=2e9, mx=0;
};

int N, M;
int a[MAXN];
Node grp[1000];
int sqrt;

Node qry(int l, int r)
{
	Node n;
	while (l%sqrt != 0 && l <= r)
	{
		if (n.mn > a[l]) n.mn = a[l];
		if (n.mx < a[l]) n.mx = a[l];
		l++;
	}

	while ((r + 1) % sqrt != 0 && l <= r)
	{
		if (n.mn > a[r]) n.mn = a[r];
		if (n.mx < a[r]) n.mx = a[r];
		r--;
	}

	while (l <= r)
	{
		if (n.mn > grp[l / sqrt].mn) n.mn = grp[l / sqrt].mn;
		if (n.mx < grp[l / sqrt].mx) n.mx = grp[l / sqrt].mx;
		l += sqrt;
	}
	return n;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	
	sqrt = 0;
	while (sqrt*sqrt <= N) sqrt++;
	sqrt--;

	for (int i = 0; i < N; i++)
	{
		grp[i / sqrt].mn = MIN(grp[i / sqrt].mn, a[i]);
		grp[i / sqrt].mx = MAX(grp[i / sqrt].mx, a[i]);
	}

	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		Node res = qry(a - 1, b - 1);
		printf("%d %d\n", res.mn, res.mx);
	}

	return 0;
}