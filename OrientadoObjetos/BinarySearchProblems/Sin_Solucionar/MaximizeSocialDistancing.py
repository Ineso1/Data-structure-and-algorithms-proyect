#Sin resolver

class Solution():
    def solve(self, seats):
        posibles = {'sides': 0, 'center': 0}
        count = 0
        primero = 0
        for i in range(len(seats)):
            if seats[i] == 0:
                count += 1
            elif count > posibles['center']:
                posibles['center'] = count
                count = 0
                primero += 1
        if count >= posibles['sides']:
            posibles['sides'] = count
        if primero == 1 and seats[0] != 1:
            posibles['sides'] = posibles['center']
        if posibles['center'] % 2 != 0:
            valCenter =  int(posibles['center']/2) + 1
        else:
            valCenter = int(posibles['center']/2) 

        if valCenter > posibles['sides']:
            return valCenter
        else:
            return posibles['sides']

            
        
            
        

if __name__ == '__main__':
    
    seats = [0, 1, 0, 0]
    sol = Solution()
    print (sol.solve(seats))