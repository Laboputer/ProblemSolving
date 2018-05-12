#include <stdio.h>
#define MAXN 20005
#define MAXE 300005

int V, E;
int S;
int dist[MAXN];
int v[MAXN];

struct Node
{
	int to;
	int cost;
	int next;
};

Node Shared[MAXE];
int Cnt;
struct List
{
	int head = -1;
	int sz = 0;

	void push(int x, int c)
	{
		Shared[Cnt] = { x, c,  head };
		head = Cnt++;
		sz++;
	}
};

struct Val
{
	int v;
	int cost;
};

struct PriorQeueue
{
	Val q[MAXE];
	int sz = 0;
    
	void clear()
	{
		sz = 0;
	}

	void swap(int i, int j) { Val t = q[i]; q[i] = q[j]; q[j] = t; }

	Val Top() { return q[1]; }

	void Push(Val x)
	{
		q[++sz] = x;
		int cur = sz;
		int p = sz >> 1;
		while (p && q[p].cost > q[cur].cost) swap(p, cur), cur >>= 1, p >>= 1;
	}
	
	void Pop() 
	{
		q[1] = q[sz--];
		int cur = 1;
		int ch = cur << 1;
		while (1)
		{
			if (ch + 1 <= sz && q[ch].cost > q[ch + 1].cost && q[cur].cost > q[ch + 1].cost) swap(cur, ch + 1), cur = ch + 1, ch = cur << 1;
			else if (ch <= sz && q[cur].cost > q[ch].cost) swap(cur, ch), cur <<= 1, ch <<= 1;
			else break;
		}
	}
};

List G[MAXN];

int main()
{
	scanf("%d%d", &V, &E);
	scanf("%d", &S);
	for (int i = 1; i <= V; i++) dist[i] = 1e9, v[i] = 0;
	dist[S] = 0, v[S] = 1;

	for (int i = 0, a, b, c; i < E; i++) scanf("%d%d%d", &a, &b, &c), G[a].push(b, c);

	int x = S;
	PriorQeueue pq;  pq.clear();

	int cnt = V - 1;
	while (cnt--)
	{
		int cur = G[x].head;
		for (int i = 0; i < G[x].sz; i++)
		{
			if (dist[Shared[cur].to] > dist[x] + Shared[cur].cost)
			{
				dist[Shared[cur].to] = dist[x] + Shared[cur].cost;
				pq.Push({ Shared[cur].to, dist[Shared[cur].to] });
			}
			cur = Shared[cur].next;
		}

		while (pq.sz)
		{
			Val top = pq.Top(); pq.Pop();
			if (v[top.v]) continue;
			v[top.v] = 1;
			x = top.v;
			break;
		}
	}


	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == 1e9) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}