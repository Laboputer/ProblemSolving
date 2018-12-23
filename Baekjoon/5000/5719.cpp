#include <stdio.h>
#define MAXN 505
#define MAXE 10005

struct p
{
	int x, y, r;
};

int N, M, S, D;
p V[MAXE];
bool used[MAXE];
int startS[MAXN];
int startD[MAXN];
int d[MAXN];

int main()
{
	while (scanf("%d%d", &N, &M))
	{
		if (N == 0 && M == 0) break;
		scanf("%d%d", &S, &D);
		for (int i = 0; i < M; i++)
			scanf("%d%d%d", &V[i].x, &V[i].y, &V[i].r);

		for (int i = 0; i < N; i++) startS[i] = startD[i] = d[i] = 1e9;

		bool flag = 1;
		startS[S] = 0;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < M; i++)
			{
				if (startS[V[i].y] > startS[V[i].x] + V[i].r)
				{
					startS[V[i].y] = startS[V[i].x] + V[i].r;
					flag = 1;
				}
			}
		}

		flag = 1;
		startD[D] = 0;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < M; i++)
			{
				if (startD[V[i].x] > startD[V[i].y] + V[i].r)
				{
					startD[V[i].x] = startD[V[i].y] + V[i].r;
					flag = 1;
				}
			}
		}

		for (int i = 0; i < M; i++) used[i] = 0;
		for (int i = 0; i < M; i++)
		{
			if (startS[D] == startS[V[i].x] + V[i].r + startD[V[i].y])
				used[i] = 1;
		}

		flag = 1;
		d[S] = 0;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < M; i++)
			{
				if (used[i]) continue;
				if (d[V[i].y] > d[V[i].x] + V[i].r)
				{
					d[V[i].y] = d[V[i].x] + V[i].r;
					flag = 1;
				}
			}
		}

		printf("%d\n", (d[D] == 1e9) ? -1 : d[D]);
	}

	return 0;
}