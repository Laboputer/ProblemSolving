class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int res = 0, v = 0, o = 0;
		char order[] = { 'a', 'e', 'i', 'o', 'u', 'u' };
		for (int i = 0; i < word.size(); i++)
		{
			if (v == 0 && word[i] != 'a') continue;
			
			if (word[i] == order[o]) v++;
			else if (word[i] == order[o + 1]) v++, o++;
			else if (word[i] == 'a') v = 1, o = 0;
			else v = 0, o = 0;

			if (order[o] == 'u') res = max(res, v);
		}
		return res;
	}
};