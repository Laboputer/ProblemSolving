#include <stdio.h>

int N, K;
int a[105];
int d[10005];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	
	for (int i = 0; i <= K; i += a[0]) d[i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = a[i]; j <= K; j++) d[j] += d[j - a[i]];

	printf("%d\n", d[K]);
	return 0;
}
