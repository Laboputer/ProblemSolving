#include <stdio.h>
#include <math.h>
#define MAXN 505

struct UF
{
	int set[MAXN];
	void Init() { for (int i = 0; i < MAXN; i++) set[i] = i; }

	int Find(int x) 
	{
		if (set[x] == x) return x;
		else return set[x] = Find(set[x]);
	}
	void Union(int a, int b) { set[Find(a)] = Find(b); }
};

struct pos
{
	int i, j;
	int d;
};

int x[MAXN], y[MAXN];
pos edge[MAXN*MAXN];
pos tmp[MAXN*MAXN];
int ecnt;
int N, M;
UF uf;

void SORT(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	SORT(l, m);
	SORT(m + 1, r);

	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (edge[p1].d < edge[p2].d) ? edge[p1++] : edge[p2++];
	while (p1 <= m) tmp[p3++] = edge[p1++];
	while (p2 <= r) tmp[p3++] = edge[p2++];
	for (int i = l; i <= r; i++) edge[i] = tmp[i];
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) scanf("%d", &x[i]);
		for (int i = 0; i < N; i++) scanf("%d", &y[i]);

		int cnt = 0;
		uf.Init();
		for (int i = 0, a, b; i < M; i++)
		{
			scanf("%d%d", &a, &b);
			if (uf.Find(a) != uf.Find(b))
				uf.Union(a, b), cnt++;
		}

		ecnt = 0;
		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		{
			if (uf.Find(i) != uf.Find(j))
				edge[ecnt++] = { i,  j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) };
		}

		SORT(0, ecnt - 1);
		double ans = 0;

		int s = 0;
		while (cnt != N - 1)
		{
			int n1 = edge[s].i;
			int n2 = edge[s].j;
			int dis = edge[s].d;
			if (uf.Find(n1) != uf.Find(n2))
			{
				uf.Union(n1, n2);
				ans += sqrt((double)dis);
				cnt++;
			}
			s++;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}