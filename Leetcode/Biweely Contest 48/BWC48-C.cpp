class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		int ans = 0;
		sort(coins.begin(), coins.end());

		for (int i = 0; i < coins.size(); i++)
		{
			if (ans + 1 < coins[i])
				return ans + 1;
			else
				ans += coins[i];
		}
		return ans + 1;
	}
};