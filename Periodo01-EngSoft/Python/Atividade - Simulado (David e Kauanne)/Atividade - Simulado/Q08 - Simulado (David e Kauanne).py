# IFPE - Campus Belo Jardim
# Questão 08 do Simulado
# Alunos: David e Kauanne

n1 = int(input('Digite o 1° número: '))
maior = n1
n2 = int(input('Digite o 2° número: '))
if n2 > maior:
    maior = n2
n3 = int(input('Digite o 3° número: '))
if n3 > maior:
    maior = n3
N1 = n1
N2 = n2
N3 = n3

mmc = 1
for c in range(2, maior + 1):
    while n1 % c == 0 or n2 % c == 0 or n3 % c == 0:
        if (n1 % c == 0 and n2 % c != 0 and n3 % c != 0) or (n1 % c != 0 and n2 % c == 0 and n3 % c != 0) or (n1 % c != 0 and n2 % c != 0 and n3 % c == 0) or (n1 % c != 0 and n2 % c == 0 and n3 % c == 0) or (n1 % c == 0 and n2 % c != 0 and n3 % c == 0) or (n1 % c == 0 and n2 % c == 0 and n3 % c != 0) or (n1 % c == 0 and n2 % c == 0 and n3 % c == 0):
            mmc = mmc * c
            if n1 % c == 0:
                n1 = n1 / c
            if n2 % c == 0:
                n2 = n2 / c
            if n3 % c == 0:
                n3 = n3 / c
               
        if n1 == 1 and n2 == 1 and n3 == 1:
            break
    c = c + 1

print(f'O MMC de {N1}, {N2} e {N3} é igual a {mmc}.')
