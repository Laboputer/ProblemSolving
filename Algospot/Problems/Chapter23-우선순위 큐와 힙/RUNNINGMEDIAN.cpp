#include <stdio.h>
#define MAXN 200005
#define MOD 20090711ll

struct minheap
{
	int arr[MAXN];
	int sz = 0;

	void swap(int i, int j) { int t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
	void push(int x)
	{
		sz++;
		arr[sz] = x;
		int cur = sz;
		int p = cur / 2;
		while (cur != 1 && arr[cur] < arr[p]) swap(cur, p), cur /= 2, p /= 2;
	}

	void pop()
	{
		swap(1, sz);
		sz--;
		int cur = 1;
		int l, r;
		while (cur * 2 <= sz)
		{
			l = cur * 2;
			r = cur * 2 + 1;
			if (r <= sz && arr[r] < arr[l] && arr[r] < arr[cur]) swap(cur, r), cur = r;
			else if (arr[l] < arr[cur]) swap(cur, l), cur = l;
			else break;
		}
	}

	int top()
	{
		return arr[1];
	}
};


struct maxheap
{
	int arr[MAXN];
	int sz = 0;

	void swap(int i, int j) { int t = arr[i]; arr[i] = arr[j]; arr[j] = t; }
	void push(int x)
	{
		sz++;
		arr[sz] = x;
		int cur = sz;
		int p = cur / 2;
		while (cur != 1 && arr[cur] > arr[p]) swap(cur, p), cur /= 2, p /= 2;
	}

	void pop()
	{
		swap(1, sz);
		sz--;
		int cur = 1;
		int l, r;
		while (cur * 2 <= sz)
		{
			l = cur * 2;
			r = cur * 2 + 1;
			if (r <= sz && arr[r] > arr[l] && arr[r] > arr[cur]) swap(cur, r), cur = r;
			else if (arr[l] > arr[cur]) swap(cur, l), cur = l;
			else break;
		}
	}

	int top()
	{
		return arr[1];
	}
};


minheap minh;
maxheap maxh;

int N; long long a, b;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%lld%lld", &N, &a, &b);
		minh.sz = 0;
		maxh.sz = 0;

		long long p = 1983;
		long long ans = 0;
		for (int i = 0; i < N; i++)
		{
			minh.push(p);

			while (maxh.sz != 0 && maxh.top() > minh.top())
			{
				int x = maxh.top(), y = minh.top();
				maxh.pop(), minh.pop();
				maxh.push(y); minh.push(x);
			}

			while (maxh.sz < minh.sz) {
				maxh.push(minh.top()); 
				minh.pop();
			}
			ans = (ans + (long long)maxh.top()) % MOD;
			p = (p * a + b) % MOD;
		}
		printf("%d\n", ans);
	}

	return 0;
}