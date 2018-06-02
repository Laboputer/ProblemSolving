#include <stdio.h>
#define MAXN 25

int M;
int main()
{
	scanf("%d", &M);
	int set = 0;
	char cmd[10]; int x;
	while (M--)
	{
		scanf("%s %d", cmd, &x);
		if (cmd[0] == 'a' && cmd[1] == 'd') set |= (1 << x);
		else if (cmd[0] == 'r' && cmd[1] == 'e') set &= ~(1 << x);
		else if (cmd[0] == 'c' && cmd[1] == 'h') printf("%d\n", (set & (1 << x) ? 1 : 0));
		else if (cmd[0] == 't' && cmd[1] == 'o') { 
			if (set & (1 << x)) set &= ~(1 << x);
			else set |= (1 << x);
		}
		else if (cmd[0] == 'a' && cmd[1] == 'l') set = (1 << MAXN) - 1;
		else if (cmd[0] == 'e' && cmd[1] == 'm') set = 0;
	}
	return 0;
}