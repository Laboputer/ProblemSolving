#include <stdio.h>
#define MAXN 3005

struct UF
{
	int set[MAXN];
	
	void init()
	{
		for (int i = 0; i < MAXN; i++) set[i] = i;
	}
	int Find(int x)
	{
		return set[x] = (set[x] == x) ? x : Find(set[x]);
	}
	void Union(int a, int b)
	{
		set[Find(a)] = Find(b);
	}
};


int N;
int x[MAXN], y[MAXN], r[MAXN];
bool v[MAXN];
UF uf;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);
		uf.init();

		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		{
			if ((r[i] + r[j]) * (r[i] + r[j]) >= ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])))
				uf.Union(i, j);
		}

		for (int i = 0; i < N; i++) v[i] = 0;
		int ans = 0;
		while (1)
		{
			int idx = -1;
			for (int i = 0; i < N; i++) if (v[i] == 0) { idx = i; break; }
			if (idx == -1) break;

			ans++;
			int target = uf.Find(idx);
			for (int i = idx; i < N; i++)
				if (v[i] == 0 && uf.Find(i) == target) v[i] = 1;
		}

		printf("%d\n", ans);
	}
	return 0;
}