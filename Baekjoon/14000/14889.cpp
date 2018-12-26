#include <stdio.h>
#define MAXN 20

inline int abs(int a, int b)
{
	if (a < b) return b - a;
	else return a - b;
}

int N;
int m[MAXN][MAXN];
int set[MAXN];
int ans = 1e9;
void F(int n, int r)
{
	if (n == N && r > 0) return;
	if (r == 0)
	{
		int m1 = 0;
		int m2 = 0;

		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		{
			if (set[i] == 0 && set[j] == 0)
				m1 += m[i][j] + m[j][i];
			if (set[i] == 1 && set[j] == 1)
				m2 += m[i][j] + m[j][i];
		}
		
		int dis = abs(m1, m2);
		if (ans > dis) ans = dis;
		return;
	}

	for (int i = n; i < N; i++)
	{
		set[i] = 1;
		F(i + 1, r - 1);
		set[i] = 0;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &m[i][j]);
	F(0, N/2);

	printf("%d", ans);

	return 0;
}