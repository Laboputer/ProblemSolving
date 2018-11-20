#include <stdio.h>
#define MAXN 45

int N, S;
long long arr[MAXN];
long long S1[1 << 21], S2[1 << 21];
long long tmp[1 << 21];

void swap(long long* i, long long* j) {long long t = *i; *i = *j; *j = t; }

void SORT(long long* a, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SORT(a, l, m);
	SORT(a, m + 1, r);

	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (a[p1] < a[p2]) ? a[p1++] : a[p2++];
	while (p1 <= m) tmp[p3++] = a[p1++];
	while (p2 <= r) tmp[p3++] = a[p2++];

	for (int i = l; i <= r; i++) a[i] = tmp[i];
}

void power(long long* s, int l, int& r, long long sum)
{
	if (l > r)
	{
		s[++s[0]] = sum;
		return;
	}

	power(s, l + 1, r, sum);
	power(s, l + 1, r, sum + arr[l]);
}

int main()
{
	scanf("%d%d", &N, &S);
	for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);

	int m = N >> 1;
	power(S1, 1, m, 0);
	power(S2, m + 1, N, 0);

	SORT(S1, 1, S1[0]);
	SORT(S2, 1, S2[0]);
	
	long long ans = 0;
	int l = 1, r = S2[0];
	while ((l <= S1[0]) && (r >= 1))
	{
		long long s = S1[l] + S2[r];
		if (s == S)
		{
			long long cnt1 = 1, cnt2 = 1;
			while ((l < S1[0]) && (S1[l + 1] == S1[l])) l++, cnt1++;
			while ((r >= 2) && (S2[r - 1] == S2[r])) r--, cnt2++;
			ans += cnt1*cnt2;
			l++;
		}
		else if (s < S) l++;
		else r--;
	}
	if (S == 0) ans--;
	printf("%lld\n", ans);

	return 0;
}