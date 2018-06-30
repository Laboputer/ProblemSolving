#include <stdio.h>
#define MAXN 500005

int a[MAXN];
int N, M;

void SWAP(int i, int j) { int tmp = a[i]; a[i] = a[j]; a[j] = tmp; }
void Qsort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;
	if (l + 2 < r)
	{
		if ((a[l] < a[m] && a[m] < a[r]) || (a[r] < a[m] && a[m] < a[l])) SWAP(m, r);
		else if ((a[m] < a[l] && a[l] < a[r]) || (a[r] < a[m] && a[m] < a[l])) SWAP(l, r);
	}

	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (a[i] < a[r])
		{
			j++;
			SWAP(i, j);
		}
	}

	j++;
	SWAP(j, r);
	Qsort(l, j - 1);
	Qsort(j + 1, r);
}


bool BinarySearch(int l, int r, int tar)
{
	int ll = l, rr = r;

	while (ll <= rr)
	{
		int m = (ll + rr) / 2;
		if (a[m] == tar) return true;
		else if (a[m] < tar) ll = m + 1;
		else rr = m - 1;
	}
	return false;
}

int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	Qsort(0, N - 1);
	scanf("%d", &M);
	int val;
	while (M--)
	{
		scanf("%d", &val);
		if (BinarySearch(0, N - 1, val)) printf("1 ");
		else printf("0 ");
	}

	return 0;
}