class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		int sxor = 0;
		for (int i = 0; i < arr2.size(); i++)
			sxor ^= arr2[i];

		int res = 0;
		for (int i = 0; i < arr1.size(); i++)
			res ^= (arr1[i] & sxor);
		return res;
	}
};