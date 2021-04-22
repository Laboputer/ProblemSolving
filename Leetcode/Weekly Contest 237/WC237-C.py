class Solution(object):
    def getOrder(self, tasks):
        tasks = sorted([(v[0], v[1], i) for i, v in enumerate(tasks)])
        
        available = []
        res = []
        cT, i = 1, 0
        while len(available) != 0 or i < len(tasks):
            while i < len(tasks) and tasks[i][0] <= cT:
                heapq.heappush(available, (tasks[i][1], tasks[i][2]))
                i += 1
                
            if len(available) == 0:
                cT = tasks[i][0]
                continue
            
            pT, idx = heapq.heappop(available)
            res.append(idx)
            cT += pT
            
        return res