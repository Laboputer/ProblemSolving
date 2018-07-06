#include <stdio.h>
#define MAXN 1005

struct node
{
	int a, b, c, d;
};
char str[MAXN];
int cnt;
node tree[MAXN];

void InitTree(int x)
{
	cnt++;
	if (str[x] != 'x') return;

	tree[x].a = cnt; InitTree(cnt);
	tree[x].b = cnt; InitTree(cnt);
	tree[x].c = cnt; InitTree(cnt);
	tree[x].d = cnt; InitTree(cnt);
}

void DFS(int x)
{
	printf("%c", str[x]);
	if (str[x] != 'x') return;

	DFS(tree[x].c);
	DFS(tree[x].d);
	DFS(tree[x].a);
	DFS(tree[x].b);
}


int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		cnt = 0;
		InitTree(0);
		DFS(0);
		printf("\n");
	}
	return 0;
}