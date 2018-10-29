#include <stdio.h>
#define FULL (1<<24)

struct queue
{
	int arr[FULL+ 1];
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
int arr[8];
int v[FULL];
queue q;

int getVal(int state, int i) // i번째 값
{
	return (state >> (i * 3)) & 7;
}

int getChange(int state, int i, int k) // i번째 값을 k로 변경한 값
{
	return (state & ~(7 << (i * 3))) | (k << (i * 3));
}

int rev(int state, int l, int r) // l~r 리버스한 값
{
	for (int k = 0; k < (r - l + 1) / 2; k++)
	{
		int t = getVal(state, l + k);
		state = getChange(state, l + k, getVal(state, r - k));
		state = getChange(state, r - k, t);
	}
	return state;
}

void bfs(int n, int start)
{
	q.init();
	q.push(start);
	v[start] = 0;

	int depth = 0;
	while (q.size)
	{
		int size = q.size;
		depth++;
		while (size--)
		{
			int here = q.top(); q.pop();
			for (int i = 0; i < n; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					int to = rev(here, i, j);
					if (v[to] == -1)
					{
						v[to] = depth;
						q.push(to);
					}
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < (1<<24); i++) v[i] = -1;

	int init = 0;
	for (int i = 0; i < 8; i++)
		init |= (i << (i * 3));

	bfs(8, init);

	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

		int end = 0;
		bool ch[8];
		for (int i = 0; i < 8; i++) ch[i] = 0;
		for (int i = 0; i < N; i++)
		{
			int mn = 2e9;
			int idx = 0;
			for (int j = 0; j < N; j++)
			{
				if (ch[j]) continue;
				if (mn > arr[j]) mn = arr[j], idx = j;
			}
			end |= (i << (idx * 3));
			ch[idx] = 1; 
		}
		for (int i = N; i < 8; i++)
		{
			end |= (i << (i * 3));
		}

		printf("%d\n", v[end]);
	}
	return 0;
}
