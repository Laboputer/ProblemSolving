#include <stdio.h>
#define MAX(a,b) ((a<b) ? (b) : (a))
#define MAXN 55

int N;
int a[MAXN];
int d[MAXN][500005];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= 50; i++) for (int j = 0; j < 500005; j++) d[i][j] = -1;
	
	d[0][250000] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 500005; j++)
		{
			if (d[i - 1][j] == -1) continue;
			if (j + a[i] <= 500000) d[i][j + a[i]] = MAX(d[i][j + a[i]], d[i - 1][j] + a[i]);
			if (j - a[i] >= 0) d[i][j - a[i]] = MAX(d[i][j - a[i]], d[i - 1][j] + a[i]);
			d[i][j] = MAX(d[i][j], d[i - 1][j]);
		}
	}

	printf("%d\n", (d[N][250000] <= 0) ? -1 : d[N][250000] / 2);

	return 0;
}