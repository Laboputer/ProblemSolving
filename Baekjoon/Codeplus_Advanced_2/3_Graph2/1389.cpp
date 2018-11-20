#include <stdio.h>
#define MAXN 105

int N, M;
int d[MAXN][MAXN];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) d[i][j] = 1e9;
	for (int i = 1; i <= N; i++) d[i][i] = 0;
	for (int i = 0, a, b; i < M; i++) scanf("%d%d", &a, &b), d[a][b] = d[b][a] = 1;

	for (int x = 1; x <= N; x++)
		for (int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
				if (d[a][b] > d[a][x] + d[x][b]) d[a][b] = d[a][x] + d[x][b];

	int ans = 0;
	int Cnt = 1e9;

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++) cnt += d[i][j];
		if (Cnt > cnt) Cnt = cnt, ans = i;
	}
	printf("%d\n", ans);

	return 0;
}