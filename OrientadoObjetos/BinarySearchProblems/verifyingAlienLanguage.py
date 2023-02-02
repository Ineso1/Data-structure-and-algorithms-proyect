# class Solution:
#     def encode(self, word, lex) -> int:
#         value = ""
#         for j in word:
#             value += str(lex[j])
#         return int(value) 

#     def compare(self, word1, word2, lex):
#         for i,j in zip(word1, word2):
#             if lex[i] > lex[j]:
#                 return False
#         return True

#     def isAlienSorted(self, words: list[str], order: str) -> bool:
#         numerated = set(enumerate(order))
#         lex = dict((y, x) for x, y in numerated)
        # curr = 0 
        # prev = self.encode(words[0], lex)
        # for i in range(1, len(words)):
        #     curr = self.encode(words[i], lex)
        #     if curr < prev:
        #         return False
        # return True
        # for i in range(1,len(words)):
        #     if not self.compare(words[i-1],words[i], lex):
        #         return False
        # return True

class Solution:
    def isAlienSorted(self, words: list[str], order: str) -> bool:
        order_index = {char: index for index, char in enumerate(order)}
        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            for j in range(min(len(word1), len(word2))):
                if word1[j] != word2[j]:
                    if order_index[word1[j]] > order_index[word2[j]]:
                        return False
                    break
            else:
                if len(word1) > len(word2):
                    return False
        return True

if __name__ == '__main__':
    words = ["hello","leetcode"]
    order = "hlabcdefgijkmnopqrstuvwxyz"
    sol = Solution()
    sol.isAlienSorted(words, order)