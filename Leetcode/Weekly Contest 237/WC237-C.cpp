class Solution {
	struct task
	{
		int i;
		int pTime;
		bool operator < (const task& rhs) const
		{
			if (pTime == rhs.pTime) return i > rhs.i;
			else return pTime > rhs.pTime;
		}
	};

public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		for (int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);
		sort(tasks.begin(), tasks.end());

		priority_queue<task> available;
		vector<int> res;
		long long cT = 1, i = 0;
		while (available.size() != 0 || i < tasks.size())
		{
			while (i < tasks.size() && (long long)tasks[i][0] <= cT)
			{
				available.push({ tasks[i][2], tasks[i][1] });
				i++;
			}
            
            if (available.size() == 0)
            {
                cT = tasks[i][0];
                continue;
            }

			task top = available.top(); available.pop();
			res.push_back(top.i);
			cT += top.pTime;
		}
		return res;
	}
};