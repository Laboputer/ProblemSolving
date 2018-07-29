#include <stdio.h>
#define MAXN 105

int N, W;
char obj[MAXN][25];
int w[MAXN], v[MAXN];
int d[MAXN][1005]; // i번째 물건까지 j안에서 최대 만족도
int p[MAXN][1005];

int cnt = 0;
int ans[MAXN];

void back(int n, int ww)
{
	if (n < 0 || ww <= 0) return;

	if (w[n] <= ww && d[n][ww] == d[n - 1][ww - w[n]] + v[n])
	{
		ans[cnt++] = n;
		back(n - 1, ww - w[n]);
	}
	else back(n - 1, ww);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &N, &W);
		for (int i = 0; i < N; i++) 
			scanf("%s %d %d", obj[i], &w[i], &v[i]);

		cnt = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j <= W; j++) d[i][j] = 0, p[i][j] = -1;
		for (int j = w[0]; j <= W; j++) d[0][j] = v[0], p[0][j] = 0;
		
		for (int i = 1; i < N; i++) for (int j = 0; j <= W; j++)
		{
			d[i][j] = d[i - 1][j];
			p[i][j] = p[i - 1][j];
			if (j >= w[i] && (d[i][j] < d[i - 1][j - w[i]] + v[i]))
				d[i][j] = d[i - 1][j - w[i]] + v[i], p[i][j] = i;
		}

		back(N - 1, W); // dp 최적값 경로 추적
		printf("%d %d\n", d[N - 1][W], cnt);
		for (int i = 0; i < cnt; i++) printf("%s\n", obj[ans[i]]);
	}
	return 0;
}