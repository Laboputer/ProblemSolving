#include <map>
using namespace std;

#define MAXLEN 15
class Solution {
public:
	struct trie
	{
		trie* node[2] = {NULL, NULL};
		int cnt = 0;

		void insert(trie* root, int x)
		{
			trie* cur = root;
			for(int i=MAXLEN; i>=0; i--)
			{
				int next = (x >> i) & 1;
				if(cur->node[next] == NULL)
					cur->node[next] = new trie();
				cur->node[next]->cnt++;
				cur = cur->node[next];
			}	
		}
	};

	int countUnderK(trie* root, int num, int k)
	{
		int res = 0;
		trie* cur = root;
		for(int i=MAXLEN; i>=0; i--)
		{
			if((k >> i) & 1)
			{
				int target = ((k >> i) & 0) ^ ((num >> i) & 1);
				if(cur->node[target] != NULL)
					res += cur->node[target]->cnt; 
			}
			int next = ((k^num) >> i) & 1;
			if (cur->node[next] == NULL)
				break;
			cur = cur->node[next];
		}
		return res;
	}

    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
		trie* root = new trie();
		for(int i=0; i<nums.size(); i++)
		{
			res += countUnderK(root, nums[i], high+1) - countUnderK(root, nums[i], low);
			root->insert(root, nums[i]);
		}
		return res;
    }
};