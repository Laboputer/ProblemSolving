#include <stdio.h>
#define MAXN 1000005

struct UF
{
	int set[MAXN];
	UF() { for (int i = 0; i < MAXN; i++) set[i] = i; }
	int Find(int x) { return set[x] = (set[x] == x ? x : Find(set[x])); }
	void Union(int a, int b) { set[Find(a)] = Find(b); }
};

int N, M;
int main()
{
	scanf("%d%d", &N, &M);
	UF uf;
	for (int i = 0, x, a, b; i < M; i++)
	{
		scanf("%d%d%d", &x, &a, &b);
		if (x == 0) uf.Union(a, b);
		else printf("%s\n", (uf.Find(a) == uf.Find(b) ? "YES" : "NO"));
	}
	return 0;
}