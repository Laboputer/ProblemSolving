class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans |= nums[i];
		return ans * pow(2, nums.size()-1);
    }
};