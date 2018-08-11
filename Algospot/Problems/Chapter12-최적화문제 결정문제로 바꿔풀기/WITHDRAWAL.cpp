#include <stdio.h>
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define MAXN 1005

int N, K;
double R[MAXN], C[MAXN];
double tmp[MAXN];
void SORT(double* a, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) >> 1;

	SORT(a, l, m);
	SORT(a, m + 1, r);
	int p1 = l, p2 = m + 1, p3 = l;
	while (p1 <= m && p2 <= r) tmp[p3++] = (a[p1] > a[p2]) ? a[p1++] : a[p2++];
	while (p1 <= m) tmp[p3++] = a[p1++];
	while (p2 <= r) tmp[p3++] = a[p2++];
	for (int i = l; i <= r; i++) a[i] = tmp[i];
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) scanf("%lf%lf", &R[i], &C[i]);

		double v[MAXN];
		double l = 0.0, r = 1.0;
		double ans = 0;
		for (int i = 0; i < 50 && l < r; i++)
		{
			double x = (l + r) / 2.0;
			for (int i = 0; i < N; i++) v[i] = x * C[i] - R[i];
			SORT(v, 0, N - 1); // sum(xc[i] - r[i]) >=0를 k개이상 선택할때 가능한가.
			double val = 0;
			for (int i = 0; i < K; i++) val += v[i];
			for (int i = K; i < N && v[i] > 0; i++) val += v[i];
			
			if (val > 1e-9) ans = x, r = x;
			else l = x;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}