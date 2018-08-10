#include <stdio.h>
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define MAX(a,b) (((b)<(a)) ? (a) : (b))
#define MAXN 105

struct UF
{
	int set[MAXN];
	UF() { for (int i = 0; i < MAXN; i++) set[i] = i; }
	int Find(int x) { return set[x] = (set[x] == x) ? x : Find(set[x]); }
	void Union(int a, int b) { set[Find(a)] = Find(b); }
};

int N;
double x[MAXN], y[MAXN];
double dist[MAXN][MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%lf%lf", &x[i], &y[i]);

		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		{
			double dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
			dist[i][j] = dis;
		}

		double ans = 1000;
		double l = 0.0, r = 1000.0;
		for (int i = 0; i < 30 && (l < r); i++)
		{
			double m = (l + r) / 2.0;
			UF uf;
			for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) if (dist[i][j] <= m * m) uf.Union(i, j);
			bool flag = true;
			for (int i = 1; i < N; i++) if (uf.Find(i) != uf.Find(0)) flag = false;

			if (flag) ans = m, r = m;
			else l = m;
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}