#include <stdio.h>
#define MAXN 2505
#define MIN(a,b) ((a<b) ? (a) : (b))

int N;
char str[MAXN];
int F[MAXN][MAXN];
int d[MAXN];

int main()
{
	scanf("%s", str+1);
	N = 0; for (int i = 1; str[i]; i++) N++;

	for (int i = 1; i <= N; i++) for (int j = i; j <= N; j++) F[i][j] = 0;
	for (int i = 1; i <= N; i++) F[i][i] = 1;
	for (int i = 2; i <= N; i++) F[i - 1][i] = (str[i - 1] == str[i]) ? 1 : 0;

	for (int i = 2; i < N; i++) for (int j = 1; j + i <= N; j++)
			F[j][j + i] = (F[j + 1][j + i - 1] && (str[j] == str[j + i])) ? 1 : 0;

	d[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (F[1][i])
		{
			d[i] = 1; 
			continue;
		}
		d[i] = d[i - 1] + 1;
		for (int j = 1; i - j - 1 >= 1; j++) 
			if (F[i - j][i]) d[i] = MIN(d[i], d[i - j - 1] + 1);
	}
	printf("%d\n", d[N]);
	
	return 0;
}