class Solution:
    def solve(self, nums):
        m1 = nums[::int(len(nums)/2)]
        m2 = nums[int(len(nums)/2)::]
        res = 0
        while len(m2) > 0:
            sM1 = sum(m1)
            sM2 = sum(m2)
            val = sM1 + sM2
            if val > res:
                res = val
            if sM1 > 0 and sM2 > 0:
                val = sM1 + sM2
                if sM1 > sM2:
                    m1 = nums[::int(len(m1)/2)]
                    m2 = nums[int(len(m1)/2)::]
                elif sM1 < sM2:
                    m1 = nums[::int(len(m2)/2)]
                    m2 = nums[int(len(m2)/2)::]
            elif sM1 > sM2:
                m1 = nums[::int(len(m1)/2)]
                m2 = nums[int(len(m1)/2)::]
            elif sM1 < sM2:
                m1 = nums[::int(len(m2)/2)]
                m2 = nums[int(len(m2)/2)::]
        return res
            

if __name__ == '__main__':
    nums = [10, -5, 12, -100, 3, -1, 20]
    sol = Solution()
    print(sol.solve(nums))