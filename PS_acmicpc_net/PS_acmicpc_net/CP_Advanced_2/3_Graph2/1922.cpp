#include <stdio.h>

struct UF
{
	int set[1005];
	UF() { for (int i = 0; i < 1005; i++) set[i] = i; }
	int Find(int x) { return set[x] = ((set[x] == x) ? x : Find(set[x])); }
	void Union(int a, int b) { set[Find(a)] = Find(b); }
};

struct edge
{
	int s, e, r;
};

int N, M;
edge E[100005];
edge tmp[100005];
void SWAP(int i, int j) { edge t = E[i]; E[i] = E[j]; E[j] = t; }
void Sort(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	Sort(l, m);
	Sort(m + 1, r);

	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (E[p1].r < E[p2].r) ? E[p1++] : E[p2++];
	while (p1 <= m) tmp[p3++] = E[p1++];
	while (p2 <= r) tmp[p3++] = E[p2++];

	for (int i = l; i <= r; i++) E[i] = tmp[i];
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d%d%d", &E[i].s, &E[i].e, &E[i].r);
	UF uf;
	Sort(0, M - 1);

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		if (uf.Find(E[i].s) != uf.Find(E[i].e))
		{
			uf.Union(E[i].s, E[i].e);
			ans += E[i].r;
			cnt++;
		}
		if (cnt == N - 1) break;
	}
	printf("%d\n", ans);
	return 0;
}