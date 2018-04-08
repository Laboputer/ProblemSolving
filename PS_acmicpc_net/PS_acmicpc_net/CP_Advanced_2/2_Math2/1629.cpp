#include <stdio.h>

long long A, B, C;

long long F(long long b)
{
	if (b == 0) return 1;

	long long f = F(b>>1);
	f = (f*f) % C;
	if (b & 1) f = (A*f) % C;
	return f;
}
int main()
{
	scanf("%lld%lld%lld", &A, &B, &C);
	printf("%lld", F(B));
	return 0;
}