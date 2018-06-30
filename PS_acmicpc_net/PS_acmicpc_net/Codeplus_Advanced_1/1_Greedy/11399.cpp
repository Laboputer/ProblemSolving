#include <stdio.h>
#define MAXN 1005

int a[MAXN];
int N;

void Swap(int i, int j) { int tmp = a[i]; a[i] = a[j]; a[j] = tmp; }
void Qsort(int l, int r)
{
	if (l >= r) return;

	int m = (l + r) / 2;
	if (l + 2 <= r)
	{
		if (a[m] < a[l]) Swap(m, l);
		if (a[m] < a[r]) Swap(m, r);
		else if (a[r] < a[l]) Swap(l, r);
	}

	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (a[i] < a[r])
		{
			j++; Swap(i, j);
		}
	}
	j++;
	Swap(j, r);
	Qsort(l, j - 1);
	Qsort(j + 1, r);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	Qsort(0, N - 1);
	int sum = 0;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		sum += a[i];
		ans += sum;
	}

	printf("%d", ans);

	return 0;
}