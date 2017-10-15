#include <stdio.h>
#define MAXN 100005

int inorder[MAXN];
int postorder[MAXN];
int N;

void Pre(int s1, int e1, int s2, int e2)
{
	if (s1 > e1) return;

	for (int i = s1; i <= e1; i++)
	{
		if (postorder[e2] != inorder[i]) continue;

		printf("%d ", inorder[i]);
		Pre(s1, i - 1, s2, s2 + (i - s1) - 1);
		Pre(i + 1, e1, s2 + (i - s1), e2 - 1);
		break;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);
	Pre(0, N - 1, 0, N - 1);
	return 0;
}