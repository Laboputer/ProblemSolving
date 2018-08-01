#include <stdio.h>

int Judge(int s[9])
{
	if (s[0] != '.' && s[0] == s[1] && s[1] == s[2]) return s[0];
	else if (s[3] != '.' && s[3] == s[4] && s[4] == s[5]) return s[3];
	else if (s[6] != '.' && s[6] == s[7] && s[7] == s[8]) return s[6];
	else if (s[0] != '.' && s[0] == s[3] && s[3] == s[6]) return s[0];
	else if (s[1] != '.' && s[1] == s[4] && s[4] == s[7]) return s[1];
	else if (s[2] != '.' && s[2] == s[5] && s[5] == s[8]) return s[2];
	else if (s[0] != '.' && s[0] == s[4] && s[4] == s[8]) return s[0];
	else if (s[2] != '.' && s[2] == s[4] && s[4] == s[6]) return s[2];
	else return -1;
}

int p[9];
int win(int s[9], int who)
{
	int jud = Judge(s);
	if (jud != -1) return jud;

	bool end = true;
	for (int i = 0; i < 9; i++) if (s[i] == -1) end = false;
	if (end) return jud;


	bool same = false;
	bool w = false;
	for (int i = 0; i < 9; i++)
	{
		if (s[i] != -1) continue;
		s[i] = who;
		int k = win(s, (who + 1) % 2);
		s[i] = -1;

		if (k == -1) same = true;
		else if (k == who) w = true;
	}

	if (w) return who;
	else if (same) return -1;
	else return (who + 1) % 2;
}

int main()
{
	char map[5];
	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 3; i++)
		{
			scanf("%s", map);
			for (int j = 0; j < 3; j++)
				if (map[j] == '.') p[i * 3 + j] = -1;
				else if (map[j] == 'x') p[i * 3 + j] = 0;
				else if (map[j] == 'o') p[i * 3 + j] = 1;
		}


		int xcnt = 0;
		int ocnt = 0;
		for (int i = 0; i < 9; i++)
			if (p[i] == 0) xcnt++;
			else if (p[i] == 1) ocnt++;

			bool turnX = (xcnt <= ocnt) ? 1 : 0;

			int ans = win(p, turnX ? 0 : 1);
			if (ans == -1) printf("TIE\n");
			else if (ans == 0) printf("x\n");
			else printf("o\n");
	}
	return 0;
}