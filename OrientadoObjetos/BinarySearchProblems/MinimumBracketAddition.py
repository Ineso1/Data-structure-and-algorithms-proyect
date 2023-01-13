class Solution():
    def solve(self, s):
        a = 0
        b = 0
        for i in s:
            if i == ')' and b > 0:
                b -= 1
            elif i == ')':
                a += 1
            else:
                b += 1
        return a + b

if __name__ == '__main__':
    _s = "()))(()"
    sol = Solution()
    print(sol.solve(_s))