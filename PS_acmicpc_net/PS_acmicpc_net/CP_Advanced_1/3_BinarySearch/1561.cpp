#include <stdio.h>
#define MAXM 10005

long long N;
int M;
int T[MAXM];

bool P(long long t)
{
	long long cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		cnt += t / T[i] + 1;
		if (cnt >= N) return 1;
	}
	return 0;
}

int main()
{
	scanf("%lld%d", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%d", &T[i]);

	if (N <= M) return 0 & printf("%d\n", N);

	long long ll = 1, rr = 2e12;
	long long t1, t2;
	while (ll <= rr)
	{
		long long m = (ll + rr) >> 1;
		if (P(m)) rr = m - 1, t2 = m;
		else ll = m + 1;
	}
	t1 = t2 - 1;
	int n = 0;
	for (int i = 1; i <= M; i++) n += t1 / T[i] + 1;
	n = N - n;

	for (int i = 1; i <= M; i++)
	{
		if ((t2 % T[i] == 0) && (--n == 0)) 
		{ 
			printf("%d\n", i); 
			break; 
		}
	}

	return 0;
}