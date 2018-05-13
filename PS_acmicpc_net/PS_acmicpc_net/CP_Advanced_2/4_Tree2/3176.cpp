#include <stdio.h>
#define MAXN 100005
#define MAXP 20
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define MAX(a,b) (((a)<(b)) ? (b) : (a))

struct Node
{
	int to;
	int r;
	int next;
};

Node S[MAXN << 1];
int Cnt;

struct List
{
	int head = -1;
	int sz = 0;

	void push(int x, int r)
	{
		S[Cnt] = { x, r, head };
		head = Cnt++;
		sz++;
	}
};

int N, M;
List G[MAXN];
int p[MAXN][MAXP];
int mn[MAXN][MAXP];
int mx[MAXN][MAXP];
int d[MAXN];

void DFS(int x, int pre)
{
	int cur = G[x].head;
	while (cur != -1)
	{
		if (S[cur].to != pre)
		{
			p[S[cur].to][0] = x;
			mn[S[cur].to][0] = S[cur].r;
			mx[S[cur].to][0] = S[cur].r;
			d[S[cur].to] = d[x] + 1;
			DFS(S[cur].to, x);
		}
		cur = S[cur].next;
	}
}

void LCAmnmx(int a, int b, int& minv, int& maxv)
{
	minv = 2e9;
	maxv = 0;
	if (d[a] > d[b]) { int t = a; a = b; b = t; }

	int x = d[b] - d[a];
	for (int i = MAXP - 1; i >= 0; i--)
		if (x & (1 << i))
		{
			minv = MIN(minv, mn[b][i]);
			maxv = MAX(maxv, mx[b][i]);
			b = p[b][i];
		}

	if (a == b) return;

	for (int i = MAXP - 1; i >= 0; i--)
	{
		if (p[a][i] != p[b][i])
		{
			minv = MIN(minv, MIN(mn[a][i], mn[b][i]));
			maxv = MAX(maxv, MAX(mx[a][i], mx[b][i]));
			a = p[a][i];
			b = p[b][i];
		}
	}
	minv = MIN(minv, MIN(mn[a][0], mn[b][0]));
	maxv = MAX(maxv, MAX(mx[a][0], mx[b][0]));
	return;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1, a, b, c; i < N; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a].push(b, c);
		G[b].push(a, c);
	}

	for (int i = 1; i <= N; i++) for (int j = 0; j < 20; j++) p[i][j] = -1, mn[i][j] = 2e9, mx[i][j] = -1;
	DFS(1, 0);

	for (int k = 1; k < MAXP; k++)
		for (int i = 1; i <= N; i++)
			if (p[i][k - 1] >= 0)
			{
				p[i][k] = p[p[i][k - 1]][k - 1];
				mn[i][k] = MIN(mn[i][k - 1], mn[p[i][k - 1]][k - 1]);
				mx[i][k] = MAX(mx[i][k - 1], mx[p[i][k - 1]][k - 1]);
			}

	scanf("%d", &M);
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		int ans1, ans2;
		LCAmnmx(a, b, ans1, ans2);
		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}