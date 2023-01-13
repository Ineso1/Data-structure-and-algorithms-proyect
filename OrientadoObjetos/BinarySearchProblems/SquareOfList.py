class Solution:
    def solve(self, nums):
        for i in range(len(nums)):
            nums[i]*=nums[i]
        nums.sort()
        return nums   

if __name__ == '__main__':
    _nums  = [-9, -2, 0, 2, 3]
    sol = Solution()
    print(sol.solve(_nums))