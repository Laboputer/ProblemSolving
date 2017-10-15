#include <stdio.h>
#define MAXN 70

int N;
char a[MAXN][MAXN];

void F(int N, int y, int x)
{
	if (N == 0) return;

	char ch = a[y][x];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (ch == a[y + i][x + j]) continue;
		
		printf("(");
		for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++) 
			F(N / 2, y + a*N / 2, x + b*N / 2);
		printf(")");
		return;
	}

	printf("%c", ch);
}

int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%s", &a[i]);
	F(N, 0, 0);

	return 0;
}