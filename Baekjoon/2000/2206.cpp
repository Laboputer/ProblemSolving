#include <stdio.h>
#define MAXN 1005
#define MAXQ 10000005

inline int min(int x, int y)
{
	if (x < y) return x;
	else return y;
}

struct node
{
	int y, x;
};

struct queue
{
	node arr[MAXQ + 1];
	int sz, front, tail;

	void init()
	{
		sz = 0;
		front = 0;
		tail = 0;
	}

	void push(node x)
	{
		arr[tail] = x;
		tail = (tail + 1) % MAXQ;
		sz++;
	}

	node top()
	{
		return arr[front];
	}

	void pop()
	{
		front = (front + 1) % MAXQ;
		sz--;
	}
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M;
char str[MAXN][MAXN];
int m1[MAXN][MAXN];
int m2[MAXN][MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", &str[i]);

	for (int i = 0; i <= N + 1; i++) m1[i][0] = m1[i][M + 1] = m2[i][0] = m2[i][M + 1] = 1e9;
	for (int j = 0; j <= M + 1; j++) m1[0][j] = m1[N + 1][j] = m2[0][j] = m2[N + 1][j] = 1e9;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		if (str[i][j] == '1') m1[i + 1][j + 1] = m2[i + 1][j + 1] = 1e9;

	queue q;
	q.init();
	q.push({ 1, 1 });
	m1[1][1] = 1;

	int cnt = 1;
	while (q.sz)
	{
		int size = q.sz;
		cnt++;
		while (size--)
		{
			node top = q.top(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = top.y + dy[i];
				int nx = top.x + dx[i];
				if (m1[ny][nx] == 0)
				{
					q.push({ ny, nx });
					m1[ny][nx] = cnt;
				}
			}
		}
	}

	q.init();
	q.push({ N,M });
	m2[N][M] = 1;
	cnt = 1;
	while (q.sz)
	{
		int size = q.sz;
		cnt++;
		while (size--)
		{
			node top = q.top(); q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = top.y + dy[i];
				int nx = top.x + dx[i];
				if (m2[ny][nx] == 0)
				{
					q.push({ ny, nx });
					m2[ny][nx] = cnt;
				}
			}
		}
	}

	int ans = 1e9;
	for (int y = 1; y <= N; y++) for (int x = 1; x <= M; x++)
	{
		if (m1[y][x] != 0 && m2[y][x] != 0)
			ans = min(ans, m1[y][x] + m2[y][x] - 1); // 벽 부수지않고 이동가능

		if (m1[y][x] == 1e9)
		{
			int c1 = 1e9, c2 = 1e9;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (m1[ny][nx] != 0) c1 = min(c1, m1[ny][nx]);
				if (m2[ny][nx] != 0) c2 = min(c2, m2[ny][nx]);
			}
			ans = min(ans, c1 + c2 + 1);
		}
	}

	printf("%d", (ans == 1e9) ? -1 : ans);
	return 0;
}