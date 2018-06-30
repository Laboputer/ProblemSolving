#include <stdio.h>

bool P[4000005];
int prime[4000000];
int cnt = 0;
int main()
{
	for (int i = 2; i <= 4000000; i++) P[i] = 1;
	for (int i = 4; i <= 4000000; i += 2) P[i] = 0;
	for (int i = 3; i <= 4000000; i+=2)
		if (P[i]) for (int j = i + i; j <= 4000000; j += i) P[j] = 0;

	prime[0] = 2; cnt++;
	for (int i = 3; i <= 4000000; i += 2) if (P[i]) prime[cnt++] = i;

	int N; scanf("%d", &N);
	int ans = 0;
	int sum = 0, l = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += prime[i];
		while (sum >= N)
		{
			if (sum == N) ans++;
			sum -= prime[l++];
		}
	}

	printf("%d\n", ans);

	return 0;
}