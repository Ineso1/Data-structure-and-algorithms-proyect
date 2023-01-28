def solution(a):
    seen = {}
    for i, num in enumerate(a):
        if num in seen:
            return num
        seen[num] = i
    return -1

if __name__ == '__main__':
    a = [2, 1, 3, 5, 3, 2]
    print(solution(a))