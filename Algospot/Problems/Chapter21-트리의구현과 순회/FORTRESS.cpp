#include <stdio.h>
#define MAX(a,b) (((a)<(b)) ? (b) : (a))
#define MAXN 105


int N;
int X[MAXN], Y[MAXN], R[MAXN];

int C[MAXN][MAXN]; // i안에 j가 있음
int cCnt[MAXN]; // i를 감싸고 있는 원의 개수

bool IsContain(int s1, int s2) // s1안에 s2 포함?
{
	if (R[s2] >= R[s1]) return 0;
	return ((X[s2] - X[s1]) * (X[s2] - X[s1]) + (Y[s2] - Y[s1]) * (Y[s2] - Y[s1])) <= ((R[s1] - R[s2]) * (R[s1] - R[s2])) ? 1 : 0;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d%d%d", &X[i], &Y[i], &R[i]);

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) C[i][j] = 0;
		for (int i = 0; i < N; i++) cCnt[i] = 0;

		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
			{
				if (IsContain(i, j)) C[i][j] = 1, cCnt[j]++;
				if (IsContain(j, i)) C[j][i] = 1, cCnt[i]++;
			}

		int ans = 0;
		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		{
			if (IsContain(i, j)) ans = MAX(ans, cCnt[j] - cCnt[i]);
			else if (IsContain(j, i)) ans = MAX(ans, cCnt[i] - cCnt[j]);
			else
			{
				int cnt = 0;
				for (int k = 1; k < N; k++)
				{
					if (i == k || j == k) continue;
					if (C[k][i] && C[k][j]) cnt++;
				}
				ans = MAX(ans, cCnt[i] + cCnt[j] - 2 * cnt);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}