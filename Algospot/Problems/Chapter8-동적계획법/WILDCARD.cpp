#include <stdio.h>
#define MAXN 55
#define MAXR 105

char wild[MAXR];
int snum;

int match[MAXN];
int mcnt;

int N;
char strings[MAXN][MAXR];
int d[MAXR][MAXR];

int F(int n, int c)
{
	if (wild[n] == 0 && strings[snum][c] == 0) return 1;
	else if (wild[n] == 0 && strings[snum][c] != 0) return 0;

	int& ref = d[n][c];
	if (ref != -1) return ref;
	ref = 0;
	if (wild[n] == '*')
	{
		int i; for (i = c; strings[snum][i] != 0; i++) ref |= F(n + 1, i);
		ref |= F(n + 1, i);
	}
	else if (wild[n] == '?' && strings[snum][c] != 0) ref |= F(n + 1, c + 1);
	else if (wild[n] == strings[snum][c]) ref |= F(n + 1, c + 1);
	return ref;
}

bool IsUpper(char* n1, char* n2)
{
	for (int i = 0; n1[i] != 0 || n2[i] != 0; i++)
		if (n1[i] != n2[i]) return n1[i] < n2[i];
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%s", wild);
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%s", strings[i]);

		mcnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < MAXR; j++) for (int k = 0; k < MAXR; k++) d[j][k] = -1;
			snum = i;
			if (F(0, 0)) match[mcnt++] = i;
		}

		for (int i = 0; i < mcnt; i++) for (int j = i + 1; j < mcnt; j++)
		{
			if (IsUpper(strings[match[j]], strings[match[i]]))
			{
				int t = match[i];
				match[i] = match[j];
				match[j] = t;
			}
		}

		for (int i = 0; i < mcnt; i++) printf("%s\n", strings[match[i]]);

	}
	return 0;
}