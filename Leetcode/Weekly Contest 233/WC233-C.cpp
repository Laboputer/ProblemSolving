class Solution {
public:
	long long getSum(long long len, long long K)
	{
		if (K > len)
			return (K*(K + 1) / 2ll) - (K - len) * (K - len + 1) / 2ll;
		else
			return K * (K + 1) / 2ll + len - K;
	}

	int maxValue(int n, int index, int maxSum) {
		int ans = 0;
		int l = 1, r = 1e9;
		while (l <= r)
		{
			int k = (l + r) / 2;

			int leftLen = index + 1;
			int rightLen = n - index;

			long long useSum = getSum(leftLen, k) + getSum(rightLen, k) - k;
			if (useSum <= (long long)maxSum)
			{
				ans = k;
				l = k + 1;
			}
			else r = k - 1;
		}

		return ans;
	}
};