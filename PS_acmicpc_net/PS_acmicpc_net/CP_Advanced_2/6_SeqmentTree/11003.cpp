#include <stdio.h>
#define MAXN 5000005

struct node
{
	int val, idx;
};

struct heap
{
	node data[MAXN];
	int sz = 0;

	void swap(int i, int j) { node t = data[i]; data[i] = data[j]; data[j] = t; }
	void push(node x)
	{
		sz++;
		data[sz] = x;
		int cur = sz;
		while (cur != 1 && data[cur >> 1].val > data[cur].val)
			swap(cur, cur >> 1), cur = cur >> 1;
	}

	void pop()
	{
		swap(sz, 1);
		sz--;

		int c = 1; int p = c << 1;
		while (p <= sz)
		{
			if (p + 1 <= sz && data[c].val > data[p + 1].val && data[p].val > data[p + 1].val)
				swap(c, p + 1), c = p + 1, p = c << 1;
			else if (data[c].val > data[p].val)
				swap(c, p), c = p, p = c << 1;
			else break;
		}
	}

	node top()
	{
		return data[1];
	}
};


int N, L;

int main()
{
	scanf("%d%d", &N, &L);
	
	heap h;
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		h.push({ x, i });
		while (true)
		{
			node top = h.top();
			if (i - L + 1 <= top.idx && top.idx <= i)
			{
				printf("%d ", top.val);
				break;
			}
			else h.pop();
		}
	}

	return 0;
}