#include <stdio.h>
#define MAXN 2005
#define MAXM 100005

struct dist
{
	int a, b, r;
};

int N, M, T;
int S, G, H;

dist V[MAXM];
int vcnt;

int Sdis[MAXN], Gdis[MAXN], Hdis[MAXN];
bool Check[MAXN];

void SetSPFA(int* arr, int start)
{
	arr[start] = 0;
	bool flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < vcnt; i++)
		{
			if (arr[V[i].b] > arr[V[i].a] + V[i].r)
			{
				arr[V[i].b] = arr[V[i].a] + V[i].r;
				flag = 1;
			}
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int a, b, d, x, i;
		vcnt = 0;

		scanf("%d%d%d", &N, &M, &T);
		scanf("%d%d%d", &S, &G, &H);
		for (i = 1; i <= N; i++) Sdis[i] = Gdis[i] = Hdis[i] = 1e9, Check[i] = 0;
		Sdis[S] = Gdis[G] = Hdis[H] = 0;

		int gh = 0;
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &d);
			V[vcnt++] = { a,b,d };
			V[vcnt++] = { b,a,d };
			if ((a == G && b == H) || (b == G && a == H))
				gh = d;
		}

		SetSPFA(Sdis, S);
		SetSPFA(Gdis, G);
		SetSPFA(Hdis, H);

		for (i = 0; i < T; i++)
		{
			scanf("%d", &x);
			Check[x] = 1;
		}

		for (int i = 1; i <= N; i++)
		{
			if (!Check[i]) continue;
			if ((Sdis[G] + gh + Hdis[i] == Sdis[i]) || (Sdis[H] + gh + Gdis[i] == Sdis[i]))
				printf("%d ", i);
			// 여기서 최단 경로를 gh를 거치느냐로 확인하였는데.. 이 방법 말고도
			// 모든 가중치를 2배 증가 시키고 gh를 1 감소시켰을때 이 간선을 통해서 더 작아지는 지만 확인하는 방법도 있다.
		}
		printf("\n");
	}
	return 0;
}