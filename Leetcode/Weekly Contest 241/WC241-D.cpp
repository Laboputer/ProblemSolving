class Solution {
public:
#define MOD 1000000007ll
	long long d[1001][1001];
	int rearrangeSticks(int n, int k) {
		d[1][1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= k; j++)
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j] * (long long)(i - 1)) % MOD;
		return d[n][k];
	}
};