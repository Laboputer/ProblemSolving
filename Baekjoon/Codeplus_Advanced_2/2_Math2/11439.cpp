#include <stdio.h>
#define MAXN 4000005
typedef long long ll;

struct prime
{
	ll p[300000];
	int cnt = 0;

	prime()
	{
		bool pp[MAXN];
		for (int i = 1; i < MAXN; i++) pp[i] = 1;
		for (int i = 4; i < MAXN; i += 2) pp[i] = 0;
		for (int i = 3; i < MAXN; i += 2)
			if (pp[i]) for (int j = i + i; j < MAXN; j += i) pp[j] = 0;
		for (int i = 2; i < MAXN; i++) if (pp[i]) p[cnt++] = i;
	}
};

int N, K, M;
ll f[300000];
prime p;

long long pow(long long n, long long r)
{
	if (r == 0) return 1;
	if (r & 1) return (n * pow(n, r - 1)) % M;
	long long pval = pow(n, r / 2);
	return (pval*pval) % M;
}

void F(ll k, bool add)
{
	for (int i = 0; i < p.cnt && p.p[i] <= k; i++)
	{
		ll pval = p.p[i];
		while (k / pval)
		{
			if (add) f[i] += (k / pval);
			else f[i] -= (k / pval);
			pval *= p.p[i];
		}
	}
}

int main()
{
	scanf("%d%d%d", &N, &K, &M);

	// N! prime factorization
	F(N, 1);

	F(K, 0);
	F(N - K, 0);

	long long ans = 1;
	for (int i = 0; i < p.cnt; i++)
		ans = (ans * pow(p.p[i], f[i])) % M;

	printf("%lld\n", ans);

	return 0;
}