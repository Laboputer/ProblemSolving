class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int res = nums[0], sum = nums[0];
		for (int s = 1; s < nums.size(); s++)
		{
			if (nums[s - 1] >= nums[s])
				sum = nums[s];
			else
				sum += nums[s];
			res = max(res, sum);
		}
		return res;
	}
};