#include <stdio.h>
#define MAXN 20005

struct stack
{
	int arr[MAXN+1];
	int cur = 0;
	int sz = 0;
	void push(int x)
	{
		arr[++cur] = x;
		sz++;
	}
	int top()
	{
		return arr[cur];
	}
	void pop()
	{
		cur--, sz--;
	}
};

int N;
int H[MAXN];
int left[MAXN];
int right[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &H[i]);
		H[N] = 0;

		stack st;
		for (int i = 0; i <= N; i++)
		{
			while (st.sz != 0 && H[st.top()] > H[i])
			{
				right[st.top()] = i - 1;
				st.pop();
			}

			if (st.sz == 0) left[i] = 0;
			else left[i] = st.top() + 1;
			st.push(i);
		}

		int ans = 0;
		for (int i = 0; i < N; i++) if (ans < (H[i] * (right[i] - left[i] + 1))) ans = H[i] * (right[i] - left[i] + 1);
		printf("%d\n", ans);
	}
	return 0;
}