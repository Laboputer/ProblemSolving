#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 32005
#define MAXQ 100005

struct node
{
	int to;
	int next;
};

node Shared[MAXQ];
int Cnt = 0;
struct List
{
	int head = -1;
	int sz = 0;
	void push(int x)
	{
		Shared[Cnt] = { x , head };
		sz++;
		head = Cnt++;
	}
};

struct PriorQueue
{
	int set[MAXQ + 1];
	int size = 0;

	void Swap(int i, int j) { int t = set[i]; set[i] = set[j]; set[j] = t; }

	void push(int x)
	{
		set[++size] = x;
		int cur = size;
		int p = cur >> 1;
		while (p && set[cur] < set[p]) Swap(cur, p), cur >>= 1, p >>= 1;
	}

	void Pop()
	{
		set[1] = set[size--];
		int cur = 1;
		int lc = cur * 2;
		while (lc <= size)
		{
			if ((lc + 1 <= size) && (set[lc] > set[lc + 1]) && (set[cur] > set[lc + 1])) Swap(lc + 1, cur), cur = lc + 1, lc = cur << 1;
			else if (set[lc] < set[cur]) Swap(lc, cur), cur = lc, lc = cur << 1;
			else break;
		}
	}

	int Top()
	{
		return set[1];
	}
};


int N,M;
List G[MAXN];
int s[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push(b);
		s[b]++;
	}

	PriorQueue q;
	for (int i = 1; i <= N; i++) if (s[i] == 0) q.push(i);

	while (q.size)
	{
		int top = q.Top(); q.Pop();
		printf("%d ", top);
		int cur = G[top].head;
		for (int i = 0; i < G[top].sz; i++)
		{
			--s[Shared[cur].to];
			if (s[Shared[cur].to] == 0) q.push(Shared[cur].to);
			cur = Shared[cur].next;
		}
	}
	return 0;
}