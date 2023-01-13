class Solution():
    def minimum(self,a,b):
        if a <= b: 
            return a 
        else: 
            return b

    def solve(self,nums):
        if len(nums) <= 2:
            return 0
        else:
            izq = nums[0]
            der = nums[1]
            recoleccion = False
            espacios = []
            suma = 0
        for i in range(len(nums)):
            if (nums[i] < der or nums[i] < izq) and i != 0:
                recoleccion = True
                espacios.append(nums[i])
            elif ((nums[i] >= der or nums[i] >= izq) or i == len(nums)) and recoleccion == True:
                der = nums[i]
                suma += (len(espacios) * self.minimum(izq,der)) - sum(espacios)
                recoleccion = False
                izq = der
                espacios = []
            elif recoleccion == False and nums[i] > izq:
                izq = nums[i]
            else:
                recoleccion = True
        return suma


if __name__ == '__main__':
    nums = [3, 0, 1, 3, 0, 5]
    sol = Solution()
    print(sol.solve(nums))