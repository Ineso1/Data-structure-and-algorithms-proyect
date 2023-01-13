
class Solution():
    def solve(self, s):
        solitario = 0
        dic = {}
        deste = set(s)
        for i in deste:
            dic[i] = s.count(i)
        for i in deste:
            if dic[i] % 2 !=0:
                if solitario == 0:
                    solitario += 1
                else:
                    return False
        return True

if __name__ == '__main__':
    s = "carrace"
    sol = Solution()
    print(sol.solve(s))