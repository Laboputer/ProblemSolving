class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.n1 = nums1
        self.n2 = nums2
        self.m = {}
        for x in nums2:
            if x in self.m:
                self.m[x] +=1
            else:
                self.m[x] = 1

    def add(self, index: int, val: int) -> None:
        self.m[self.n2[index]] -=1
        self.n2[index] += val
        
        if self.n2[index] in self.m:
            self.m[self.n2[index]] +=1
        else:
            self.m[self.n2[index]] = 1

    def count(self, tot: int) -> int:
        return sum([self.m[tot-x] if tot-x in self.m else 0 for x in self.n1])