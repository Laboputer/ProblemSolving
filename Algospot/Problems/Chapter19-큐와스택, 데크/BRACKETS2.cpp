#include <stdio.h>
#define MAXN 100005

struct stack
{
	char arr[MAXN+1];
	int cur = 0;
	int sz = 0;
	void push(int x)
	{
		arr[++cur] = x;
		sz++;
	}
	int top()
	{
		return arr[cur];
	}
	void pop()
	{
		cur--, sz--;
	}
};

char str[MAXN];
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		
		stack st;
		bool flag = 1;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') st.push(str[i]);
			else if (str[i] == ')' && st.sz != 0 && st.top() == '(') st.pop();
			else if (str[i] == '}' && st.sz != 0 && st.top() == '{') st.pop();
			else if (str[i] == ']' && st.sz != 0 && st.top() == '[') st.pop();
			else flag = 0;
		}
		if (st.sz != 0) flag = 0;

		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}