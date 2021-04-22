class Solution(object):
    def checkIfPangram(self, sentence):
        c = [0]*26
        for ch in list(sentence):
            c[ord(ch) - ord('a')] = 1
        
        return True if sum(c) == 26 else False