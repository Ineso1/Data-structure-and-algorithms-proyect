
# def main():
#     num = input()
#     pares = []
#     impares = []
#     while num != "*":
#         if int(num) % 2 == 0:
#             pares.append(int(num))
#         else:
#             impares.append(int(num))
#         num = input()

#     print("PARES: ")
#     print(pares)
#     print("IMPARES: ")
#     print(impares)


# if __name__ == '__main__':
#     main()

# def main():
#     lista = []
#     i = int(input())
#     for x in range(i):
#         num = int(input())
#         lista.append(num)
#     for i in range(len(lista)):
#         if lista[i] % 2 == 0:
#             print(f"pos {i}, valor {lista[i]}")

# if __name__ == '__main__':
#     main()


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
print("L1=")
print(L1)

print("L2=")
print(L2)

print("LORDENADA=")
print(lOrdenada)