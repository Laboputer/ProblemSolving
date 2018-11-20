#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 1000005

int N, M;
int a[2 * MAXN];
int tmp[2 * MAXN];

void swap(int i, int j) { int tmp = a[i]; a[i] = a[j]; a[j] = tmp; }
void Qsort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;
	swap(m, r);

	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (a[i] < a[r])
		{
			j++;
			swap(i, j);
		}
	}
	j++;
	swap(j, r);
	Qsort(l, j - 1);
	Qsort(j + 1, r);
}
void Msort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;
	Msort(l, m);
	Msort(m+1, r);

	int p1 = l, p2 = m+1;
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


int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N + M; i++) scanf("%d", &a[i]);
	//sort(a, a + N + M);
	//Qsort(0,N+M-1);
	Msort(0,N+M-1);

	for (int i = 0; i < N + M; i++) printf("%d ", a[i]);

	return 0;
}