#include <stdio.h>

int LR(int x)
{
	int k = (x & (1 << 7)) != 0 ? 1 : 0;
	return ((x << 1) + k) & 0xFF;
}

int RR(int x)
{
	int k = (x & 1);
	return ((x >> 1) + (k << 7));
}

int top[4];
int main()
{
	char str[10];
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < 8; j++)
			if (str[j] == '1') top[i] += 1 << (7 - j);
	}

	int r[4], n, d;
	int K; scanf("%d", &K);
	while (K--)
	{
		scanf("%d%d", &n, &d);
		n--;
		for (int i = 0; i < 4; i++) r[i] = 0;
		r[n] = d;

		for (int i = n - 1; i >= 0; i--)
		{
			int g1 = (top[i] & (1 << 5)) != 0 ? 1 : 0;
			int g2 = (top[i + 1] & (1 << 1)) != 0 ? 1 : 0;
			if (g1 != g2)
				r[i] = -r[i + 1];
			else break;
		}

		for (int i = n + 1; i < 4; i++)
		{
			int g1 = (top[i - 1] & (1 << 5)) != 0 ? 1 : 0;
			int g2 = (top[i] & (1 << 1)) != 0 ? 1 : 0;
			if ( g1 != g2 ) 
				r[i] = -r[i - 1];
			else break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (r[i] == 1) top[i] = RR(top[i]);
			else if (r[i] == -1) top[i] = LR(top[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((top[i] & (1 << 7)))
			ans += (1 << i);
	}
	printf("%d\n", ans);
	return 0;
}