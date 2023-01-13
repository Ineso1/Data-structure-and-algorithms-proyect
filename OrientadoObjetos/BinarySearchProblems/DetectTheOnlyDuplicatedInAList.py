class Solution:
    def solve(self, nums):
        deste = sum(set(nums))
        sNums = sum(nums)
        return sNums - deste

if __name__ == '__main__':
    _nums = [1, 2, 3, 1]
    sol = Solution()
    print(sol.solve(_nums))