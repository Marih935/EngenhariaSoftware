# IFPE - Campus Belo Jardim
# Questão 03 do Simulado
# Alunos: David e Kauanne

S = 0
print('Os 30 primeiros termos do somatório são:\n')
print('S =', end=' ')
for c in range(1, 6):
    if c == 5:
        print('2/3 + 6/4 + 3/1 + 2/6 + (-1)/3 + 2/6', end='')
    else:
        print('2/3 + 6/4 + 3/1 + 2/6 + (-1)/3 + 2/6 + ', end='')
    S = S + (2/3 + 6/4 + 3/1 + 2/6 + (-1)/3 + 2/6)
print(f'\nS = {S:.2f}')
