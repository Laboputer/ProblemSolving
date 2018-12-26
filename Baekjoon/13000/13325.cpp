#include <stdio.h>

int K;
int sum[1 << 20 + 1];
int main()
{
	long long alledge = 0;

	scanf("%d", &K);
	int x;
	for (int h = 1; h <= K; h++)
	{
		int edges = 1 << h;
		int len = 1 << (K - h);
		for (int i = 0; i < edges; i++)
		{
			scanf("%d", &x);
			alledge += x;
			sum[i*len] += x;
			sum[i*len + len] -= x;
		}
	}

	int len = 1 << K;
	for (int i = 1; i < len; i++)
		sum[i] += sum[i - 1];

	for (int i = 0, next = 1; i < K; i++, next <<= 1)
	{
		for (int j = 0; j < len; j += next * 2)
		{
			int abs = (sum[j] < sum[j + next]) ? (sum[j + next] - sum[j]) : (sum[j] - sum[j + next]);
			alledge += abs;
			if (sum[j] < sum[j + next]) sum[j] += abs;
			else sum[j + next] += abs;
		}
	}

	printf("%lld\n", alledge);
	
	return 0;
}