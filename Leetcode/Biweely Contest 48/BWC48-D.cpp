class Solution {
public:
	int size;
	int d[100000];
	int gcd[14][14];
	int visit[14];
	int ans = 0;

	int GCD(int a, int b)
	{
		if (b == 0) return a;
		else return GCD(b, a%b);
	}

	int F(int state)
	{
		if (state == (1 << size) - 1)
			return 0;

		int& ref = d[state];
		if (ref != -1) return ref;

		int cnt = 0;
		for (int i = 0; i < size; i++) if (state & (1 << i)) cnt++;
		cnt /= 2;

		ref = 0;
		for (int i = 0; i < size; i++)
		{
			if (state & (1 << i)) continue;
			for (int j = i + 1; j < size; j++)
			{
				if (state & (1 << j)) continue;

				state |= (1 << i);
				state |= (1 << j);
				ref = max(ref, F(state) + (cnt + 1)*gcd[i][j]);
				state &= ~(1 << i);
				state &= ~(1 << j);
			}
		}
		return ref;
	}

	int maxScore(vector<int>& nums) {
		for (int i = 0; i < 100000; i++) d[i] = -1;

		size = nums.size();
		for (int i = 0; i < size; i++)
			for (int j = i + 1; j < size; j++)
				gcd[i][j] = GCD(nums[i], nums[j]);

		return F(0);
	}
};