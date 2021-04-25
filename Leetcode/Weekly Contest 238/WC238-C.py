class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        ch = "aeiouu"
        res, v, o = 0, 0, 0
        for c in list(word):
            if v == 0 and c != 'a':
                continue
            if c == ch[o]:
                v += 1
            elif c == ch[o+1]:
                v += 1
                o += 1
            elif c == 'a':
                v = 1
                o = 0
            else:
                v = 0
                o = 0
            if ch[o] == 'u':
                res = max(res, v)
        return res 
        