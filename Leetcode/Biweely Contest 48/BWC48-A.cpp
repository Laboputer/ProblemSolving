class Solution {
public:
	int secondHighest(string s) {
		int cnt[10] = { 0, };
		for (int i = 0; i < s.size(); i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
				cnt[s[i] - '0']++;
		}

		int exist = 1;
		for (int i = 9; i >= 0; i--)
		{
			if (cnt[i] != 0)
			{
				if (exist > 0) exist--;
				else return i;
			}
		}
		return -1;
	}
};