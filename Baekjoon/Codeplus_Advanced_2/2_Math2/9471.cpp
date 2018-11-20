#include <stdio.h>

int N, M;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &M);
		int p1 = 1, p2 = 2;
		int ans = 1;
		while (p1 != 1 || p2 != 1)
		{
			int a = p2;
			int b = (p1 + p2) % M;
			p1 = a, p2 = b;
			ans++;
		}
		printf("%d %d\n", N, ans);

	}
	return 0;
}