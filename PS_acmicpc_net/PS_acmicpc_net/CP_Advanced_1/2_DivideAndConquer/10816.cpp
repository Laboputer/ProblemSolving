#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 500005

int a[MAXN], tmp[MAXN];
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
void Msort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;
	Msort(l, m);
	Msort(m + 1, r);

	int p1 = l, p2 = m + 1;
	int p3 = l;

	while (p1 <= m || p2 <= r)
	{
		if (p1 > m) tmp[p3++] = a[p2++];
		else if (p2 > r) tmp[p3++] = a[p1++];
		else if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
		else tmp[p3++] = a[p2++];
	}
	for (int i = l; i <= r; i++) a[i] = tmp[i];
}


int lower_BinarySearch(int l, int r, int tar)
{
	int ll = l, rr = r;

	int idx = -1;
	while (ll <= rr)
	{
		int m = (ll + rr) / 2;
		if (a[m] == tar) idx = m, rr = m - 1;
		else if (a[m] < tar) ll = m + 1;
		else rr = m - 1;
	}
	return idx;
}

int upper_BinarySearch(int l, int r, int tar)
{
	int ll = l, rr = r;

	int idx = -1;
	while (ll <= rr)
	{
		int m = (ll + rr) / 2;
		if (a[m] == tar) idx = m, ll = m + 1;
		else if (a[m] < tar) ll = m + 1;
		else rr = m - 1;
	}
	return idx;
}

int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	//Qsort(0, N - 1);
	//sort(a, a + N);
	Msort(0, N - 1);
	
	scanf("%d", &M);
	int val;
	while (M--)
	{
		scanf("%d", &val);

		int cnt = lower_BinarySearch(0, N - 1, val);
		if (cnt == -1) printf("0 ");
		else printf("%d ", upper_BinarySearch(0, N - 1, val) - cnt + 1);
	}

	return 0;
}