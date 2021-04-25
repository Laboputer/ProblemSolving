class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.sort()
        if restrictions[-1][0] != n:
            restrictions.append([n, 10**9])

        for i in range(len(restrictions)-1):
            c = restrictions[i+1][0] - restrictions[i][0]
            restrictions[i+1][1] = min(restrictions[i+1][1], restrictions[i][1] + c)

        for i in range(len(restrictions)-1, 0, -1):
            c = restrictions[i][0] - restrictions[i-1][0]
            restrictions[i-1][1] = min(restrictions[i-1][1], restrictions[i][1] + c)
        
        res = 0
        for i in range(len(restrictions)-1):
            l = restrictions[i+1][0] - restrictions[i][0]
            h1, h2 = restrictions[i][1], restrictions[i+1][1]
            res = max(res, h1, h2, (l + h1 + h2) // 2)
        return res

