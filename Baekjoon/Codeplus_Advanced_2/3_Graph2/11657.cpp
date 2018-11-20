#include <stdio.h>
#define MAXN 505


int N, M;
int s[6000], e[6000], r[6000];
long long d[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d%d%d", &s[i], &e[i], &r[i]);

	for (int i = 1; i <= N; i++) d[i] = 2e9;
	d[1] = 0;

	int cnt = 0;
	bool flag = 1;
	while (flag)
	{
		if (cnt == N) break;

		flag = 0;
		for (int i = 0; i < M; i++)
		{
			if (d[e[i]] > d[s[i]] + r[i])
			{
				d[e[i]] = d[s[i]] + r[i];
				flag = 1;
			}
		}
		if (flag) cnt++;
	}

	if (cnt == N) printf("-1\n");
	else for (int i = 2; i <= N; i++) printf("%lld\n", (d[i] >= 1e9) ? -1 : d[i]);

	return 0;
}