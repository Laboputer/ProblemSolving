#include <stdio.h>
#define MAXN 1005

struct edge
{
	int e, r;
};

int N, M;
edge E[MAXN][MAXN];
int cnt[MAXN];

int d[MAXN];
int ok[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0, a, b, c; i < M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		E[a][cnt[a]].e = b;
		E[a][cnt[a]++].r = c;
	}
	int x, y; scanf("%d%d", &x, &y);
	for (int i = 1; i <= N; i++) d[i] = 2e9;
	d[x] = 0, ok[x] = 1;
	
	int cur = x;
	while (1)
	{
		for (int i = 0; i < cnt[cur]; i++)
			if (d[E[cur][i].e] > d[cur] + E[cur][i].r) 
				d[E[cur][i].e] = d[cur] + E[cur][i].r;

		int val = 2e9, idx = -1;
		for (int i = 1; i <= N; i++) if (!ok[i] && val > d[i]) val = d[i], idx = i;
		if (idx == -1) break;
		ok[idx] = 1;
		cur = idx;
	}
	printf("%d\n", d[y]);

	return 0;
}