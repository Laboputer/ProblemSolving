#include <stdio.h>
#define MAXN 2200

char a[MAXN][MAXN];
int N;
void F(int N, int y, int x)
{
	if (N == 0 || N == 1) return;
	int cnt = N / 3;
	
	for (int i = 0; i < cnt; i++) for (int j = 0; j < cnt; j++) a[y + cnt + i][x + cnt + j] = ' ';
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
		F(cnt, y + i*cnt, x + j*cnt);
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) a[i][j] = '*';
	for (int i = 0; i < N; i++) a[i][N] = 0;

	F(N, 0, 0);

	for (int i = 0; i < N; i++) printf("%s\n", a[i]);

	return 0;
}