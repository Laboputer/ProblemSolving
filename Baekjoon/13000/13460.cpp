#include <stdio.h>
#define MAXN 12

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M;
char map[MAXN][MAXN];
int oy, ox;
int ans = 100;

void F(int n, int by, int bx, int ry, int rx)
{
	if (n == 11 || ans < n) return;

	for (int i = 0; i < 4; i++)
	{
		int nby = by;
		int nbx = bx;
		int nry = ry;
		int nrx = rx;

		while (map[nby + dy[i]][nbx + dx[i]] == '.' || map[nby + dy[i]][nbx + dx[i]] == 'R')
			nby += dy[i], nbx += dx[i];
		while (map[nry + dy[i]][nrx + dx[i]] == '.' || map[nry + dy[i]][nrx + dx[i]] == 'B')
			nry += dy[i], nrx += dx[i];

		if ((nby + dy[i]) == oy && (nbx + dx[i]) == ox)
			continue;
		else if ((nry + dy[i]) == oy && (nrx + dx[i]) == ox)
		{
			if (ans > n) ans = n;
			continue;
		}
		else
		{
			// 같은라인에 있는 구슬 앞뒤 처리
			if (nby == nry && nbx == nrx)
			{
				if ((dx[i] == 1 && rx < bx) || (dy[i] == 1 && ry < by) 
					|| (dx[i] == -1 && rx > bx) || (dy[i] == -1 && ry > by))
					nry -= dy[i], nrx -= dx[i];
				else
					nby -= dy[i], nbx -= dx[i];
			}
			map[by][bx] = '.';
			map[nby][nbx] = 'B';
			map[ry][rx] = '.';
			map[nry][nrx] = 'R';

			F(n + 1, nby, nbx, nry, nrx);

			if (by != nby || bx != nbx)
			{
				map[by][bx] = 'B';
				map[nby][nbx] = '.';
			}
			if (ry != nry || rx != nrx)
			{
				map[ry][rx] = 'R';
				map[nry][nrx] = '.';
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
	int by, bx, ry, rx;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		if (map[i][j] == 'R') ry = i, rx = j;
		else if (map[i][j] == 'B') by = i, bx = j;
		else if (map[i][j] == 'O') oy = i, ox = j;
	}

	F(1, by, bx, ry, rx);
	printf("%d\n", ans == 100 ? -1 : ans);

	return 0;
}