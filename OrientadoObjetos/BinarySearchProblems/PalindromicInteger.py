"""
Bonus sin string
"""

import string


class Solution:
    def solve(self, num):
        num = str(num)
        return (False, True)[num[len(num)::-1] == num]
        
if __name__ == '__main__':
    sol = Solution()
    print(sol.solve(101))
