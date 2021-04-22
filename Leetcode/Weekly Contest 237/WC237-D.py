class Solution(object):
    def getXORSum(self, arr1, arr2):
        xor1 = xor2 = 0
        for x in arr1:
            xor1 ^= x;
        for y in arr2:
            xor2 ^= y
        return xor1 & xor2
        