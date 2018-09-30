#include <stdio.h>
#define MAXN 1005

int N;
char str[MAXN][25];

int G[26][26];
int p[26];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%s", str[i]);
		
		for (int i = 0; i < 26; i++) p[i] = 0;
		for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) G[i][j] = 0;
		
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; str[i - 1][j] && str[i][j]; j++)
			{
				if (str[i - 1][j] != str[i][j])
				{
					int f = str[i - 1][j] - 'a';
					int t = str[i][j] - 'a';
					if (G[f][t] == 0)
					{
						G[f][t] = 1;
						p[t]++;
					}
					break;
				}
			}
		}


		char ans[26];
		int c = 0;

		bool flag = 1;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < 26; i++)
			{
				if (p[i] == 0)
				{
					p[i] = -1;
					ans[c++] = i + 'a';
					for (int j = 0; j < 26; j++)
						if (G[i][j] == 1) p[j]--;
					flag = 1;
				}
			}
		}

		if (c == 26) for (int i = 0; i < 26; i++) printf("%c", ans[i]);
		else printf("INVALID HYPOTHESIS");
		printf("\n");
	}
	return 0;
}