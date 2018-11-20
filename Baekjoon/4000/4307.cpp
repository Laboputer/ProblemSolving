#include <stdio.h>
#define MAXN 1000005

inline int max(int a, int b)
{
	if (a < b) return b;
	else return a;
}
inline int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int L, N;
int a[MAXN];
int main()
{
	// 0~ L 까지 길이의 막대로
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &L, &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);

		int mn = 0, mx = 0;
		for (int i = 0; i < N; i++)
		{
			mn = max(mn, min(L - a[i], a[i]));
			mx = max(mx, max(L - a[i], a[i]));
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}