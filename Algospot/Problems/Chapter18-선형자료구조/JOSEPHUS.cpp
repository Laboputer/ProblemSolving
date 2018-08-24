#include <stdio.h>
#define MAXN 1005

struct queue
{
	int arr[MAXN + 1];
	int head = 0;
	int tail = 0;
	int sz = 0;

	void push(int x)
	{
		arr[tail] = x;
		tail = (tail + 1) % MAXN;
		sz++;
	}

	void pop()
	{
		sz--;
		head = (head + 1) % MAXN;
	}

	int Top()
	{
		return arr[head];
	}
};

int N, K;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &K);
		queue q;
		for (int i = 2; i <= N; i++) q.push(i);

		while (q.sz > 2)
		{
			for (int i = 0; i < K - 1; i++)
			{
				q.push(q.Top());
				q.pop();
			}
			q.pop();
		}

		int a = q.Top(); q.pop();
		int b = q.Top();
		if (a > b) int t = a, a = b, b = t;
		printf("%d %d\n", a, b);
	}

	return 0;
}