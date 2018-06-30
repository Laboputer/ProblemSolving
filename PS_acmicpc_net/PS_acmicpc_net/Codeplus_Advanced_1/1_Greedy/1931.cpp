#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100005

struct p
{
	int s, e;

	bool operator < (const p& rhs) const
	{
		if (e == rhs.e) return s < rhs.s;
		return e < rhs.e;
	}
};

p arr[MAXN];
int N;
void swap(int i, int j) { p tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp; }
void Qsort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;

	swap(r, m);

	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (arr[i] < arr[r])
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

int main()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &arr[i].s, &arr[i].e);
	Qsort(0, N - 1);
	int ans = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		if (end <= arr[i].s)
		{
			end = arr[i].e;
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}