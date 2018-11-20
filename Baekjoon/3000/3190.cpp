#include <stdio.h>
#define MAXN 102

int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, K, L;
int m[MAXN][MAXN];
bool app[MAXN][MAXN];
char dir[10001];
int cy, cx, cdir;
int ty, tx;
int changeD(int d, char cmd)
{
	if (cmd == 'L')
	{
		d--;
		if (d == -1) d = 3;
	}
	else
	{
		d++;
		if (d == 4) d = 0;
	}
	return d;
}

int main()
{
	scanf("%d", &N);
	cy = 1, cx = 1, cdir = 0;
	ty = 1, tx = 1;

	scanf("%d", &K);
	for (int i = 0, a, b; i < K; i++)
	{
		scanf("%d%d", &a, &b);
		app[a][b] = 1;
	}

	for (int i = 0; i < 10001; i++) dir[i] = 0;
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int x; char y; scanf(" %d %c", &x, &y);
		dir[x] = y;
	}

	for (int i = 0; i <= N + 1; i++) m[i][0] = m[i][N + 1] = m[0][i] = m[N + 1][i] = 1e8;
	m[1][1] = 1;
	int ans = 0;
	while (1)
	{
		ans++;
		int ny = cy + dy[cdir];
		int nx = cx + dx[cdir];

		if (m[ny][nx] > 0) break;

		m[ny][nx] = m[cy][cx] + 1;
		if (app[ny][nx])
			app[ny][nx] = 0;
		else
		{
			for (int i = 0; i < 4; i++) // ²¿¸®ÀÚ¸£±â
			{
				int nty = ty + dy[i];
				int ntx = tx + dx[i];
				if (m[ty][tx] + 1 == m[nty][ntx])
				{
					m[ty][tx] = 0;
					ty = nty, tx = ntx;
					break;
				}
			}
		}
		if (dir[ans] != 0) cdir = changeD(cdir, dir[ans]);
		cy = ny;
		cx = nx;
	}

	printf("%d\n", ans);
	return 0;
}