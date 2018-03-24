#include <stdio.h>
#define MAXN 10005

int N;
int a[MAXN];
int v[MAXN];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	int c = 1;
	for (int i = N - 2; i >= 0 && a[i] < a[i + 1]; i--, c++);

	if (c == N) return 0 & printf("-1\n");

	int up = 0;
	v[a[N - c - 1]] = 1;
	for (int i = N - c; i < N; i++)
	{
		v[a[i]] = 1;
		if (a[N - c - 1] > a[i] && a[i] > up) up = a[i];
	}

	a[N - c - 1] = up;
	v[up] = 0;
	int cur = N - c;
	for (int i = N; i >= 1; i--) if (v[i]) a[cur++] = i;

	for (int i = 0; i < N; i++) printf("%d ", a[i]);

	return 0;
}