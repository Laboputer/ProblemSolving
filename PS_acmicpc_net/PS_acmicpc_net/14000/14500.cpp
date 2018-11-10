#include <stdio.h>
#define MAXN 505

inline int MAX(int a, int b)
{
	if (a < b) return b;
	else return a;
}

int N, M;
int m[4][MAXN][MAXN];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < 4; i++) for (int j = 0; j < MAXN; j++) for (int k = 0; k < MAXN; k++) m[i][j][k] = -1e8; // 넘어가는 곳
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &m[0][i][j]);
	
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) m[1][N - 1 - i][M - 1 - j] = m[0][i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) m[2][j][N - 1 - i] = m[0][i][j];
	for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) m[3][M - 1 - i][N - 1 - j] = m[2][i][j];
	// m[0]은 [1]의 180도 회전 N,M
	// m[2]는 [3]의 180도 회전 M,N

	int X = MAX(N, M);
	int ans = 0;
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < X; i++) for (int j = 0; j < X; j++)
		{
			ans = MAX(ans, m[k][i][j] + m[k][i][j + 1] + m[k][i][j + 2] + m[k][i][j + 3]);

			ans = MAX(ans, m[k][i][j] + m[k][i + 1][j] + m[k][i][j + 1] + m[k][i + 1][j + 1]);

			ans = MAX(ans, m[k][i][j] + m[k][i + 1][j] + m[k][i + 2][j] + m[k][i + 2][j + 1]);
			ans = MAX(ans, m[k][i][j + 1] + m[k][i + 1][j + 1] + m[k][i + 2][j] + m[k][i + 2][j + 1]);

			ans = MAX(ans, m[k][i][j] + m[k][i + 1][j] + m[k][i + 1][j + 1] + m[k][i + 2][j + 1]);
			ans = MAX(ans, m[k][i][j + 1] + m[k][i + 1][j] + m[k][i + 1][j + 1] + m[k][i + 2][j]);

			ans = MAX(ans, m[k][i][j] + m[k][i][j + 1] + m[k][i][j + 2] + m[k][i + 1][j + 1]);
		}
	}

	printf("%d\n", ans);
	return 0;
}