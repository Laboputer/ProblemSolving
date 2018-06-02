#include <stdio.h>
#define MAXN 55

char A[MAXN][MAXN];
char B[MAXN][MAXN];
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)scanf("%s", &A[i]);
	for (int i = 0; i < N; i++) scanf("%s", &B[i]);

	int cnt = 0;
	for (int i = 0; i < N - 2; i++) for (int j = 0; j < M - 2; j++)
	{
		if (A[i][j] != B[i][j])
		{
			cnt++;
			for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++)
			{
				if (A[i + a][j + b] == '0') A[i + a][j + b] = '1';
				else A[i + a][j + b] = '0';
			}
		}
	}
	
	bool flag = true;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (A[i][j] != B[i][j]) flag = false;

	printf("%d", flag ? cnt : -1);

	return 0;
}