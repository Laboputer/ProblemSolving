class Solution(object):
    def sumBase(self, n, k):
        sum = 0
        while n:
            sum += n%k
            n /= k
        return sum