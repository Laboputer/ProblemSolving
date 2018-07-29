#include <stdio.h>
#define MAXN 10005

typedef long long ll;

struct p
{
	ll m, e;
};

int N;
p arr[MAXN];
p tmp[MAXN];

void SORT(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SORT(l, m);
	SORT(m + 1, r);
	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (arr[p1].e > arr[p2].e) ? arr[p1++] : arr[p2++];
	while (p1 <= m) tmp[p3++] = arr[p1++];
	while (p2 <= r) tmp[p3++] = arr[p2++];
	for (int i = l; i <= r; i++) arr[i] = tmp[i];
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%lld", &arr[i].m);
		for (int i = 0; i < N; i++) scanf("%lld", &arr[i].e);
		SORT(0, N - 1);

		ll sum = 0;
		ll ans = 0;
		for (int i = 0; i < N; i++)
		{
			sum += arr[i].m;
			if (ans < sum + arr[i].e) ans = sum + arr[i].e;
		}
		printf("%lld\n", ans);
	}
	return 0;
}