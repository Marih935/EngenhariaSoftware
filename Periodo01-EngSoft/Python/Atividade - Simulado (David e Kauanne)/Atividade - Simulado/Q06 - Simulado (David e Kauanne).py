# IFPE - Campus Belo Jardim
# Questão 06 do Simulado
# Alunos: David e Kauanne

pessoa1 = ''
pessoa2 = ''
pessoa3 = ''
idade1 = 500
idade2 = 600
idade3 = 700
resp = '1'

while resp == '1':
    nome = input('Digite o nome: ')
    idade = int(input('Digite a idade: '))
    if idade < idade1 or idade < idade2 or idade < idade3:
        if idade1 > idade2 and idade1 > idade3:
            idade1 = idade
            pessoa1 = nome
        elif idade2 > idade1 and idade2 > idade3:
            idade2 = idade
            pessoa2 = nome
        elif idade3 > idade1 and idade3 > idade2:
            idade3 = idade
            pessoa3 = nome
    
    resp = input('Digite 1 para continuar...\n')

print(f'As três pessoas mais novas são {pessoa1}, {pessoa2} e {pessoa3}, com {idade1} anos, {idade2} anos e {idade3} anos, respectivamente.')
