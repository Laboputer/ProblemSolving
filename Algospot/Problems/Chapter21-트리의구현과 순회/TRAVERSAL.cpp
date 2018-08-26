#include <stdio.h>
#define MAXN 105

int N;
int pre[MAXN];
int in[MAXN];

int cur = 0;
void post(int l, int r)
{
	if (l > r) return;

	for (int i = l; i <= r; i++)
	{
		if (pre[cur] == in[i])
		{
			int x = pre[cur++];
			post(l, i);
			post(i + 1, r);
			printf("%d ", x);
			break;
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &pre[i]);
		for (int i = 0; i < N; i++) scanf("%d", &in[i]);
		cur = 0;
		post(0, N - 1);
		printf("\n");
	}
	return 0;
}