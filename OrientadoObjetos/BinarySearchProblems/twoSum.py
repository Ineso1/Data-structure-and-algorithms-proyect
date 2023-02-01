
# class Solution:
#     def twoSum(self, nums: list[int], target: int) -> list[int]:
#         returnList = []
#         for i,j in enumerate(nums):
#             for k in range(i+1,len(nums)):
#                 if target - j == nums[k]:
#                     returnList.append(i)
#                     returnList.append(k)
#                     return returnList
#         return returnList

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [i, hashmap[complement]]
            hashmap[nums[i]] = i

if __name__ == '__main__':
    nums = [3,2,4]
    target = 6
    sol = Solution()
    sol.twoSum(nums, target)