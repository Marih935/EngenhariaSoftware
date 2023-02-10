base = int(input('Digite a base:\n'))
expoente = int(input('Digite o expoente:\n'))
a = base

for i in range(expoente-1):
    a = a * base
print(a)