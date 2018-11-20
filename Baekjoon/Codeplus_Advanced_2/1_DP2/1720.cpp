#include <stdio.h>
#define MAXN 33

int N;
long long F[MAXN];
long long d[MAXN];
int main()
{
	scanf("%d", &N);
	F[1] = 1; F[2] = 3;
	for (int i = 3; i <= 30; i++) F[i] = F[i - 2] * 2 + F[i - 1];
	d[1] = 1; d[2] = 3;
	for (int i = 3; i <= 30; i++)
	{
		if (i & 1) d[i] = (F[i] + F[N / 2]) / 2;
		else d[i] = (F[i] + (F[N / 2] + 2*F[N / 2 - 1])) / 2;
	}
	printf("%d\n", d[N]);
	return 0;
}