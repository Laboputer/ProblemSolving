#include <map>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
	int reductionOperations(vector<int>& nums) {
		int cnt[50001] = { 0, };
		for (int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
		vector<int> n;
		for (int i = 50000; i >= 1; i--) n.push_back(i);

		int sum = 0;
		int ans = 0;
		for (int k = 0; k < n.size() - 1; k++)
		{
			sum += cnt[n[k]];
			ans += sum;
		}
		return ans;
	}
};
int main()
{
	vector<int> v1 = { 5, 1, 3 };
	vector<int> v2 = { 2,3,4,1,24 };

	Solution().reductionOperations(v1);

	return 0;
}