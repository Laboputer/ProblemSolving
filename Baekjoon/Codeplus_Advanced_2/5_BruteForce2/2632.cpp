#include <stdio.h>
#define MAXN 1000005

int X;
int N, M;
int a[1000], b[1000];
int A[MAXN];
int acnt;
int B[MAXN];
int bcnt;

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
	scanf("%d", &X);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < M; i++) scanf("%d", &b[i]);

	int sum = 0;
	for (int i = 0; i < N; i++) sum += a[i];
	A[acnt++] = sum;
	for (int i = 0; i < N; i++)
	{
		int val = a[i];
		A[acnt++] = val;
		for (int j = 1; j < N-1; j++)
		{
			int k = (i + j) % N;
			val += a[k];
			A[acnt++] = val;
		}
	}

	sum = 0;
	for (int i = 0; i < M; i++) sum += b[i];
	B[bcnt++] = sum;
	for (int i = 0; i < M; i++)
	{
		int val = b[i];
		B[bcnt++] = val;
		for (int j = 1; j < M-1; j++)
		{
			int k = (i + j) % M;
			val += b[k];
			B[bcnt++] = val;
		}
	}

	SORT(A, 0, acnt - 1);
	SORT(B, 0, bcnt - 1);

	int ans = 0;
	for (int i = 0; i < acnt; i++) if (A[i] == X) ans++;
	for (int i = 0; i < bcnt; i++) if (B[i] == X) ans++;

	int l = 0, r = bcnt - 1;
	while (l < acnt && r >= 0)
	{
		int x = A[l] + B[r];

		if (x == X)
		{
			int c1 = 1, c2 = 1;
			while (l + 1 < acnt && A[l] == A[l + 1]) c1++, l++;
			while (r > 0 && B[r] == B[r - 1]) c2++, r--;
			ans += c1 * c2;
			l++;
		}
		else if (x > X) r--;
		else l++;
	}

	printf("%d\n", ans);

	return 0;
}