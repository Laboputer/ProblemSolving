#include <stdio.h>
#define MAXN 22

int N;
int map[MAXN][MAXN];
int q[MAXN*MAXN][4];
int qcnt;

int main()
{
	int t; scanf("%d", &t);
	printf("%d\n", t);
	while (t--)
	{
		scanf("%d", &N);
		printf("%d\n", N);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
		qcnt = 0;

		for (int i = 0; i < N; i++)
		{
			int j = 0;
			while (1)
			{
				while (map[i][j] == 0 && j < N) j++;
				if (j == N) break;
				
				int r = j - 1;
				int sum = 0;
				while (map[i][j] != 0 && j < N) sum += map[i][j], j++;
				
				q[qcnt][0] = i + 1;
				q[qcnt][1] = r + 1;
				q[qcnt][2] = 0;
				q[qcnt][3] = sum;
				qcnt++;
			}
		}

		for (int i = 0; i < N-1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 0 && map[i + 1][j] != 0)
				{
					int k = i;
					while (map[k][j] == 0 && k < N) k++;
					if (k == N) break;

					int r = k;
					int sum = 0;
					while (map[k][j] != 0 && k < N) sum += map[k][j], k++;

					q[qcnt][0] = r;
					q[qcnt][1] = j + 1;
					q[qcnt][2] = 1;
					q[qcnt][3] = sum;
					qcnt++;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) printf("%d ", map[i][j] ? 1 : 0);
			printf("\n");
		}
		printf("%d\n", qcnt);
		for (int i = 0; i < qcnt; i++) printf("%d %d %d %d\n", q[i][0], q[i][1], q[i][2], q[i][3]);
		
	}
	return 0;
}