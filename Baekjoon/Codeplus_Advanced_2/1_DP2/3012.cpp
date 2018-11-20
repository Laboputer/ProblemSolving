#include <stdio.h>
#define MAXN 205
#define MOD 100000

int N;
char str[MAXN];
long long d[MAXN][MAXN];
bool over = 0;
long long getCnt(char a, char b)
{
	if (a == '?' && b == '?') return 3;
	else if (a == '?' && ((b == ')') || (b == '}') || (b == ']'))) return 1;
	else if (b == '?' && ((a == '(') || (a == '{') || (a == '['))) return 1;
	else if ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')) return 1;
	else return 0;
 } 

long long F(int i, int j)
{
	if (i + 1 == j) return getCnt(str[i], str[j]);
	
	long long& ref = d[i][j];
	if (ref != -1) return ref;
	ref = 0;
	for (int k = i + 1; k <= j; k += 2)
	{
		long long c = getCnt(str[i], str[k]);
		if (c == 0) continue;
		if (i + 1 < k - 1) c *= F(i + 1, k - 1);
		if (k + 1 < j) c *= F(k + 1, j);

		ref += c;
		if (i == 0 && j == N - 1 && ref >= MOD) over = 1;
		ref %= MOD;
	}
	return ref;
}

int main()
{
	scanf("%d", &N);
	scanf("%s", str);
	if (N & 1) return 0 & printf("0\n");

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) d[i][j] = -1;
	
	long long ans = F(0, N - 1);
	if (over) printf("%05lld\n", ans);
	else printf("%lld\n", ans);
	return 0;
}