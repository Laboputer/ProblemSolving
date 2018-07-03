#include <stdio.h>
#define MAXN 25

int H, W;
char map[MAXN][MAXN];
int ans = 0;
void F(int h, int w)
{
	if (h == H - 1 && w == W - 1)
	{
		if (map[h][w] == '#') ans++;
		return;
	}


	if (map[h][w] == '#')
	{
		F(w + 1 == W ? h + 1 : h, w + 1 == W ? 0 : w + 1);
		return;
	}

	if (w - 1 >= 0 && h + 1 < H)
	{
		if (map[h + 1][w - 1] == '.' && map[h + 1][w] == '.')
		{
			map[h][w] = map[h + 1][w - 1] = map[h + 1][w] = '#';
			F(w + 1 == W ? h + 1 : h, w + 1 == W ? 0 : w + 1);
			map[h][w] = map[h + 1][w - 1] = map[h + 1][w] = '.';
		}
	}
	if (h + 1 < H && w + 1 < W)
	{
		if (map[h + 1][w] == '.' && map[h][w + 1] == '.')
		{
			map[h][w] = map[h + 1][w] = map[h][w + 1] = '#';
			F(w + 1 == W ? h + 1 : h, w + 1 == W ? 0 : w + 1);
			map[h][w] = map[h + 1][w] = map[h][w + 1] = '.';
		}

		if (map[h + 1][w] == '.' && map[h + 1][w + 1] == '.')
		{
			map[h][w] = map[h + 1][w] = map[h + 1][w + 1] = '#';
			F(w + 1 == W ? h + 1 : h, w + 1 == W ? 0 : w + 1);
			map[h][w] = map[h + 1][w] = map[h + 1][w + 1] = '.';
		}

		if (map[h][w + 1] == '.' && map[h + 1][w + 1] == '.')
		{
			map[h][w] = map[h][w + 1] = map[h + 1][w + 1] = '#';
			F(w + 1 == W ? h + 1 : h, w + 1 == W ? 0 : w + 1);
			map[h][w] = map[h][w + 1] = map[h + 1][w + 1] = '.';
		}
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &H, &W);
		for (int i = 0; i < H; i++) scanf("%s", map[i]);

		ans = 0;
		F(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}