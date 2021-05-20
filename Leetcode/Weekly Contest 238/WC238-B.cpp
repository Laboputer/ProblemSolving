class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		long long res = 0, sum = 0, s = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			while (s < i && sum + k < nums[i] * (i - s + 1))
				sum -= nums[s++];
			res = max(res, i - s + 1);
		}
		return res;
	}
};