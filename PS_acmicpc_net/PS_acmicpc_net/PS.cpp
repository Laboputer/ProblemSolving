#include <stdio.h>
#define MAXN 500005

struct node
{
	int t;
	int val;
};

struct stack
{
	node set[MAXN];
	int sz = 0;
	void Push(node x) { set[sz++] = x; }
	void Pop() { sz--; }
	node Top() { return set[sz-1]; }
};
int N;

int main()
{
	scanf("%d", &N);
	stack st;
	long long ans = 0;
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		if (st.sz == 0 || st.Top().val >= x) st.Push({ i,x });
		else
		{
			while (st.sz)
			{
				node top = st.Top();
				if (top.val > x) break;
				st.Pop();
				ans += (long long)(i - top.t);
			}
			st.Push({ i,x });
		}
	}
	while (st.sz)
	{
		node top = st.Top(); st.Pop();
		ans += (long long)(N-1 - top.t);
	}

	printf("%lld\n", ans);
	return 0;
}