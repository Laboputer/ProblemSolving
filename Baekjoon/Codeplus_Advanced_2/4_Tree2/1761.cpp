#include <stdio.h>
#define MAXN 100005
#define MAXP 20

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
int d[MAXN];
int dist[MAXN];

void DFS(int x, int pre)
{
	int cur = G[x].head;
	while (cur != -1)
	{
		if (S[cur].to != pre)
		{
			p[S[cur].to][0] = x;
			d[S[cur].to] = d[x] + 1;
			dist[S[cur].to] = dist[x] + S[cur].r;
			DFS(S[cur].to, x);
		}
		cur = S[cur].next;
	}
}

int LCA(int a, int b)
{
	if (d[a] > d[b]) { int t = a; a = b; b = t; }

	int x = d[b] - d[a];
	for (int i = MAXP - 1; i >= 0; i--)
		if (x & (1 << i)) b = p[b][i];

	if (a == b) return a;

	for (int i = MAXP - 1; i >= 0; i--)
	{
		if (p[a][i] != p[b][i])
		{
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int DIS(int a, int b)
{
	int x = LCA(a, b);
	return dist[a] + dist[b] - 2 * dist[x];
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

	for (int i = 1; i <= N; i++) for (int j = 0; j < 20; j++) p[i][j] = -1;
	DFS(1, 0);

	for (int k = 1; k < MAXP; k++)
		for (int i = 1; i <= N; i++)
			if (p[i][k - 1] >= 0) p[i][k] = p[p[i][k - 1]][k - 1];

	scanf("%d", &M);
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", DIS(a, b));
	}

	return 0;
}