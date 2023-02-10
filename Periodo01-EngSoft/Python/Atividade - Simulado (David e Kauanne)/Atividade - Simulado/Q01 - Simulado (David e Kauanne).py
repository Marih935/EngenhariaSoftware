# IFPE - Campus Belo Jardim
# Questão 01 do Simulado
# Alunos: David e Kauanne

maior1 = 0 
maior2 = 0
menor1 = 101 
menor2 = 101
import random
for c in range(0, 51):
    n = random.randint(0, 100)
    if n % 2 == 0:
        if n > maior1 or n > maior2:
            if maior1 > maior2:
                maior2 = n
            elif maior2 > maior1:
                maior1 = n
            else:
                maior1 = n
    else:
        if n < menor1 or n < menor2:
            if menor1 > menor2:
                menor1 = n
            elif menor2 > menor1:
                menor2 = n
            else:
                menor1 = n

print(f'Os dois maiores números pares gerados foram {maior1} e {maior2}.')
print(f'Os dois menores números ímpares gerados foram {menor1} e {menor2}.')