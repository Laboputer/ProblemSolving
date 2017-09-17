#include <stdio.h>
#define MIN(a,b) ((a<b) ? (a) : (b))
int N, M, K;
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	while (K--)
	{
		if (N > M * 2) N--;
		else M--;
	}
	N /= 2;

	printf("%d", MIN(N, M));

	return 0;
}