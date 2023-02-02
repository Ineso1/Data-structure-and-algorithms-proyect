class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        patternLetter = {}
        s = list(s.split(" "))
        for i in range(len(s)):
            if s[i] in patternLetter:
                if patternLetter[s[i]] != pattern[i]:
                    return False
            else:
                for j in patternLetter:
                    if patternLetter[j] == pattern[i]:
                        return False
                patternLetter[s[i]] = pattern[i]
        return True

if __name__ == '__main__':
    pattern = "abba" 
    s = "dog cat cat fish"
    sol = Solution()
    print(sol.wordPattern(pattern, s))