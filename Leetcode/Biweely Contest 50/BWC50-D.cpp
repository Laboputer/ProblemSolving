class Solution {
public:
#define MOD 1000000007ll
	long long pow(int x, int n)
	{
		if (n == 0) return 1;
		
		long long value = pow(x, n / 2);
		value = (value * value) % MOD;
		if (n & 1) value = (value * (long long)x) % MOD;
		return value;
	}

	int makeStringSorted(string s) {
		long long res = 0;
		long long f[3001]; f[0] = 0, f[1] = 1;
		for (long long i = 2; i <= 3000; i++) f[i] = (f[i - 1] * i) % MOD;

		int c[26] = { 0, };
		for (int i = s.size() - 1; i >= 0; i--)
		{
			long long sum = 0, value = 0;
			int ch = s[i] - 'a';
			c[ch]++;
			for (int k = 0; k < ch; k++) sum += c[k];
			value = (sum * f[s.size() - i - 1]) % MOD;
			for (int k = 0; k < 26; k++) if(c[k] > 1) value = (value * pow(f[c[k]], MOD - 2)) % MOD;

			res = (res + value) % MOD;
		}
		return res % MOD;
	}
};