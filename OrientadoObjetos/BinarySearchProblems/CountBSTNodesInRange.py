class Tree:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self, cola = 0):
        self.cola = 0
    def solve(self, root, lo, hi):
        pass

    
if __name__ == '__main__':
    root = [3, [2, null, null], [9, [7, [4, null, null], [8, null, null]], [12, null, null]]]
    lo = 5
    hi = 10
    sol = Solution()
    print(sol.solve(lo, hi))
    # sol.