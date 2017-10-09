#include <stdio.h>
#define MAXN 1000005
#define MIN(a,b) ((a<b) ? (a) : (b))
int d[MAXN];
int N;

int F(int x)
{
	if (x == 1) return 0;

	int& ref = d[x];
	if (ref != -1) return ref;

	ref = F(x - 1) + 1;
	if (x % 3 == 0) ref = MIN(ref, F(x / 3) + 1);
	if (x % 2 == 0) ref = MIN(ref, F(x / 2) + 1);
	return ref;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < MAXN; i++) d[i] = -1;
	printf("%d\n", F(N));

	return 0;
}