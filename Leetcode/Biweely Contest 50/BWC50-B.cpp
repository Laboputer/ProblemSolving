class Solution {
public:
	bool inCircle(int x, int y, int r, int px, int py)
	{
		return ((px - x)*(px - x) + (py - y)*(py - y)) <= r * r;
	}
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> res;
		for (int k = 0; k < queries.size(); k++)
		{
			int cnt = 0;
			for (int i = 0; i < points.size(); i++)
				if (inCircle(queries[k][0], queries[k][1], queries[k][2], points[i][0], points[i][1]))
					cnt++;
			res.push_back(cnt);
		}

		return res;
	}
};