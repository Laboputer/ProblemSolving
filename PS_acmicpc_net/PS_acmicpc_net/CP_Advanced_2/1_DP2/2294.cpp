#include <stdio.h>

int N, K;
int a[105];
int d[10005];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	for (int i = 0; i <= K; i++) d[i] = -1;
	d[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - a[i] < 0 || d[j-a[i]] == -1) continue;
			if (d[j] == -1 || d[j] > d[j - a[i]] + 1) d[j] = d[j - a[i]] + 1;
		}
	}

	printf("%d\n", d[K]);

	return 0;
}
