#include <stdio.h>
#define MAXN 101

int V,W;
int a[1001], b[1001], d[1001];
int lower[MAXN]; // 최단거리
int upper[MAXN]; // 최장거리

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &V, &W);
		for (int i = 0; i < W; i++) scanf("%d%d%d", &a[i], &b[i], &d[i]);

		for (int i = 0; i < V; i++) lower[i] = 1e9, upper[i] = -1e9;

		bool flag1 = 1;
		int cnt1 = 0;
		lower[0] = 0;

		while (flag1)
		{
			cnt1++;
			flag1 = 0;
			for (int i = 0; i < W; i++)
			{
				if (lower[b[i]] > lower[a[i]] + d[i])
					lower[b[i]] = lower[a[i]] + d[i], flag1 = 1;
			}
			if (flag1 && cnt1 == V) break;
		}

		bool flag2 = 1;
		int cnt2 = 0;
		upper[0] = 0;
		while (flag2)
		{
			cnt2++;
			flag2 = 0;
			for (int i = 0; i < W; i++)
			{
				if (upper[b[i]] < upper[a[i]] + d[i])
					upper[b[i]] = upper[a[i]] + d[i], flag2 = 1;
			}
			if (flag2 && cnt2 == V) break;
		}

		if (lower[1] > 1e8) printf("UNREACHABLE\n");
		else
		{
			if (flag1 && cnt1 == V) printf("INFINITY ");
			else printf("%d ", lower[1]);

			if (flag2 && cnt2 == V) printf("INFINITY\n");
			else printf("%d\n", upper[1]);
		}
	}
	return 0;
}