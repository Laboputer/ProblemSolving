#include <stdio.h>

int N;
int val[11];
int type[4];
int op[11];

int mn = 2e9, mx = -2e9;

int Getval(int n1, int n2, int type)
{
	switch (type)
	{
	case 0:
		return n1 + n2;
	case 1:
		return n1 - n2;
	case 2:
		return n1 * n2;
	case 3:
		return n1 / n2;
	}
}

void DFS(int n)
{
	if (n == N - 1)
	{
		int ans = Getval(val[0], val[1], op[0]);
		for (int i = 1; i < n; i++) ans = Getval(ans, val[i + 1], op[i]);
		if (mn > ans) mn = ans;
		if (mx < ans) mx = ans;
	}

	for (int i = 0; i < 4; i++)
	{
		if (type[i] == 0) continue;

		op[n] = i;
		type[i]--;
		DFS(n + 1);
		type[i]++;
	}
}



int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &val[i]);
	for (int i = 0; i < 4; i++) scanf("%d", &type[i]);

	DFS(0);
	printf("%d\n%d\n", mx, mn);

	return 0;
}