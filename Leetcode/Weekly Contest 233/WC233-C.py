class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def getSum(len, K) -> int:
            if K > len:
                return K * (K+1) // 2 - (K-len) * (K-len+1) // 2
            else:
                return K * (K+1) // 2 + len - K

        ans, l, r = 0, 1, maxSum
        while l <= r:
            K = (l+r) // 2;
            use = getSum(index+1, K) + getSum(n-index, K) - K
            if use <= maxSum:
                ans = K
                l = K + 1
            else:
                r = K - 1
        return ans