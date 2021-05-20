class Solution(object):
    def maxFrequency(self, nums, k):
        res, sum, s = 0, 0, 0
        sorted(nums)
        for i in range(len(nums)):
            sum += nums[i]
            while s < i and sum + k < nums[i] * (i - s + 1):
                sum -= nums[s]
                s += 1
            res = max(res, i - s + 1)
        return res
