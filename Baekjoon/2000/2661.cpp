#include <stdio.h>
#define MAXN 85

int N;
char state[MAXN];
char ans[MAXN];
bool Find = false;

bool ok(int n)
{
	int half = n / 2;
	for (int x = 1; x <= half; x++)
	{
		int cnt = n - x;
		bool same = 1;
		for (int k = 0; k < x; k++)
		{
			if (state[cnt - k] != state[n - k])
				same = 0;
		}
		if (same) return false;
	}
	return true;
}

void DFS(int n)
{
	if (Find) return;
	if (N + 1 == n)
	{
		Find = 1;
		for (int i = 1; i <= N; i++) ans[i - 1] = state[i];
		return;
	}

	for (int i = '1'; i <= '3'; i++)
	{
		state[n] = i;
		if (ok(n)) DFS(n + 1);
	}
}

int main()
{
	scanf("%d", &N);
	DFS(1);
	printf("%s", ans);

	return 0;
}