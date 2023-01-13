class Solution:
    def solve(self, a, b):
        a.extend(b)
        a.sort()
        return a

if __name__ == '__main__':
    a = [5, 10, 15]
    b = [3, 8, 9]
    sol = Solution()
    print(sol.solve(a,b))