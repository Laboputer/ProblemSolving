#include <stdio.h>

int N;
void F(int N, int from, int use, int to)
{
	if (N == 0) return;
	F(N - 1, from, to, use);
	printf("%d %d\n", from, to);
	F(N - 1, use, from, to);
}
int main()
{
	scanf("%d", &N);
	printf("%d\n", (1 << N) - 1);
	F(N, 1, 2, 3);
	return 0;
}