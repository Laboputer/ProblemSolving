#include <stdio.h>
#define MAXN 1500100

inline int MAX(int a, int b)
{
	if (a < b) return b;
	return a;
}

int N;
int T[MAXN], P[MAXN];
int d[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &T[i], &P[i]);

	for (int i = 1; i <= N; i++)
	{
		d[i] = MAX(d[i], d[i - 1]);
		d[i + T[i] - 1] = MAX(d[i + T[i] - 1], d[i - 1] + P[i]);
	}
	printf("%d\n", d[N]);

	return 0;
}