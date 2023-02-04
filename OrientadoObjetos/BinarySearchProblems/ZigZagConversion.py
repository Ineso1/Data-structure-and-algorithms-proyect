class Solution(object):
    def convert(self, s, numRows):
        returnStringList = [""]*numRows
        direction = True
        j = 0 
        if numRows == 1:
            return s

        for i in s:
            auxString = ""
            if direction and j < numRows:
                returnStringList[j] += i
                if j == numRows-1:
                    direction = False
                    j -= 1
                else:
                    j += 1
            else:
                returnStringList[j] += i
                if j == 0:
                    direction = True
                    j += 1
                else:
                    j -= 1
        return "".join(returnStringList)
            





if __name__ == '__main__':
    # s = "PAYPALISHIRING"
    # numRows = 3
    s = "ABC"
    numRows = 1
    sol = Solution()
    print(sol.convert(s, numRows))