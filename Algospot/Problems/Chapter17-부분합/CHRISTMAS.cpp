#include <stdio.h>
#define MOD 20091101ll
#define MAXN 100005

struct val
{
	long long data;
	int idx;

	bool operator < (const val& rhs) const
	{
		if (data != rhs.data) return data < rhs.data;
		else return idx < rhs.idx;
	}
};

struct range
{
	int s;
	int e;

	bool operator < (const range& rhs) const
	{
		return e < rhs.e;
	}
};

int N, K;
val s[MAXN], tmp1[MAXN]; // ´ä1 
range rge[MAXN], tmp2[MAXN]; // ´ä2
int rcnt;

void SORT1(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	SORT1(l, m);
	SORT1(m + 1, r);
	
	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp1[p3++] = s[p1] < s[p2] ? s[p1++] : s[p2++];
	while (p1 <= m) tmp1[p3++] = s[p1++];
	while (p2 <= r) tmp1[p3++] = s[p2++];
	for (int i = l; i <= r; i++) s[i] = tmp1[i];
}

void SORT2(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	SORT2(l, m);
	SORT2(m + 1, r);

	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp2[p3++] = rge[p1] < rge[p2] ? rge[p1++] : rge[p2++];
	while (p1 <= m) tmp2[p3++] = rge[p1++];
	while (p2 <= r) tmp2[p3++] = rge[p2++];
	for (int i = l; i <= r; i++) rge[i] = tmp2[i];
}


int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &K);
		long long v[MAXN];
		for (int i = 0; i < N; i++) scanf("%lld", &v[i]);

		s[0].data = 0, s[0].idx = 0;
		for (int i = 1; i <= N; i++) s[i].data = (s[i - 1].data + v[i - 1]), s[i].idx = i;
		
		long long ans1 = 0;
		for (int i = 0; i <= N; i++) s[i].data %= (long long)K;
		SORT1(0, N);
		int d = -1;
		long long cnt = 0;
		for (int i = 0; i <= N; i++)
		{
			if (d != s[i].data)
			{
				ans1 = (ans1 + (cnt*cnt - cnt) / 2) % MOD;
				cnt = 1;
				d = s[i].data;
			}
			else cnt++;
		}
		if (cnt > 1) ans1 = (ans1 + (cnt*cnt - cnt) / 2) % MOD;

		rcnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (s[i - 1].data == s[i].data)
			{
				rge[rcnt].s = s[i - 1].idx;
				rge[rcnt].e = s[i].idx;
				rcnt++;
			}
		}

		int ans2 = 0;
		SORT2(0, rcnt - 1);
		int ocu = -1;
		for (int i = 0; i < rcnt; i++)
			if (ocu <= rge[i].s) ans2++, ocu = rge[i].e;
		
		printf("%lld %d\n", ans1, ans2);
	}
	return 0;
}