#include <stdio.h>
#define MAXN 1005

char str[MAXN];
int cnt;
void F(int x)
{
	if (str[x] != 'x') printf("%c", str[x]), cnt++;
	else { 
		cnt = cnt + 3; 
		F(x + cnt); 
		cnt = cnt + 4;
		F(x + cnt); 
		cnt = cnt + 1;
		F(x + cnt); 
		cnt = cnt + 2;
		F(x + cnt);
	}
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		cnt = 0;
		F(0);
		printf("\n");
	}
	return 0;
}