
class Solution:
    def solve(self, nums, k):

        subLista1 = nums[k::]
        subLista2 = nums[0:k]
        return subLista1 + subLista2


if __name__ == '__main__':
    
    _nums = [1, 2, 3, 4, 5, 6]
    _k = 2
    sol = Solution()
    print(sol.solve(_nums, _k))