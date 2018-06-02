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

struct Queue
{
	int set[MAXQ+1];
	int size = 0;
	int head = 0;
	int rear = -1;

	void push(int x)
	{
		rear = (rear + 1) % MAXQ;
		set[rear] = x;
		size++;
	}
	void Pop()
	{
		head = (head + 1) % MAXQ;
		size--;
	}
	int Top()
	{
		return set[head];
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
	Queue q;
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