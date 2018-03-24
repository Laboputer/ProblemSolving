#include <stdio.h>
#define MIN(a,b) ((a<b) ? (a) : (b))

int N, M;
int v[10];

bool P(int x)
{
	if (x == 0) return v[0];
	while (x)
	{
		if (!v[x % 10]) return 0;
		x /= 10;
	}
	return 1;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < 10; i++) v[i] = 1;
	for (int i = 0, x; i < M; i++) scanf("%d", &x), v[x] = 0;

	int ans = 2e9;
	if (N < 100) ans = MIN(ans, 100 - N);
	else if (N >= 100) ans = MIN(ans, N - 100);

	int cnt1 = 1, cnt2 = 1;

	for (int i = N; i >= 0; i--)
		if (P(i)) {
			int c = 1;
			for (int k = 1; i / c != 0; k++, c*=10) cnt1 = k;
			ans = MIN(ans, N - i + cnt1);
			break;
		}

	for (int i = N; i <= 999999; i++)
		if (P(i)) {
			int c = 1;
			for (int k = 1; i / c != 0; k++, c*=10) cnt2 = k;
			ans = MIN(ans, i - N + cnt2);
			break;
		}

	printf("%d\n", ans);
	return 0;
}
