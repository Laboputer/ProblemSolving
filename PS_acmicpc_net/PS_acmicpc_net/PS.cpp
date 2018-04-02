#include <stdio.h>
#define MOD 1000000000
#define MAXN 1000005

int N;
int d[MAXN];
int main()
{
	scanf("%d", &N);
	if (N == 0) return 0 & printf("0\n0\n");

	d[0] = 0, d[1] = 1;
	for (int i = 2; i <= 1000000; i++) d[i] = (d[i - 1] + d[i - 2]) % MOD;
	printf("%d\n", ((N < 0) && (N % 2 == 0)) ? -1 : 1);
	printf("%d\n", d[N < 0 ? -N : N]);
	return 0;
}