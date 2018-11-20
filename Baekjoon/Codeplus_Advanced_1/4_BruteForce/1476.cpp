#include <stdio.h>

int E, S, M;
int main()
{
	scanf("%d%d%d", &E, &S, &M);

	int ans = 1;
	int e = 1, s = 1, m = 1;
	while (1)
	{
		if (e == E && s == S && m == M) return 0 & printf("%d\n", ans);

		e++; if (e == 16) e = 1;
		s++; if (s == 29) s = 1;
		m++; if (m == 20) m = 1;
		ans++;
	}
	return 0;
}