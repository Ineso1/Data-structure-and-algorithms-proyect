#Sin solucionar

class Solution:
    def solve(self, s):
        if len(s) == 0:
            return 0
        palindromo = 0
        sList = list(s)
        sSet = set(sList)
        sSet = dict.fromkeys(sSet,0)
        for i in sList:
            if i in sSet:
                sSet[i] += 1
        for i in sSet:
            if sSet[i] % 2 != 0:
                palindromo += (sSet[i]-1)
            else:
                palindromo += sSet[i]
        if palindromo == 0:
            return 1
        elif len(s) % 2 != 0: 
            return palindromo + 1
        else:
            return palindromo


if __name__ == '__main__':
    
    s = "rbaicneacrayr"
    sol = Solution()
    print (sol.solve(s))