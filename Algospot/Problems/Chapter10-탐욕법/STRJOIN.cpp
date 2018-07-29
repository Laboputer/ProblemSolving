#include <stdio.h>
#define MAXN 105

struct heap
{
	int arr[MAXN];
	int sz = 0;

	void swap(int i, int j)
	{
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	void push(int x)
	{
		sz++;
		arr[sz] = x;

		int c = sz;
		int p = c / 2;
		while (c != 1 && arr[p] > arr[c]) 
			swap(p, c), p>>=1, c >>= 1;
	}

	void pop()
	{
		arr[1] = arr[sz];
		sz--;

		int c = 1;
		int l = c * 2;
		int r = c * 2 + 1;
		while (l <= sz)
		{
			if (r <= sz && arr[l] > arr[r] && arr[c] > arr[r]) swap(c, r), c = r;
			else if (l <= sz && arr[c] > arr[l]) swap(c, l), c = l;
			else break;
			l = c * 2;
			r = c * 2 + 1;
		}
	}

	int top()
	{
		return arr[1];
	}

};

int N;
int a[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &a[i]);

		heap pq;
		for (int i = 0; i < N; i++) pq.push(a[i]);

		int ans = 0;
		while (pq.sz >= 2)
		{
			int n1 = pq.top(); pq.pop();
			int n2 = pq.top(); pq.pop();
			ans += n1 + n2;
			pq.push(n1 + n2);

		}
		
		printf("%d\n", ans);	
	}
	return 0;
}