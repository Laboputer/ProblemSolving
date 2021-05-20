class Solution:
    def minSwaps(self, s: str) -> int:
        n1 = sum([1 if s[i] == '0' else 0 for i in range(0, len(s), 2)])
        n2 = sum([1 if s[i] == '1' else 0 for i in range(1, len(s), 2)])
        ans1 = n1 if (n1 == n2) else 1e9
        
        n1 = sum([1 if s[i] == '1' else 0 for i in range(0, len(s), 2)])
        n2 = sum([1 if s[i] == '0' else 0 for i in range(1, len(s), 2)])
        ans2 = n1 if (n1 == n2) else 1e9
        
        if ans1 == 1e9 and ans2 == 1e9:
            return -1
        return min(ans1, ans2)