class Solution:
    def makeStringSorted(self, s: str) -> int:
        mod = 10**9 + 7
        c = [0] * 26
        f = [0, 1]
        for i in range(2, 3001):
            f.append((f[i-1] * i) % mod)
        
        res = 0
        for i in range(len(s)-1, -1, -1):
            ch = ord(s[i]) - ord('a')
            c[ch] += 1
            value = sum(c[:ch]) * f[len(s) - i - 1]
            for k in range(26):
                if c[k] > 1:
                    value = (value * (pow(f[c[k]], mod-2, mod))) % mod
            res = (res + value) % mod
        return res