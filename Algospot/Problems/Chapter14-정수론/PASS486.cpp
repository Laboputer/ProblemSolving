#include <stdio.h>
#define MAXN 10000005

int N, lo, hi;
int prime[MAXN]; // i의 가장 작은 소인수를 저장함.

int main()
{
	prime[1] = 0;
	for (int i = 2; i < MAXN; i++) prime[i] = i;
	for (int i = 4; i < MAXN; i += 2) prime[i] = 2;
	for (int i = 3; i*i < MAXN; i += 2)
	{
		if (prime[i] == i)
			for (int j = i * i; j < MAXN; j += i)
				if (prime[j] == j) prime[j] = i;
	}

	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &N, &lo, &hi);
		
		int ans = 0;
		for (int i = lo; i <= hi; i++)
		{
			int k = i, cnt = 1;
			while (prime[k] != 0)
			{
				int c = 0;
				int p = prime[k];
				while (prime[k] != 0 && p == prime[k]) c++, k /= prime[k];
				cnt *= (c + 1);
			}
			if (N == cnt) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}

// 시간초과
// Time Complexity : O (N*sqrtN)

//#include <stdio.h>
//#define MAXN 10000005
//
//int N, lo, hi;
//int main()
//{
//	int t; scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d%d%d", &N, &lo, &hi);
//
//		int ans = 0;
//		for (int i = lo; i <= hi; i++)
//		{
//			int cnt = 0;
//			for (int k = 1; k*k <= i; k++)
//			{
//				if (i % k == 0)
//				{
//					if (k*k == i) cnt++;
//					else cnt += 2;
//				}
//			}
//			if (N == cnt) ans++;
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}