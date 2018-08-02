#include <stdio.h>
#include <stdlib.h>

char d[1 << 25];
char map[6][6];

int mv[1000];
int mcnt = 0;

int cell(int i, int j) { return (1 << (i * 5 + j)); }

char win(int state)
{
	char& ref = d[state];
	if (ref != -1) return ref;

	for (int i = 0; i < mcnt; i++)
	{
		if ((state & mv[i]) == 0)
		{
			if (win(state | mv[i]) == 0)
			{
				ref = 1;
				return ref;
			}
		}
	}
	ref = 0;
	return ref;
}


int main()
{
	int k = 1 << 25;
	for (int i = 0; i < k; i++) d[i] = -1;

	for (int i = 0; i < 5; i++) for (int j = 0; j < 4; j++) mv[mcnt++] = cell(i, j) + cell(i, j + 1);
	for (int i = 0; i < 4; i++) for (int j = 0; j < 5; j++) mv[mcnt++] = cell(i, j) + cell(i + 1, j);

	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++, k++)
	{
		int sq = cell(i, j) + cell(i, j + 1) + cell(i + 1, j) + cell(i + 1, j + 1);
		mv[mcnt++] = sq - cell(i, j);
		mv[mcnt++] = sq - cell(i + 1, j);
		mv[mcnt++] = sq - cell(i, j + 1);
		mv[mcnt++] = sq - cell(i + 1, j + 1);
	}

	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 5; i++) scanf("%s", &map[i]);

		int initState = 0;
		for (int i = 0, k = 0; i < 5; i++) for (int j = 0; j < 5; j++, k++)
		{
			if (map[i][j] == '#') initState += (1 << k);
		}
		printf("%s\n", win(initState) ? "WINNING" : "LOSING");
	}
	return 0;
}
//
//#include <stdio.h>
//
//char d[1ll << 25];
//char map[7][7];
//
//char win(char m[7][7])
//{
//	long long index = 0;
//	long long f = 1;
//	for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++)
//	{
//		if (m[i][j] == 2) index += f;
//		f <<= 1;
//	}
//	char& ref = d[index];
//	if (ref != -1) return ref;
//	ref = 0;
//
//	for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++)
//	{
//		if (m[i][j] == 1 && m[i + 1][j] == 1)
//		{
//			m[i][j] = m[i + 1][j] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j] = m[i + 1][j] = 1;
//		}
//
//		if (m[i][j] == 1 && m[i][j + 1] == 1)
//		{
//			m[i][j] = m[i][j + 1] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j] = m[i][j + 1] = 1;
//		}
//
//		if (m[i][j] == 1 && m[i + 1][j] == 1 && m[i + 1][j + 1] == 1)
//		{
//			m[i][j] = m[i + 1][j] = m[i + 1][j + 1] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j] = m[i + 1][j] = m[i + 1][j + 1] = 1;
//		}
//
//		if (m[i][j] == 1 && m[i][j + 1] == 1 && m[i + 1][j + 1] == 1)
//		{
//			m[i][j] = m[i][j + 1] = m[i + 1][j + 1] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j] = m[i][j + 1] = m[i + 1][j + 1] = 1;
//		}
//
//		if (m[i][j] == 1 && m[i + 1][j] == 1 && m[i][j + 1] == 1)
//		{
//			m[i][j] = m[i + 1][j] = m[i][j + 1] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j] = m[i + 1][j] = m[i][j + 1] = 1;
//		}
//
//		if (m[i][j + 1] == 1 && m[i + 1][j] == 1 && m[i + 1][j + 1] == 1)
//		{
//			m[i][j + 1] = m[i + 1][j] = m[i + 1][j + 1] = 2;
//			if (win(m) == 0) ref = 1;
//			m[i][j + 1] = m[i + 1][j] = m[i + 1][j + 1] = 1;
//		}
//		if (ref == 1) return ref;
//	}
//	return ref;
//}
//
//int main()
//{
//	long long k = 1ll << 25;
//	for (long long i = 0; i < k; i++) d[i] = -1;
//
//	int t; scanf("%d", &t);
//	while (t--)
//	{
//		for (int i = 1; i <= 5; i++) scanf("%s", &map[i][1]);
//		for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) map[i][j] = (map[i][j] == '.') ? 1 : 2;
//
//		printf("%s\n", win(map) ? "WINNING" : "LOSING");
//	}
//	return 0;
//}