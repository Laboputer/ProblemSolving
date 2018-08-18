#include <stdio.h>
#define MAXN 205

int N;
int R[MAXN], P[MAXN];

int GCD(int a, int b)
{
	return (b == 0) ? a : GCD(b, a%b);
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &R[i]);
		for (int i = 0; i < N; i++) scanf("%d", &P[i]);
		
		int gcd = R[0];
		for (int i = 1; i < N; i++) gcd = GCD(gcd, R[i]);
		for (int i = 0; i < N; i++) R[i] /= gcd;

		int f = 0;
		for (int i = 0; i < N; i++)
		{
			int ff = (P[i] / R[i]) + ((P[i] % R[i] != 0) ? 1 : 0); // ���� ���� ������ ������ �ø��� ��
			if (f < ff) f = ff;
		}

		for (int i = 0; i < N; i++) printf("%d ", f * R[i] - P[i]);
		printf("\n");
	}
	return 0;
}