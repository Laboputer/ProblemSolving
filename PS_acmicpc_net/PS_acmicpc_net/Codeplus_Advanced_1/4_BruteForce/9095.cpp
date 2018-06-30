#include <stdio.h>
#define MAXN 15

int N;
int d[MAXN];

int main()
{
	int t; scanf("%d", &t);
	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i < MAXN; i++) d[i] = d[i - 3] + d[i - 2] + d[i - 1];

	while (t--)
	{
		scanf("%d", &N);
		printf("%d\n", d[N]);
	}
	return 0;
}