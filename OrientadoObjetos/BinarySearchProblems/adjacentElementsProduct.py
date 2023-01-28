def solution(inputArray):
    maxNum = 0
    for i in range(len(inputArray)-1):
        product = inputArray[i] * inputArray[i+1]
        if product > maxNum:
            maxNum = product
    return maxNum
    

if __name__ == '__main__':
    print(solution([3, 6, -2, -5, 7, 3]))