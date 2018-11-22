#include <stdio.h>
#define MAXN 1005
#define MAXQ 1000010
struct p
{
	int y, x;
};

struct queue
{
	p arr[MAXQ + 1];
	int tail, front, sz;

	void init()
	{
		tail = 0;
		front = 0;
		sz = 0;
	}

	void push(p x)
	{
		arr[tail] = x;
		tail = (tail + 1) % MAXQ;
		sz++;
	}

	void pop()
	{
		front = (front + 1) % MAXQ;
		sz--;
	}
	p top()
	{
		return arr[front];
	}
};

int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M;
int m[MAXN][MAXN];
int main()
{
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) scanf("%d", &m[i][j]);
	for (int i = 0; i <= N + 1; i++) m[i][0] = m[i][M + 1] = -1;
	for (int i = 0; i <= M + 1; i++) m[0][i] = m[N + 1][i] = -1;

	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
	{
		if (m[i][j] == 0)
		{
			bool flag = 1;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (m[ny][nx] != -1) flag = 0;
			}
			if (flag) return 0 & printf("-1\n");
		}
	}


	queue q; q.init();
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
		if (m[i][j] == 1) q.push({ i,j });

	int ans = 0;
	while (q.sz)
	{
		bool flag = 0;
		int size = q.sz;
		while (size--)
		{
			p t = q.top(); q.pop();
			for (int k = 0; k < 4; k++)
			{
				int ny = t.y + dy[k];
				int nx = t.x + dx[k];
				if (m[ny][nx] == 0)
				{
					flag = 1;
					m[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
		}
		if (flag) ans++;
	}
	printf("%d\n", ans);

	return 0;
}