class Solution(object):
    def countPoints(self, points, queries):
        return [sum([1 if ((px - x)**2 + (py - y)**2 <= r**2) else 0 for px, py in points]) for (x, y, r) in queries]
