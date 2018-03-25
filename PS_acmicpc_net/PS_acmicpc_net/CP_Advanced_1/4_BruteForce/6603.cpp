#include <stdio.h>

int K;
int S[14];
int tmp[6];
int v[14];

void F(int n)
{
	if (n == 6)
	{
		for (int i = 0; i < 6; i++) printf("%d ", S[tmp[i]]);
		printf("\n");
		return;
	}

	int i = 0;
	if (n != 0) i = tmp[n - 1];
	for ( ; i < K; i++)
	{
		if (v[i]) continue;
		v[i] = 1;
		tmp[n] = i;
		F(n + 1);
		v[i] = 0;
	}
}

int main()
{
	while (scanf("%d", &K))
	{
		if (K == 0) return 0;

		for (int i = 0; i < K; i++) scanf("%d", &S[i]);
		F(0);
		printf("\n");
	}

	return 0;
}