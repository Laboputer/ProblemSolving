#include <stdio.h>
#define MAXN 110

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, M;
char map[MAXN][MAXN];
struct edge
{
	int cur, to;
	int r;
};
edge E[MAXN*MAXN * 4];
int d[MAXN*MAXN * 4];
int ecnt = 0;
int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 0; i < MAXN*MAXN* 4; i++) d[i] = 1e9;
	d[M+1] = 0;
	for (int y = 1; y <= N; y++) scanf("%s", map[y] + 1);

	for (int y = 1; y <= N; y++) for (int x = 1; x <= M; x++)
	{
		int c = y*M + x;
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (nx <= 0 || ny <= 0 || M < nx || N < ny) continue;
			int to = ny*M + nx;
			E[ecnt++] = { c, to, map[y][x] - '0' };
		}
	}

	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < ecnt; i++)
			if (d[E[i].to] > d[E[i].cur] + E[i].r)
				d[E[i].to] = d[E[i].cur] + E[i].r, flag = true;
	}

	printf("%d\n", d[N*M + M]);
	
	return 0;
}