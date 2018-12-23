#include <stdio.h>
#define MAXN 1000005

struct UF
{
	int set[MAXN];
	void init() { for (int i = 0; i < MAXN; i++) set[i] = i; }
	int find(int x) { return set[x] = set[x] == x ? x : find(set[x]); }
	void merge(int a, int b) { set[find(a)] = set[find(b)]; }
};

int N, M;
int x[MAXN], y[MAXN];
UF uf;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++) scanf("%d%d", &x[i], &y[i]);

		bool cycle = 0;
		uf.init();
		for (int i = 0; i < M; i++)
		{
			if (uf.find(x[i]) == uf.find(y[i]))
			{
				cycle = 1;
				break;
			}
			uf.merge(x[i], y[i]);
		}

		if (cycle)
		{
			printf("graph\n");
			continue;
		}

		bool connect = 1;
		int s = uf.find(1);
		for (int i = 2; i <= N; i++)
			if (uf.find(i) != s) connect = 0;

		printf("%s\n", connect ? "tree" : "graph");
	}

	return 0;
}