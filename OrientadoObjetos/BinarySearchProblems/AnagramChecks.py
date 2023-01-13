# class Solution:
#     def solve(self, s0, s1):
#         for i in s0:
#             if i in s1:
#                 s1 = s1.replace(i,'',1)
#             else:
#                 return False
#         if len(s1) != 0:
#             return False
#         return True

class Solution:
    def solve(self, s0, s1):
        s0 = sorted(s0)
        s1 = sorted(s1)
        if s1 == s0:
            return True
        else:
            return False


if __name__ == '__main__':
    
    _s0 = "a"
    _s1 = "a"
    sol = Solution()
    print(sol.solve(_s0, _s1))