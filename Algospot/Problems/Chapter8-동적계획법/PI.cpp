#include <stdio.h>
#define MAXN 10005
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
int N;
char str[MAXN];
int d[MAXN];

int F(int x)
{
	if (x == 0) return 0;

	int& ref = d[x];
	if (ref != -1) return ref;

	ref = 1e9;
	if (x - 3 >= 0)
	{
		if (str[x - 2] == str[x - 1] && str[x - 1] == str[x]) ref = MIN(ref, F(x - 3) + 1);
		else if (str[x - 2] + 1 == str[x - 1] && str[x - 1] + 1 == str[x]) ref = MIN(ref, F(x - 3) + 2);
		else if (str[x - 2] - 1 == str[x - 1] && str[x - 1] - 1 == str[x]) ref = MIN(ref, F(x - 3) + 2);
		else if (str[x - 2] == str[x]) ref = MIN(ref, F(x - 3) + 4);
		else if (str[x - 2] - str[x - 1] == str[x - 1] - str[x]) ref = MIN(ref, F(x - 3) + 5);
		else ref = MIN(ref, F(x - 3) + 10);
	}
	if (x - 4 >= 0)
	{
		if (str[x - 3] == str[x - 2] && str[x - 2] == str[x - 1] && str[x - 1] == str[x]) ref = MIN(ref, F(x - 4) + 1);
		else if (str[x - 3] + 1 == str[x - 2] && str[x - 2] + 1 == str[x - 1] && str[x - 1] + 1 == str[x]) ref = MIN(ref, F(x - 4) + 2);
		else if (str[x - 3] - 1 == str[x - 2] && str[x - 2] - 1 == str[x - 1] && str[x - 1] - 1 == str[x]) ref = MIN(ref, F(x - 4) + 2);
		else if (str[x - 3] == str[x - 1] && str[x - 2] == str[x]) ref = MIN(ref, F(x - 4) + 4);
		else if (str[x - 3] - str[x - 2] == str[x - 2] - str[x - 1] && str[x - 2] - str[x - 1] == str[x - 1] - str[x]) ref = MIN(ref, F(x - 4) + 5);
		else ref = MIN(ref, F(x - 4) + 10);
	}
	if (x - 5 >= 0)
	{
		if (str[x - 4] == str[x - 3] && str[x - 3] == str[x - 2] && str[x - 2] == str[x - 1] && str[x - 1] == str[x]) ref = MIN(ref, F(x - 5) + 1);
		else if (str[x - 4] + 1 == str[x - 3] && str[x - 3] + 1 == str[x - 2] && str[x - 2] + 1 == str[x - 1] && str[x - 1] + 1 == str[x]) ref = MIN(ref, F(x - 5) + 2);
		else if (str[x - 4] - 1 == str[x - 3] && str[x - 3] - 1 == str[x - 2] && str[x - 2] - 1 == str[x - 1] && str[x - 1] - 1 == str[x]) ref = MIN(ref, F(x - 5) + 2);
		else if (str[x - 4] == str[x - 2] && str[x - 3] == str[x - 1] && str[x - 2] == str[x]) ref = MIN(ref, F(x - 5) + 4);
		else if (str[x - 4] - str[x - 3] == str[x - 3] - str[x - 2] && str[x - 3] - str[x - 2] == str[x - 2] - str[x - 1] && str[x - 2] - str[x - 1] == str[x - 1] - str[x]) ref = MIN(ref, F(x - 5) + 5);
		else ref = MIN(ref, F(x - 5) + 10);
	}
	return ref;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%s", &str[1]);
		N = 0; for (int i = 1; str[i]; i++) N++;
		for (int i = 0; i <= N; i++) d[i] = -1;
		printf("%d\n", F(N));
	}
	return 0;
}