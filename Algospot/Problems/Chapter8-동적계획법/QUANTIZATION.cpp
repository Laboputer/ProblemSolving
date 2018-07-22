#include <stdio.h>
#define MAXN 105
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

int N, S;
int a[MAXN];
int tmp[MAXN];
int d[MAXN][11];

void SORT(int* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SORT(arr, l, m);
	SORT(arr, m + 1, r);
	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	while (p1 <= m) tmp[p3++] = arr[p1++];
	while (p2 <= r) tmp[p3++] = arr[p2++];
	for (int i = l; i <= r; i++) arr[i] = tmp[i];
}

int quan(int l, int r)
{
	int sum = 0; for (int i = l; i <= r; i++) sum += a[i];
	int len = r - l + 1;
	int q = sum / len;
	if (((sum%len) * 10) / (len * 5)) q++;
	
	int res = 0;
	for (int i = l; i <= r; i++) res += (q - a[i])*(q - a[i]);
	return res;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &S);
		for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
		SORT(a, 1, N);

		for (int i = 1; i <= N; i++) d[i][1] = quan(1, i);
		for (int i = 1; i <= N; i++) for (int j = 2; j <= S; j++)
		{
			if (i <= j) d[i][j] = 0;
			else
			{
				d[i][j] = 2e9;
				for (int k = 1; k < i; k++) d[i][j] = MIN(d[i][j], d[i - k][j - 1] + quan(i - k + 1, i));
			}
		}
		printf("%d\n", d[N][S]);
	}
	return 0;
}