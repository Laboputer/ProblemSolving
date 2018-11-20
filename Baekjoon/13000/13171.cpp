#include <stdio.h>

typedef long long ll;
const ll MOD = 1000000007ll;

ll A, X;
ll pow[64];
int main()
{
	scanf("%lld %lld", &A, &X);
	pow[0] = A % MOD;
	for (int i = 1; i < 64; i++) pow[i] = (pow[i - 1] * pow[i - 1]) % MOD;
	
	ll ans = 1;
	for (int i = 0; i < 64 && X != 0; i++)
	{
		if (X & 1) ans = (ans * pow[i]) % MOD;
		X = X >> 1;
	}
	printf("%lld\n", ans);
	return 0;
}