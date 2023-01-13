def main():
    num = input()
    L1 = []
    while num != "*":
        L1.append(int(num))
        num = input()
    L2 = []
    num = input()
    while num != "*":
        L2.append(int(num))
        num = input()
    lOrdenada = L1 + L2
    lOrdenada.sort()
    print(lOrdenada)

if __name__=='__main__':
    main()