#include <stdio.h>
#define MIN(a,b) ((a<b) ? (a) : (b))
int N, M, K;
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	printf("%d", MIN((N + M - K) / 3, MIN(N / 2, M)));

	return 0;
}