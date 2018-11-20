#include <stdio.h>

struct node
{
	int to;
	int next;
};

node S[2000010];
int sc;

struct List
{
	int h = -1;
	void push(int x)
	{
		S[sc] = { x, h };
		h = sc++;
	}
};

struct edge
{
	int x;
	int y;

	bool operator < (const edge& rhs) const
	{
		if (x != rhs.x) return x < rhs.x;
		else return y < rhs.y;
	}
};

int V, E;
List G[100005];
int order[100005];
int ocnt;

edge ans[100005];
edge tmp[100005];
int acnt;

void SWAP(int i, int j)
{
	if (i == j) return;
	edge t = ans[i];
	ans[i] = ans[j];
	ans[j] = t;
}
void SORT(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	SORT(l, m);
	SORT(m + 1, r);

	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (ans[p1] < ans[p2]) ? ans[p1++] : ans[p2++];
	while (p1 <= m) tmp[p3++] = ans[p1++];
	while (p2 <= r) tmp[p3++] = ans[p2++];
	for (int i = l; i <= r; i++) ans[i] = tmp[i];
}

int DFS(int p, int x)
{
	order[x] = ++ocnt;
	int sub = order[x];

	int cur = G[x].h;
	while (cur != -1)
	{
		int to = S[cur].to;
		if (to != p)
		{
			if (order[to] != 1e9)
			{
				if (sub > order[to])
					sub = order[to];
			}
			else
			{
				int low = DFS(x, to);
				if (order[x] < low)
				{
					if (x < to) ans[acnt] = { x, to };
					else ans[acnt] = { to, x };
					acnt++;
				}
				if (sub > low) sub = low;
			}
		}
		cur = S[cur].next;
	}

	return sub;
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
	for (int i = 0; i <= V; i++) order[i] = 1e9;

	DFS(1, 1);
	SORT(0, acnt - 1);
	printf("%d\n", acnt);
	for (int i = 0; i < acnt; i++) printf("%d %d\n", ans[i].x, ans[i].y);

	return 0;
}