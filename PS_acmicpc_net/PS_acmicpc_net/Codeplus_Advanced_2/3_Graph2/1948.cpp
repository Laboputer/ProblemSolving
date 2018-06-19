#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10005

struct Node
{
	int to;
	int r;
};

int N, M;
int S, E;
vector<Node> G[MAXN];
vector<Node> preG[MAXN];
int ind[MAXN];
int dist[MAXN];
int V[MAXN];

int ans = 0;
void DFS(int x)
{
	if (V[x] == 1) return;
	
	V[x] = 1;
	for (int i = 0; i < preG[x].size(); i++)
	{
		if (dist[x] == dist[preG[x][i].to] + preG[x][i].r)
		{
			DFS(preG[x][i].to);
			ans++;
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({ b,c });
		ind[b]++;
		preG[b].push_back({ a,c });
	}
	scanf("%d%d", &S, &E);

	queue<int> q;
	q.push(S);
	while (q.size())
	{
		int top = q.front(); q.pop();
		for (int i = 0; i < G[top].size(); i++)
		{
			if (dist[G[top][i].to] < dist[top] + G[top][i].r)
				dist[G[top][i].to] = dist[top] + G[top][i].r;
			ind[G[top][i].to]--;
			if (ind[G[top][i].to] == 0) q.push(G[top][i].to);
		}
	}
	printf("%d\n", dist[E]);
	DFS(E);
	printf("%d\n", ans);

	return 0;
}