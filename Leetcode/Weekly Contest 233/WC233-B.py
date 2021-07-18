class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        buy , sell = [], []
        for p, a, t in orders:
            if t == 1:
                while a > 0 and len(buy) > 0 and -buy[0][0] >= p:
                    topp, topa = buy[0]
                    heapq.heappop(buy)
                    a -= topa
                    if a < 0:
                        heapq.heappush(buy, [topp, -a])
                if a > 0:
                    heapq.heappush(sell, [p, a])
            else:
                while a > 0 and len(sell) > 0 and sell[0][0] <= p:
                    topp, topa = sell[0]
                    heapq.heappop(sell)
                    a -= topa
                    if a < 0:
                        heapq.heappush(sell, [topp, -a])
                if a > 0:
                    heapq.heappush(buy, [-p, a])
        return (sum([a for p, a in buy]) + sum([a for p, a in sell])) % (10**9 + 7)