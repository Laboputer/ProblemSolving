#include <stdio.h>
#define MAXN 2005

int N, M;
int arr[MAXN];
bool F[MAXN][MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++) for (int j = i; j <= N; j++) F[i][j] = 0;
	for (int i = 1; i <= N; i++) F[i][i] = 1;
	for (int i = 2; i <= N; i++) F[i - 1][i] = (arr[i - 1] == arr[i]) ? 1 : 0;
	
	for (int i = 2; i < N; i++)
		for (int j = 1; j + i <= N; j++)
			F[j][j + i] = (F[j + 1][j + i - 1] && (arr[j] == arr[j + i])) ? 1 : 0;
	
	scanf("%d", &M);
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", F[a][b]);
	}
	return 0;
}