#include <stdio.h>
#define MAXN 105
#define MAXQ 1000010
struct p
{
	int z, y, x;
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

int dx[6] = { 1, -1, 0 ,0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int N, M, H;
int m[MAXN][MAXN][MAXN];
int main()
{
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 0; i <= H + 1; i++) for (int j = 0; j <= N + 1; j++) for (int k = 0; k <= M + 1; k++) m[i][j][k] = -1;
	for (int i = 1; i <= H; i++) for (int j = 1; j <= N; j++) for (int k = 1; k <= M; k++) scanf("%d", &m[i][j][k]);

	for (int i = 1; i <= H; i++) for (int j = 1; j <= N; j++) for (int k = 1; k <= M; k++)
	{
		if (m[i][j][k] == 0)
		{
			bool flag = 1;
			for (int z = 0; z < 6; z++)
			{
				int nz = i + dz[z];
				int ny = j + dy[z];
				int nx = k + dx[z];
				if (m[nz][ny][nx] != -1) flag = 0;
			}
			if (flag) return 0 & printf("-1\n");
		}
	}

	queue q; q.init();
	for (int i = 1; i <= H; i++) for (int j = 1; j <= N; j++) for (int k = 1; k <= M; k++)
		if (m[i][j][k] == 1) q.push({ i, j, k });

	int ans = 0;
	while (q.sz)
	{
		bool flag = 0;
		int size = q.sz;
		while (size--)
		{
			p t = q.top(); q.pop();
			for (int k = 0; k < 6; k++)
			{
				int nz = t.z + dz[k];
				int ny = t.y + dy[k];
				int nx = t.x + dx[k];
				if (m[nz][ny][nx] == 0)
				{
					flag = 1;
					m[nz][ny][nx] = 1;
					q.push({ nz, ny, nx });
				}
			}
		}
		if (flag) ans++;
	}
	printf("%d\n", ans);

	return 0;
}