class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        mod = 1000000007
        d = [[0]*1001 for i in range(1001)]
        d[1][1] = 1
        
        for i in range(2, n+1):
            for j in range(1, k+1):
                d[i][j] = (d[i-1][j-1] + d[i-1][j]*(i-1)) % mod
        return d[n][k]