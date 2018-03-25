#include <stdio.h>
#define MAXN 205
#define MIN(a,b) ((a<b) ? (a) : (b))

int A, B, C;
int v[MAXN][MAXN][MAXN];
int V[MAXN];
void DFS(int a, int b, int c)
{
	if (v[a][b][c]) return;
	v[a][b][c] = 1;
	if (a == 0) V[c] = 1;
	int X;
	if (a != 0)
	{
		X = MIN(B - b, a); DFS(a - X, b + X, c);
		X = MIN(C - c, a); DFS(a - X, b, c + X);
	}
	if (b != 0)
	{
		X = MIN(A - a, b); DFS(a + X, b - X, c);
		X = MIN(C - c, b); DFS(a, b - X, c + X);
	}
	if (c != 0)
	{
		X = MIN(A - a, c); DFS(a + X, b, c - X);
		X = MIN(B - b, c); DFS(a, b + X, c - X);
	}
}

int main()
{
	scanf("%d%d%d", &A, &B, &C);
	DFS(0, 0, C);

	for (int i = 0; i <= C; i++) if (V[i]) printf("%d ", i);
	return 0;
}