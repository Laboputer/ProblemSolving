#include <stdio.h>
#define MAXN 55

struct STK
{
	int data[MAXN];
	int sz;
	int top;

	STK()
	{
		sz = 0, top = -1;
	}

	void PUSH(int x)
	{
		top++, sz++;
		data[top] = x;
	}

	int TOP()
	{
		return data[top];
	}

	void POP()
	{
		top--, sz--;
	}
};

char str[MAXN];
int main()
{
	int t; scanf("%d", &t);

	while (t--)
	{
		scanf("%s", str);

		bool flag = 1;
		STK st;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '(') st.PUSH(1);
			else if (st.sz) st.POP();
			else flag = 0;
		}
		if (st.sz) flag = 0;

		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}