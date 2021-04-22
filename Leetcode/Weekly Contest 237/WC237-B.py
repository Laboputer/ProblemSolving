class Solution(object):
    def maxIceCream(self, costs, coins):
        res = 0
        for x in sorted(costs):
            if(x > coins):
                break
            coins -= x
            res += 1
        return res