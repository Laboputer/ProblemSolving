#include <stdio.h>
#define MIN(a,b) ((a<b) ? (a) : (b))
#define MAXN 1005

int N, M;
int map[MAXN][MAXN];
int d[MAXN][MAXN];
int main()
{
	while (scanf("%d %d", &N, &M))
	{
		if (N == 0 && M == 0) break;

		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
		for (int i = 0; i < N; i++) d[i][0] = map[i][0];
		for (int i = 0; i < M; i++) d[0][i] = map[0][i];
		for (int i = 1; i < N; i++) for (int j = 1; j < M; j++)
		{
			if (map[i][j] == 0) d[i][j] = 0;
			else d[i][j] = MIN(d[i - 1][j - 1], MIN(d[i - 1][j], d[i][j - 1])) + 1;
		}
		int ans = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (ans < d[i][j]) ans = d[i][j];
		printf("%d\n", ans);
	}
	return 0;
}