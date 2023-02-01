class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)

        lcm = len(str1) * len(str2) // gcd(len(str1), len(str2))
        if str1 * (lcm // len(str1)) == str2 * (lcm // len(str2)):
            return str1[:gcd(len(str1), len(str2))]
        return ""

if __name__ == '__main__':
    str1 = "ABCABC"
    str2 = "ABC"
    sol = Solution()
    print(sol.gcdOfStrings(str1, str2))