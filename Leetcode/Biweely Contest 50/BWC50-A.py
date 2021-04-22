class Solution(object):
    def minOperations(self, nums):
        res = 0
        for i in range(1, len(nums)):
            if nums[i-1] >= nums[i]:
                res += nums[i-1] + 1 - nums[i]
                nums[i] = nums[i-1] + 1
        return res