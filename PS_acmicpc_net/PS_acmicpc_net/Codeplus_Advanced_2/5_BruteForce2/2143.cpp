#include <stdio.h>
#define MAXN 1000005

int T;
int N, M;
int A[1000], B[1000];
int a[MAXN], b[MAXN];
int acnt, bcnt;

int tmp[MAXN];
void SORT(int* arr, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;
	SORT(arr, l, m);
	SORT(arr, m + 1, r);
	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (arr[p1] < arr[p2]) ? arr[p1++] : arr[p2++];
	while (p1 <= m) tmp[p3++] = arr[p1++];
	while (p2 <= r) tmp[p3++] = arr[p2++];
	for (int i = l; i <= r; i++) arr[i] = tmp[i];
}

int main()
{
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) scanf("%d", &B[i]);

	for (int i = 0; i < N; i++)
	{
		int sum = A[i]; a[acnt++] = sum;
		for (int j = i + 1; j < N; j++) sum += A[j], a[acnt++] = sum;
	}
	for (int i = 0; i < M; i++)
	{
		int sum = B[i]; b[bcnt++] = sum;
		for (int j = i + 1; j < M; j++) sum += B[j], b[bcnt++] = sum;
	}

	SORT(a, 0, acnt - 1);
	SORT(b, 0, bcnt - 1);
	
	long long ans = 0;
	int l = 0, r = bcnt - 1;
	while (l < acnt && r >= 0)
	{
		int sum = a[l] + b[r];
		if (sum == T)
		{
			int c1 = 1, c2 = 1;
			while (l < acnt - 1 && a[l] == a[l + 1]) l++, c1++;
			while (r > 0 && b[r] == b[r - 1]) r--, c2++;
			ans += (long long)c1 * (long long)c2;
			l++;
		}
		else if (sum < T) l++;
		else r--;
	}
	printf("%lld\n", ans);
	return 0;
}
