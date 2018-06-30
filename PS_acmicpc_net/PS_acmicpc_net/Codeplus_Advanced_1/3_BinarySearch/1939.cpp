#include <stdio.h>
#define MAXN 10005

struct node
{
	int e, c;
	int next;
};

node Shared[200005];
int Cnt;

struct List
{
	int head = -1;
	int sz = 0;
	void Push(int e, int c)
	{
		node n = { e, c, head };
		Shared[Cnt] = n;
		head = Cnt++;
		sz++;
	}
};

List map[MAXN];

void mapInit()
{
	Cnt = 0;
	for (int i = 0; i < MAXN; i++) map[i].sz = 0, map[i].head = -1;
}

int N, M;
int X, Y;
int V[MAXN];
int Check;
void DFS(int x, int& C)
{
	if (Check || V[x]) return;
	if (x == Y) Check = 1;
	V[x] = 1;

	int cur = map[x].head;
	for (int i = 0; i < map[x].sz; i++)
	{
		if (Shared[cur].c >= C) DFS(Shared[cur].e, C);
		cur = Shared[cur].next;
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	mapInit();

	for (int i = 0, a, b, c; i < M; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		map[a].Push(b, c);
		map[b].Push(a, c);
	}
	scanf("%d%d", &X, &Y);

	int l = 1, r = 1e9;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		Check = 0;
		for (int i = 1; i <= N; i++) V[i] = 0;
		DFS(X, m);
		if (Check) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r);

	return 0;
}