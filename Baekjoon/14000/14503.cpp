#include <stdio.h>
#define MAXN 55

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int N, M;
int R, C, D;
int m[MAXN][MAXN];
int V[MAXN][MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &R, &C, &D);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &m[i][j]);
	int ans = 1;
	V[R][C] = 1;
	
	bool go = 1;
	while (go)
	{
		bool done = 1; // 4방향 검사
		for (int i = 0; i < 4; i++)
			if (m[R + dy[i]][C + dx[i]] == 0 && V[R + dy[i]][C + dx[i]] == 0)
				done = 0;

		int BR = R + dy[(D + 2) % 4];
		int BC = C + dx[(D + 2) % 4];
		if (done && m[BR][BC] == 1) // 종료조건
			break;

		if (done) // 3번
		{
			R = BR;
			C = BC;
			continue;
		}

		int LR = R + dy[(D + 3) % 4];
		int LC = C + dx[(D + 3) % 4];

		if (m[LR][LC] == 0 && V[LR][LC] == 0) // 1번
		{
			D = (D + 3) % 4;
			V[LR][LC] = 1; ans++;
			R = LR; C = LC;
		}
		else // 2번
			D = (D + 3) % 4;
	}

	printf("%d\n", ans);
	return 0;
}