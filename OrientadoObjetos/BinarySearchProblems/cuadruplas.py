class Solution:
    def solve(self, nums, target):
        cuadruplas = []
        actual = []
        for i in nums:
            actual.append(nums.pop())
            for j in nums:
                if 




if __name__ == '__main__':
    nums = [1,0,-1,0,-2,2]
    target = 0
    solution = Solution()
    solution.solve(nums, target)