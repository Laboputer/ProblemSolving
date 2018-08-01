#include <stdio.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MAXN 55

int N;
int a[MAXN];
int d[MAXN][MAXN]; // k턴에서 i, j 숫자가 있을때 최대 차이값

int F(int i, int j)
{
	if (i > j) return 0;

	int& ref = d[i][j];
	if (ref != -2e9) return ref;

	ref = -1e9;
	if (i != j)
	{
		ref = MAX(ref, -F(i + 2, j));
		ref = MAX(ref, -F(i, j - 2));
	}
	ref = MAX(ref, a[i] - F(i + 1, j));
	ref = MAX(ref, a[j] - F(i, j - 1));
	return ref;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) d[i][j] = -2e9;
		printf("%d\n", F(0, N - 1));
	}
	return 0;
}
