# IFPE - Campus Belo Jardim
# Questão 05 do Simulado
# Alunos: David e Kauanne

import random

n1 = 0
n2 = 0
n3 = 0
vezes = 0

while True:
    n1 = random.randint(0, 200)
    n2 = random.randint(0, 200)
    n3 = random.randint(0, 200)

    if n1 == n2 and n1 == n3:
        print(f'O número gerado foi {n1} para os três.')
        print(f'Foram necessários gerar {vezes} trios.')
        break

    else:
        n1 = random.randint(0, 200)
        n2 = random.randint(0, 200)
        n3 = random.randint(0, 200)
        vezes = vezes + 1
