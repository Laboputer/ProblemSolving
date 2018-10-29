#include <stdio.h>
#include <math.h>
#define MAXN 10005

struct node
{
	int to;
	double value;
	int next;
};

node Shared[40005];
int scnt;

struct List
{
	int h = -1;
	int sz = 0;
	
	void init()
	{
		h = -1;
		sz = 0;
	}

	void push(int to, double val)
	{
		Shared[scnt] = { to, val, h };
		h = scnt;
		scnt++;
		sz++;
	}
};

struct state
{
	double val;
	int x;
};

struct pq
{
	state q[100005];
	int sz = 0;
	
	void init()
	{
		sz = 0;
	}

	void swap(int i, int j)
	{
		if (i == j) return;
		state t = q[i];
		q[i] = q[j];
		q[j] = t;
	}
	void push(state x)
	{
		++sz;
		q[sz] = x;
		int cur = sz, p = sz / 2;
		while (cur != 1 && q[p].val > q[cur].val)
		{
			swap(p, cur);
			p /= 2;
			cur /= 2;
		}
	}

	void pop()
	{
		swap(1, sz);
		sz--;

		int cur = 1;
		int ch = 2;

		while (ch <= sz)
		{
			if (ch + 1 <= sz && q[cur].val > q[ch + 1].val && q[ch].val > q[ch + 1].val)
				swap(cur, ch + 1), cur = ch + 1;
			else if (q[cur].val > q[ch].val)
				swap(cur, ch), cur = ch;
			else break;
			ch = cur * 2;
		}
	}

	state top()
	{
		return q[1];
	}
};

int N, M;
bool V[MAXN];
double dist[MAXN];
List G[MAXN];
pq q;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);

		for (int i = 0; i < N; i++) G[i].init(), V[i] = 0;
		scnt = 0;
		q.init();

		for (int i = 0, a, b; i < M; i++)
		{
			double x;
			scanf("%d%d%lf", &a, &b, &x);
			x = log10(x);
			G[a].push(b, x);
			G[b].push(a, x);
		}

		q.push({ 0, 0 });
		while (q.sz)
		{
			state top = q.top(); q.pop();
			if (V[top.x]) continue;

			int here = top.x;
			double dis = top.val;
			V[here] = 1;
			dist[here] = dis;

			int cur = G[here].h;
			while (cur != -1)
			{
				int to = Shared[cur].to;
				if (V[to] == 0)
					q.push({ Shared[cur].value + dis , to });
				cur = Shared[cur].next;
			}
		}

		if (N == 1) printf("%.10lf\n", 0.0);
		else printf("%.10lf\n", pow(10, dist[N - 1]));
	}
	return 0;
}