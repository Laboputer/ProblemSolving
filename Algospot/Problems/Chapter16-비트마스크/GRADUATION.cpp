#include <stdio.h>
#define MIN(a,b) (((a)<(b))  ? (a) : (b))
#define MAXN 13

int N, K, M, L;
int R[MAXN];
int Pre[MAXN];
int C[MAXN];
int Open[MAXN];

int d[1 << MAXN][MAXN]; // 현재 이수한 과목State이고, 시작되는 학기가 m 일때 최소 학기수
int F(int state, int cur)
{
	int& ref = d[state][cur];
	if (ref < 2e9) return ref;

	int c = 0;
	for (int i = 0; i < N; i++) if (state & (1 << i)) c++;
	if (c >= K) return ref = 0;
	if (cur == M) return ref = 2e8;

	ref = 2e8;
	ref = MIN(ref, F(state, cur + 1));
	int need = (~state) & ((1 << N) - 1); // 안들은 과목
	need &= Open[cur]; // 지금 가능한 과목
	for (int sub = need; sub; sub = ((sub - 1) & need))
	{
		int p = 0; for (int i = 0; i < N; i++) if (sub & (1 << i)) p |= Pre[i];
		int c = 0; for (int i = 0; i < N; i++) if (sub & (1 << i)) c++;

		if (((p & state) == p) && (c <= L)) ref = MIN(ref, F(state | sub, cur + 1) + 1);
	}
	return ref;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &N, &K, &M, &L);
		for (int i = 0; i < (1 << MAXN); i++) for (int j = 0; j < MAXN; j++) d[i][j] = 2e9;
		for (int i = 0; i < MAXN; i++) R[i] = Pre[i] = C[i] = Open[i] = 0;

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &R[i]);
			for (int j = 0, r; j < R[i]; j++) scanf("%d", &r), Pre[i] |= (1 << r);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &C[i]);
			for (int j = 0, c; j < C[i]; j++) scanf("%d", &c), Open[i] |= (1 << c);
		}

		if (F(0, 0) >= 2e8) printf("IMPOSSIBLE\n");
		else printf("%d\n", F(0, 0));
	}
	return 0;
}