#include <stdio.h>
#define MAXN 105

int N, S, M;
int a[MAXN];
int v[MAXN][1001];

void DFS(int n, int s)
{
	if (s<0 || s>M || v[n][s]) return;
	v[n][s] = 1;
	
	if (n < N)
	{
		DFS(n + 1, s + a[n + 1]);
		DFS(n + 1, s - a[n + 1]);
	}
}

int main()
{
	scanf("%d%d%d", &N, &S, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	DFS(0, S);
	int ans = -1;
	for (int i = 1000; i >= 0; i--) if (v[N][i]) { ans = i; break; }
 	printf("%d\n", ans);
	
	return 0;
}