#include <stdio.h>
#define MAXN 300005

struct STK
{
	int data[MAXN];
	int sz;
	int top;

	STK()
	{
		sz = 0, top = -1;
	}

	void PUSH(int x)
	{
		top++, sz++;
		data[top] = x;
	}

	int TOP()
	{
		return data[top];
	}

	void POP()
	{
		top--, sz--;
	}
};

int N, P;
int main()
{
	scanf("%d%d", &N, &P);

	int n, p;
	STK st[6];

	long long ans = 0;
	while (N--)
	{
		scanf("%d%d", &n, &p);

		while (st[n - 1].sz && st[n - 1].TOP() > p) ans++, st[n - 1].POP();
		if (st[n - 1].sz == 0 || st[n - 1].TOP() != p) ans++, st[n - 1].PUSH(p);
	}

	printf("%lld", ans);

	return 0;
}