#include <stdio.h>
#define MAXN 10005

struct node
{
	int to;
	int next;
};

node Shared[200010];
int sCnt;

struct List
{
	int h = -1;
	int s = 0;

	void push(int x)
	{
		Shared[sCnt].to = x;
		Shared[sCnt].next = h;
		h = sCnt++;
		s++;
	}
};

int V, E;
List G[MAXN];
int order[MAXN];
int o;
bool IsCut[MAXN];

int dfs(int x, bool root)
{
	order[x] = ++o;
	int mp = order[x];

	int child = 0;
	int cur = G[x].h;
	while (cur != -1)
	{
		int to = Shared[cur].to;
		if (order[to] == 0)
		{
			child++;
			int ch = dfs(to, 0);
			if (!root && order[x] <= ch) IsCut[x] = 1;
			if (mp > ch) mp = ch;
		}
		else if (mp > order[to]) mp = order[to];
		cur = Shared[cur].next;
	}

	if (root && child >= 2) IsCut[x] = 1;
	return mp;
}


int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0, a, b; i < E; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push(b);
		G[b].push(a);
	}

	for (int i = 1; i <= V; i++)
		if (order[i] == 0) dfs(i, true);

	int cnt = 0;
	for (int i = 1; i <= V; i++) if (IsCut[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= V; i++) if (IsCut[i]) printf("%d ", i);
	return 0;
}