#include <stdio.h>
#define MAXN 505

struct edge
{
	int s, e, r;
};

int N, M, W;
edge E[3000];
int d[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &N, &M, &W);
		for (int i = 0; i < M; i++) scanf("%d%d%d", &E[i].s, &E[i].e, &E[i].r);
		for (int i = M; i < M + W; i++) scanf("%d%d%d", &E[i].s, &E[i].e, &E[i].r), E[i].r = -E[i].r;

		for (int i = 1; i <= N; i++) d[i] = 2e9;
		bool flag = 1;
		int cnt = 0;
		while (flag)
		{
			if (cnt == N + 1) break;
			flag = 0, cnt++;
			for (int i = 0; i < M; i++)
			{
				if (d[E[i].e] > d[E[i].s] + E[i].r) d[E[i].e] = d[E[i].s] + E[i].r, flag = 1;
				if (d[E[i].s] > d[E[i].e] + E[i].r) d[E[i].s] = d[E[i].e] + E[i].r, flag = 1;
			}

			for (int i = M; i < M + W; i++)
				if (d[E[i].e] > d[E[i].s] + E[i].r) d[E[i].e] = d[E[i].s] + E[i].r, flag = 1;
		}
		
		printf("%s\n", (cnt == N + 1) ? "YES" : "NO");
	}

	return 0;
}