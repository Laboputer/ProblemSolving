#include <stdio.h>
#define FULL (1<<24)

struct queue
{
	int arr[FULL + 1];
	int size = 0;
	int f = 0, b = 0;

	void init()
	{
		size = 0;
		f = 0; b = 0;
	}
	void push(int x)
	{
		arr[b++] = x;
		b %= FULL;
		size++;
	}

	void pop()
	{
		f = (f + 1) % FULL;
		size--;
	}

	int top()
	{
		return arr[f];
	}
};

int N;
int v[FULL + 1];
queue q;

int getCol(int x, int i)
{
	return (x >> (i + i)) & 3;
}

// i번째 판을 j 기둥으로
int getChange(int x, int i, int j)
{
	return (x & ~(3 << (i + i))) | (j << (i + i));
}

int biBFS(int start, int end)
{
	if (start == end) return 1;

	for (int i = 0; i < FULL; i++) v[i] = 0;
	q.init();
	q.push(start);
	q.push(end);
	v[start] = 1;
	v[end] = -1;
	
	int depth = 1;
	while (q.size)
	{
		int size = q.size;
		depth++;
		while (size--)
		{
			int here = q.top(); q.pop();

			int top[4] = { 100, 100, 100, 100 };
			for (int i = 0; i < N; i++)
			{
				int s = getCol(here, i);
				if (top[s] == 100) top[s] = i;
			}

			for (int i = 0; i < 4; i++)
			{
				if (top[i] == 100) continue;
				for (int j = 0; j < 4; j++)
				{
					if (i == j || top[i] > top[j]) continue;
					int to = getChange(here, top[i], j);
					
					if (v[to] == 0)
					{
						v[to] = v[here] < 0 ? -depth : depth;
						q.push(to);
					}
					else if ((v[here] > 0 && v[to] < 0) || (v[here] < 0 && v[to] >0))
					{
						int diff = v[here] - v[to];
						if (diff < 0) diff = -diff;
						return diff;
					}
				}
			}

		}
	}

}


int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);

		int start = 0;
		for (int i = 0, cnt, x; i < 4; i++)
		{
			scanf("%d", &cnt);
			for (int k = 0; k < cnt; k++)
			{
				scanf("%d", &x);
				x--;
				start |= i << (x + x);
			}
		}

		int end = (1 << (N + N)) - 1;
		printf("%d\n", biBFS(start, end)-1);
	}

	return 0;
}