class Solution(object):
    def maxAscendingSum(self, nums):
        res, sum = nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i-1] >= nums[i]:
                sum = nums[i]
            else:
                sum += nums[i]
            res = max(res, sum)
        return res