#include <stdio.h>
#define MAXN 55

char str[MAXN];

int op[MAXN];
char opr[MAXN];
int sum[MAXN];
int main()
{
	scanf("%s", str);

	int cnt = 0;
	for (int i = 0; str[i]; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			op[cnt] *= 10;
			op[cnt] += str[i] - '0';
		}
		else
		{
			opr[cnt] = str[i];
			cnt++;
		}
	}

	int cnt2 = 0;
	sum[0] = op[0];
	for (int i = 0; i < cnt; i++)
	{
		if (opr[i] == '-') cnt2++;
		sum[cnt2] += op[i + 1];
	}
	int ans = sum[0];
	for (int i = 1; i <= cnt2; i++) ans -= sum[i];

	printf("%d", ans);
	return 0;
}