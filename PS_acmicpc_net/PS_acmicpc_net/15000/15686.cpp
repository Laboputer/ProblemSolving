#include <stdio.h>

int N, M;
int map[50][50];

int hy[100], hx[100];
int hCnt;
int chy[15], chx[15];
int cCnt;

int v[15];
int select[15];
int ans;

void make(int n, int p)
{
	if (n == M)
	{
		int res = 0;
		for (int i = 0; i < hCnt; i++)
		{
			int chi = 10000;
			for (int j = 0; j < M; j++)
			{
				int dy = hy[i] - chy[select[j]];
				int dx = hx[i] - chx[select[j]];
				if (dy < 0) dy = -dy;
				if (dx < 0) dx = -dx;
				if (chi > dy + dx) chi = dy + dx;
			}
			res += chi;
		}
		if (ans > res) ans = res;
		return;
	}

	for (int i = p + 1; i <= cCnt - (M-n); i++)
	{
		select[n] = i;
		make(n + 1, i);
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (map[i][j] == 0) continue;
		else if (map[i][j] == 1) {
			hy[hCnt] = i;
			hx[hCnt] = j;
			hCnt++;
		}
		else if (map[i][j] == 2)
		{
			chy[cCnt] = i;
			chx[cCnt] = j;
			cCnt++;
		}
	}

	ans = 2e9;
	make(0, -1);
	printf("%d\n", ans);
	return 0;
}