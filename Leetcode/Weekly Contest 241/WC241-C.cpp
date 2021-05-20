class FindSumPairs {
public:
	vector<int> n1;
	vector<int> n2;
	unordered_map<int, int> m2;
	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		n1 = nums1;
		n2 = nums2;
		for (int i = 0; i < n2.size(); i++)
			m2[n2[i]]++;
	}

	void add(int index, int val) {
		m2[n2[index]]--;
		n2[index] += val;
		m2[n2[index]]++;
	}

	int count(int tot) {
		int ans = 0;
		for (int i = 0; i < n1.size(); i++)
		{
			int target = tot - n1[i];
			ans += m2[target];
		}
		return ans;
	}
};