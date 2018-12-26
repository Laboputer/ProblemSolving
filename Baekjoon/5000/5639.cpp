#include <stdio.h>
#define MAXN 10005

int N;
int a[MAXN];

void DQ(int l, int r)
{
	if (l > r) return;

	int m = l+1;
	while (m <= r && a[m] < a[l]) m++;

	DQ(l + 1, m - 1);
	DQ(m, r);
	printf("%d\n", a[l]);
}


int main()
{
	freopen("input.txt", "r", stdin);
	N = 0;
	while (scanf("%d", &a[N]) != EOF)
		N++;

	DQ(0, N - 1);
	return 0;
}