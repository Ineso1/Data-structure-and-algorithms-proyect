class Solution:
    def solve(self, s):
        ev = s[0]
        cont = 0
        _str = ""
        for i in s:
            if ev == i:
                cont = cont + 1
            else:
                _str = _str + str(cont) + ev
                ev = i
                cont = 1
        _str = _str + str(cont) + ev
        return _str

if __name__ == '__main__':
    _s = "aaaabbbccdaa"
    sol = Solution()
    print(sol.solve(_s))