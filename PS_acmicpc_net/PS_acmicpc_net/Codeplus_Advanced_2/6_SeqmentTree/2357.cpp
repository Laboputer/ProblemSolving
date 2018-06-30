#include <stdio.h>
#define MAXN 100005
#define INF 2000000000
#define MIN(a,b) ((a<b) ? (a) : (b))
#define MAX(a,b) ((a<b) ? (b) : (a))

struct val
{
	int mn, mx;
};

int N, M;
val ST[MAXN << 2];

void update(int n, int s, int e, int idx, int x)
{
	if (idx < s || e < idx) return;
	ST[n].mn = MIN(ST[n].mn, x);
	ST[n].mx = MAX(ST[n].mx, x);
	
	if (s != e)
	{
		update(n * 2, s, (s + e) / 2, idx, x);
		update(n * 2 + 1, ((s + e) / 2) + 1, e, idx, x);
	}
}

val query(int n, int s, int e, int l, int r)
{
	if (e < l || r < s) return { INF , 0 };
	if (l <= s && e <= r) return ST[n];

	val q1 = query(n * 2, s, (s + e) / 2, l, r);
	val q2 = query(n * 2 + 1, ((s + e) / 2) + 1, e, l, r);
	return {MIN(q1.mn, q2.mn), MAX(q1.mx, q2.mx) };
}

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 0; i < MAXN * 4; i++) ST[i].mn = INF, ST[i].mx = 0;

	for (int i = 1, x; i <= N; i++)
	{
		scanf("%d", &x);
		update(1, 1, N, i, x);
	}

	for (int i = 0, x, y; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		val q = query(1, 1, N, x, y);
		printf("%d %d\n", q.mn, q.mx);
	}
	return 0;
}