#include <stdio.h>
#define MAXN 100005

char str[MAXN];
int cnt[10];
int main()
{
	scanf("%s", str);

	bool chk = 0;
	int sum = 0;
	for (int i = 0; str[i]; i++)
	{
		cnt[str[i] - '0']++;
		if (str[i] == '0') chk = 1;
		else sum += str[i] - '0';
	}

	if (sum % 3 != 0 || !chk) printf("-1");
	else
		for (int i = 9; i >= 0; i--)
			while (cnt[i]) { printf("%d", i); cnt[i]--; }

	return 0;
}