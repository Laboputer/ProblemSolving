#include <stdio.h>
#define MAX(a,b) ((a<b) ? (b) : (a))
int N;
int a[8];
int t[8];
int v[8];

int ans = -2e9;

void P(int n)
{
	if (n == N)
	{
		int val = 0;
		for (int i = 0; i < N - 1; i++)
			val += (a[t[i]] - a[t[i + 1]] < 0) ? a[t[i + 1]] - a[t[i]] : a[t[i]] - a[t[i + 1]];
		if (ans < val) ans = val;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (v[i]) continue;
		v[i] = 1;
		t[n] = i;
		P(n + 1);
		v[i] = 0;
	}
}

int main()
{
	scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", &a[i]);

	for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++)
		if (a[i] > a[j]) { int t = a[i]; a[i] = a[j]; a[j] = t; }

	P(0);
	printf("%d\n", ans);
	return 0;
}