#include <stdio.h>
#define MAXN 55

int N, D, P;
int cnt[MAXN];
int G[MAXN][MAXN];
double d[MAXN][105]; // i,j // j일째에 i마을에 있을 확률

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &N, &D, &P);
		for (int i = 0; i < N; i++) cnt[i] = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		{
			int x; scanf("%d", &x);
			if (x == 0) continue;
			G[i][cnt[i]++] = j;
		}

		for (int i = 0; i < N; i++) for (int j = 1; j <= D; j++) d[i][j] = 0;
		for (int i = 0; i < cnt[P]; i++) d[G[P][i]][1] = 1.0 / (double)(cnt[P]);

		for (int i = 2; i <= D; i++) for (int j = 0; j < N; j++)
			for (int k = 0; k < cnt[j]; k++) d[j][i] += d[G[j][k]][i - 1] * (1.0 / cnt[G[j][k]]);

		int ans = 0; scanf("%d", &ans);
		for (int i = 0, a; i < ans; i++)
		{
			scanf("%d", &a);
			printf("%.8lf ", d[a][D]);
		}
		printf("\n");
	}
	return 0;
}