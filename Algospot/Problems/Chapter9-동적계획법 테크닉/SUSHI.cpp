#include <stdio.h>
#define MAXN 25

struct obj
{
	int c;
	int v;
};

int N, M;
obj item[MAXN];
int d[300];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		M /= 100;
		for (int i = 0; i < N; i++) scanf("%d %d", &item[i].c, &item[i].v);
		for (int i = 0; i < N; i++) item[i].c /= 100;

		for (int i = 0; i <= 300; i++) d[i] = 0;
		for (int k = 1; k < 300; k++)
		{
			for (int i = 0; i < N; i++)
			{
				if (k - item[i].c < 0) continue;
				if (d[k] < d[k - item[i].c] + item[i].v) d[k] = d[k - item[i].c] + item[i].v;
			}
		}

		for (int k = 300; k <= M; k++)
		{
			for (int i = 0; i < N; i++)
			{
				if (d[k%300] < d[(k - item[i].c) % 300] + item[i].v)
					d[k%300] = d[(k - item[i].c) % 300] + item[i].v;
			}
		}
		printf("%d\n", d[M % 300]);

	}
	return 0;
}