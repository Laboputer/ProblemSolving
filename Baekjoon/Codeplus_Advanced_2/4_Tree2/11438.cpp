#include <stdio.h>
#define MAXN 100005

struct Node
{
	int next;
	int head;
};

Node Shared[MAXN<<1];
int Cnt;

struct List
{
	int head = -1;
	int sz = 0;
	void push(int x)
	{
		Shared[Cnt] = { x, head };
		head = Cnt++; sz++;
	}
};

int N,M;
List tree[MAXN];
int in[MAXN], out[MAXN];
int cnt = 0;
int v[MAXN];
int p[MAXN][20];

void DFS(int parent, int x)
{
	if (v[x]) return;
	v[x] = 1;

	in[x] = cnt++;
	p[x][0] = parent;
	int cur = tree[x].head;
	while (cur != -1)
	{
		DFS(x, Shared[cur].next);
		cur = Shared[cur].head;
	}

	out[x] = cnt++;
}

// Is a the parent of b ? 
bool upper(int a, int b)
{
	if (in[a] <= in[b] && out[b] <= out[a]) return 1;
	return 0;
}

int LCA(int a, int b)
{
	if (upper(a, b)) return a;
	if (upper(b, a)) return b;

	for (int i = 19; i >= 0; i--)
		if (!upper(p[a][i], b))
			a = p[a][i];

	return p[a][0];
}

int main()
{
	scanf("%d", &N);
	for (int i = 1, a, b; i < N; i++) scanf("%d%d", &a, &b), tree[a].push(b), tree[b].push(a);
	
	for (int i = 1; i <= N; i++) v[i] = 0;
	for (int i = 1; i <= N; i++) for (int j = 0; j < 20; j++) p[i][j] = 1;

	DFS(1, 1);
	
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= N; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];

	scanf("%d", &M);
	for (int i = 0, x, y; i < M; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", LCA(x, y));
	}

	return 0;
}