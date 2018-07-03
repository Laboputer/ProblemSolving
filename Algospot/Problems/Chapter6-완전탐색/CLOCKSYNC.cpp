#include <stdio.h>
#define MAXN 16

const int swi[10][10]=
{
	{0,1,2,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7,-1},
	{6,7,8,10,12,-1},
	{0,2,14,15,-1},
	{3,14,15,-1},
	{4,5,7,14,15,-1},
	{1,2,3,4,5,-1},
	{3,4,5,9,13,-1}
};

int N = MAXN;
int watch[MAXN];
int tmp[MAXN];
int sw[MAXN];

int ans;
void F(int n)
{
	if (n == 10)
	{
		for (int i = 0; i < 16; i++) tmp[i] = watch[i];
		for (int i = 0; i < 10; i++) for (int j = 0; swi[i][j] != -1; j++) tmp[swi[i][j]] += sw[i] * 3;
		for (int i = 0; i < 16; i++) tmp[i] %= 12;

		bool flag = 1;
		for (int i = 0; i < N; i++) if (tmp[i] != 0) flag = 0;
		if (!flag) return;
		
		int cnt = 0;
		for (int i = 0; i < 10; i++) cnt += sw[i];
		if (ans > cnt) ans = cnt;
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		sw[n] = i;
		F(n + 1);
	}
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < N; i++) scanf("%d", &watch[i]), watch[i] %= 12;
		ans = 2e9;
		F(0);
		printf("%d\n", ans == 2e9 ? -1 : ans);
	}
 	return 0;
}