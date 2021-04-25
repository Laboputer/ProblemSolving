class Solution {
public:
	int maxBuilding(int n, vector<vector<int>>& restrictions) {
		restrictions.push_back({ 1, 0 });
		sort(restrictions.begin(), restrictions.end());
		if (restrictions[restrictions.size() - 1][0] != n) 
			restrictions.push_back({ n, 1000000000 });

		for (int i = 0; i < restrictions.size() - 1; i++)
		{
			int c = restrictions[i + 1][0] - restrictions[i][0];
			restrictions[i+1][1] = min(restrictions[i+1][1], restrictions[i][1] + c);
		}

		for(int i = restrictions.size() - 1; i > 0; i--)
		{
			int c = restrictions[i][0] - restrictions[i - 1][0];
			restrictions[i-1][1] = min(restrictions[i-1][1], restrictions[i][1] + c);
		}

        int res = 0;
        for(int i = 0; i < restrictions.size() - 1; i++)
        {
			int len = restrictions[i+1][0] - restrictions[i][0];  
			int h1 = restrictions[i][1];
			int h2 = restrictions[i+1][1];

			res = max(res, max(h1, h2));
			res = max(res, (len + h1 + h2) / 2);            
        }
        
		return res;
	}
};