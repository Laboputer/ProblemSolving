#include <stdio.h>
#define MAXN 105

struct VEC
{
	int a[MAXN];
	int c;
	int s;
};

char str[MAXN][20];

int N;
VEC G[26][26];
int in[26], out[26];

int used[MAXN];
int path[MAXN];
int cnt;

bool CanFind()
{
	int icnt = 0, ocnt = 0;
	for (int i = 0; i < 26; i++)
	{
		int d = in[i] - out[i];
		if (d < -1 || d > 1) return false;
		if (d == -1) ocnt++;
		if (d == 1) icnt++;
	}

	if (icnt == 1 && ocnt == 1) return true;
	else if (icnt == 0 && ocnt == 0) return true;
	else return false;
}

void DFS(int x)
{
	for (int i = 0; i < 26; i++)
	{
		while (G[x][i].s)
		{
			G[x][i].s--;
			out[x]--;
			in[i]--;
			DFS(i);
		}
	}
	path[cnt++] = x;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) G[i][j].s = G[i][j].c = 0;
		for (int i = 0; i < 26; i++) in[i] = out[i] = used[i] = 0;
		cnt = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%s", str[i]);
		for (int i = 0; i < N; i++)
		{
			int len = 0; for (; str[i][len]; len++);
			char ff = str[i][0] - 'a', ll = str[i][len - 1] - 'a';
			G[ff][ll].a[G[ff][ll].c++] = i;
			G[ff][ll].s++;
			out[ff]++;
			in[ll]++;
		}

		if (!CanFind())
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		int start;
		for (int i = 0; i < 26; i++) if (out[i] != 0) start = i;
		for (int i = 0; i < 26; i++) if (out[i] == in[i] + 1) start = i;
		DFS(start);

		if (cnt != N + 1) printf("IMPOSSIBLE\n");
		else
		{
			for (int i = cnt - 1; i > 0; i--)
			{
				int back = G[path[i]][path[i - 1]].c - 1;
				int idx = G[path[i]][path[i - 1]].a[back];
				if (i == 1) printf("%s\n", str[idx]);
				else printf("%s ", str[idx]);
				G[path[i]][path[i - 1]].c--;
			}
		}
	}
	return 0;
}