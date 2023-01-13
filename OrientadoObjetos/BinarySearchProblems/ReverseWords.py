class Solution:
    def solve(self, sentence):
        sentence = sentence.split()
        return " ".join(sentence[::-1])
        

if __name__ == '__main__':

    _sentence = "hello there my friend"
    sol = Solution()
    print(sol.solve(_sentence))