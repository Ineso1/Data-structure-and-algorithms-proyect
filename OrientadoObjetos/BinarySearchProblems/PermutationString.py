# class Solution(object):
#     def checkInclusion(self, s1, s2):
#         """
#         :type s1: str
#         :type s2: str
#         :rtype: bool
#         """
#         if len(s1) > len(s2):
#             return False

#         s1_count = [0] * 26
#         s2_count = [0] * 26

#         for char in s1:
#             s1_count[ord(char) - ord("a")] += 1

#         for i in range(len(s1)):
#             s2_count[ord(s2[i]) - ord("a")] += 1

#         for i in range(len(s1), len(s2)):
#             if s1_count == s2_count:
#                 return True

#             s2_count[ord(s2[i - len(s1)]) - ord("a")] -= 1
#             s2_count[ord(s2[i]) - ord("a")] += 1

#         return s1_count == s2_count
from collections import defaultdict


class Solution(object):
    def checkInclusion(self, s1, s2):
        count_s1 = defaultdict(int)
        for c in s1:
            count_s1[c] +=1
        s1char = set(count_s1.keys())
        s1_len = len(s1)
        
        char_remn = len(s1char) 
        for i,c in enumerate(s2):
            if c in s1char: 
                count_s1[c] -=1
                if count_s1[c] == 0: 
                    char_remn -= 1
                    if char_remn == 0: return True 
            if ((i-s1_len+1)>=0) and (s2[i-s1_len+1] in s1char):
                count_s1[s2[i-s1_len+1]] +=1
                if count_s1[s2[i-s1_len+1]]==1:
                    char_remn +=1
        return False


if __name__ == '__main__':
    s1 = "ab" 
    s2 = "eidbaooo"
    sol = Solution()
    sol.checkInclusion(s1, s2)