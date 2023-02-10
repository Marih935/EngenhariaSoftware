n1 = int(input('Digite um número: '))
maior = n1
n2 = int(input('Digite outro número: '))

if n2 > maior:
    maior = n2
n3 = int(input('Novamente, digite outro número: '))
if n3 > maior:
    maior = n3
N1 = n1
N2 = n2
N3 = n3
mmc = 1
for i in range(2,maior+1):
    while n1 % i == 0 or n2 % i == 0 or n3 % i == 0:
        if (n1 % i == 0 and n2 % i != 0 and n3 % i != 0) or (n1 % i != 0 and n2 % i == 0 and n3 % i != 0) or (n1 % i != 0 and n2 % i != 0 and n3 % i == 0) or (n1 % i != 0 and n2 % i == 0 and n3 % i == 0) or (n1 % i == 0 and n2 % i != 0 and n3 % i == 0) or (n1 % i == 0 and n2 % i == 0 and n3 % i != 0) or (n1 % i == 0 and n2 % i == 0 and n3 % i == 0):
            mmc = mmc * i
            if n1 % i == 0:
                n1 = n1/i
            if n2 % i == 0:
                n2 = n2/i
            if n3 % i == 0:
                n3 = n3/i
        if n1 == 1 and n2 == 1 and n3 == 1:
            break
i = i + 1
print(f'O MMC de {n1}, {n2} e {n3} é {mmc}')