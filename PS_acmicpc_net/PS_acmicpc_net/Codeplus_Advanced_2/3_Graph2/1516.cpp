#include <stdio.h>
#define MAXN 505

struct Queue
{
	int set[MAXN+1];
	int sz = 0;
	int rear = 0;
	int front = 0;
	
	void push(int x) { 
		sz++;
		set[rear] = x; 
		rear = (rear + 1) % MAXN;
	}
	void pop() { sz--; front = (front + 1) % MAXN; }
	int Top() { return set[front]; }
};

int N;
int G[MAXN][MAXN];
int inCnt[MAXN];
int cost[MAXN];
int dist[MAXN];
int main()
{
	for (int i = 0; i < MAXN; i++) inCnt[i] = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &cost[i]);
		int x;
		while (scanf("%d", &x))
		{
			if (x == -1) break;
			G[x][++G[x][0]] = i;
			inCnt[i]++;
		}
	}
	for (int i = 0; i < MAXN; i++) dist[i] = cost[i];

	Queue q;
	for (int i = 1; i <= N; i++) if (inCnt[i] == 0) q.push(i);
	
	while (q.sz)
	{
		int top = q.Top(); q.pop();
		for (int i = 1; i <= G[top][0]; i++)
		{
			if (inCnt[G[top][i]] == 0) continue;
			inCnt[G[top][i]]--;
			if (dist[G[top][i]] < dist[top] + cost[G[top][i]]) dist[G[top][i]] = dist[top] + cost[G[top][i]];
			if (inCnt[G[top][i]] == 0) q.push(G[top][i]);
		}
	}

	for (int i = 1; i <= N; i++) printf("%d\n", dist[i]);
	
	return 0;
}