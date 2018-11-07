#include <stdio.h>

inline int MAX(int a, int b)
{
	return (a < b) ? b : a;
}

inline int MIN(int a, int b)
{
	return (a < b) ? a : b;
}

bool chk[401];
int d[401]; // 차이값 n = a-b (-200<=n<=200 -> 0<=n<=400) 일때, sum[a]의 값
int M;
int a[500], b[500];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &M);
		for (int i = 0; i < M; i++) scanf("%d%d", &a[i], &b[i]);

		for (int i = 0; i <= 400; i++) d[i] = 1e9, chk[i] = 0;


		for (int i = 0; i < M; i++)
			d[200 + a[i] - b[i]] = MIN(d[200 + a[i] - b[i]], a[i]);

		int start = -1;
		int val = 1e9;
		for (int i = 0; i <= 400; i++) if (chk[i] == 0 && val >= d[i]) val = d[i], start = i;
		chk[start] = 1;

		for (int k = 0; k < 400; k++)
		{
			for (int i = 0; i < M; i++)
			{
				int next = start + a[i] - b[i];
				if (next < 0 || next > 400) continue;
				if (chk[next]) continue;
				d[next] = MIN(d[next], d[start] + a[i]);
			}

			start = -1;
			val = 1e9;
			for (int i = 0; i <= 400; i++) if (chk[i] == 0 && val >= d[i]) val = d[i], start = i;
			chk[start] = 1;
		}

		if (d[200] == 1e9) printf("IMPOSSIBLE\n");
		else printf("%d\n", d[200]);
	}
	return 0;
}