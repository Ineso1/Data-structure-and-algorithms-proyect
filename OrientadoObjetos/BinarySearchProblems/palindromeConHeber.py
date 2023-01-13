class Solution:
    def solve(self, s):
        if(s==s[::-1]):
            return True
        return False

if __name__ == '__main__':
    sol = Solution()
    s = "evilolive"
    print(sol.solve(s))
    