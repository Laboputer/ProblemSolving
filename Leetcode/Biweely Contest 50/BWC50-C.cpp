class Solution {
public:
	vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
		int xorsum = 0;
		for (int i = 0; i < nums.size(); i++) 
			xorsum ^= nums[i];
		
		int bits = (1 << maximumBit)-1;

		vector<int> res;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			res.push_back((~(xorsum & bits)) & bits);
			xorsum ^= nums[i];
		}
        return res;
	}
};