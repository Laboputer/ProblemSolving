#include <stdio.h>
#define MAXN 2200

int N;
int a[MAXN][MAXN];

int ans[3];
void F(int N, int sy, int sx)
{
	if (N == 1)
	{
		ans[a[sy][sx] + 1]++;
		return;
	}

	int off = N / 3;
	int val = a[sy][sx];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (val == a[i + sy][j + sx]) continue;

		for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++)
			F(N / 3, sy + off*a, sx + off*b);
		return;

	}
	ans[val + 1]++;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &a[i][j]);
	F(N, 0, 0);
	for (int i = 0; i < 3; i++) printf("%d\n", ans[i]);

	return 0;
}
