import queue


class Solution:
    def solve(self, prices):
        res = 0
        for i in range(len(prices)):
            minimo = prices[0]
            maximo = max(prices)
            indexMax = prices.index(maximo)
            resta = maximo - minimo
            if resta > res:
                res = resta
            prices.pop([0:indexMax])
        return res



if __name__ == '__main__':
    prices = [9, 11, 8, 5, 7, 10]
    sol = Solution()
    print(sol.solve(prices))