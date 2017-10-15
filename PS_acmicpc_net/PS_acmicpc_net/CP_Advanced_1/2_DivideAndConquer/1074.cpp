#include <stdio.h>

int N, r, c;
void F(int N, int idx, int y, int x)
{
	if (N == 1 && y == r && x == c)
	{
		printf("%d", idx);
		return;
	}

	if (y <= r && r < y + N && x <= c && c < x + N)
	{
		int val = (N*N) / 4;
		F(N / 2, idx, y, x);
		F(N / 2, idx + val, y, x + N / 2);
		F(N / 2, idx + 2 * val, y + N / 2, x);
		F(N / 2, idx + 3 * val, y + N / 2, x + N / 2);
	}
}

int main()
{
	scanf("%d%d%d", &N, &r, &c);
	F(1<<N, 0, 0, 0);
	return 0;
}