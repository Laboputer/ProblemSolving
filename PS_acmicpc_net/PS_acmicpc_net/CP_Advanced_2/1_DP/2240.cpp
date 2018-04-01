#include <stdio.h>
#define MAX(a,b) ((a<b) ? (b) : (a))
#define MAXN 1005

int T, W;
int p[MAXN];
int d[3][31][MAXN];

int F(int c, int w, int t)
{
	if (t == T+1) return 0;
	int& ref = d[c][w][t];
	if (ref != -1) return ref;

	ref = F(c, w, t + 1) + ((p[t] == c) ? 1 : 0);
	if (w) ref = MAX(ref, F((~c) & 3, w - 1, t + 1) + ((p[t] == c) ? 1 : 0));
	return ref;
}

int main()
{
	scanf("%d%d", &T, &W);
	for (int i = 1; i <= T; i++) scanf("%d", &p[i]);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 31; j++) for (int k = 0; k <= T; k++) d[i][j][k] = -1;

	printf("%d\n", F(1, W, 0));

	return 0;
}