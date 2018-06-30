#include <stdio.h>
#define MAXN 10005

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

int arr1[MAXN], arr2[MAXN];
int cnt1, cnt2;

int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	SORT(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		if (a[i] <= 0) arr1[cnt1++] = a[i];
		else arr2[cnt2++] = a[i];
	}
	
	int ans = 0;
	if (cnt1 & 1) ans += arr1[--cnt1];
	if (cnt2 & 1) ans += arr2[0];

	for (int i = 0; i < cnt1; i+=2) ans += arr1[i] * arr1[i + 1];
	for (int i = cnt2 & 1; i < cnt2; i+=2) ans += (arr2[i] * arr2[i + 1] > arr2[i] + arr2[i + 1]) ? arr2[i] * arr2[i + 1] : arr2[i] + arr2[i + 1];

	printf("%d\n", ans);

	return 0;
}