#include <stdio.h>

int N;
int a[9];
int v[9];
void F(int n)
{
	if (n == N)
	{
		for (int i = 0; i < N; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (v[i]) continue;
		a[n] = i, v[i] = 1;
		F(n + 1);
		v[i] = 0;
	}
}
int main()
{
	scanf("%d", &N);
	F(0);
	return 0;
}