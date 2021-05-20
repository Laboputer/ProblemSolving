class Solution {
public:
	int minSwaps(string s) {
		int n1 = 0, n2 = 0;
		int ans = 1e9;
		for (int i = 0; i < s.size(); i += 2) if (s[i] == '0') n1++;
		for (int i = 1; i < s.size(); i += 2) if (s[i] == '1') n2++;
		if (n1 == n2) ans = min(ans, n1);

		n1 = 0, n2 = 0;
		for (int i = 0; i < s.size(); i += 2) if (s[i] == '1') n1++;
		for (int i = 1; i < s.size(); i += 2) if (s[i] == '0') n2++;
		if (n1 == n2) ans = min(ans, n1);
		return ans == 1e9 ? -1 : ans;
	}
};