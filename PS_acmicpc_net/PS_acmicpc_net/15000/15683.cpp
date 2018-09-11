#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int Type[6] = { 0, 4, 2, 4, 4, 1 }; // 각 카메라의 회전 개수
int cntType[6] = { 0, 1, 2, 2, 3, 4 }; // 각 카메라의 방향 개수
int dir[6][4] = {
	{-1,-1,-1,-1},
	{1,-1,-1,-1},
	{1,3,-1,-1},
	{0,1,-1,-1},
	{0,1,3,-1},
	{0,1,2,3}
}; // 카메라 위치

int cy[8], cx[8];
int camType[8];
int camCnt;
int state[8];
int ans;

int N, M;
int map[8][8];
int reMap[8][8];
void make(int n)
{
	if (n == camCnt)
	{
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) reMap[i][j] = map[i][j];
		for (int i = 0; i < camCnt; i++)
		{
			for (int k = 0; k < cntType[camType[i]]; k++)
			{
				int ny = dy[(dir[camType[i]][k] + state[i]) % 4];
				int nx = dx[(dir[camType[i]][k] + state[i]) % 4];
				int y = cy[i] + ny;
				int x = cx[i] + nx;
				while (0 <= y && y < N && 0 <= x && x < M)
				{
					if (reMap[y][x] == 6) break;
					if (reMap[y][x] == 0) reMap[y][x] = '#';
					y += ny;
					x += nx;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (reMap[i][j] == 0) res++;
		if (ans > res) ans = res;
		return;
	}

	int rotateCnt = Type[camType[n]];
	for (int i = 0; i < rotateCnt; i++)
	{
		state[n] = i;
		make(n + 1);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

	camCnt = 0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) 
		if (1 <= map[i][j] && map[i][j] <= 5)
		{
			cy[camCnt] = i;
			cx[camCnt] = j;
			camType[camCnt] = map[i][j];
			camCnt++;
		}

	ans = 2e9;
	make(0);
	printf("%d\n", ans);
	return 0;
}