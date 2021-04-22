class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        xsum = 0
        xorsumList = []
        for x in nums:
            xsum ^= x
            xorsumList.append(xsum)
            
        bits = (1<<maximumBit)-1
        return [((~(xorsum & bits)) & bits) for xorsum in reversed(xorsumList)]