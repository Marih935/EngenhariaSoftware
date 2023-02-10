cont = 0
homem = 1000
mulher = ''
idade_mulher = -1

print('Digite 0 para informar a pessoa:\n')
while cont == 0:
    nome= str(input('Digite o nome:\n'))
    print('Digite a idade de', nome,':\n', end = '')
    idade = int(input())
    print('Digite o sexo de', nome)
    print('1-Feminino\n2-Masculino\n')
    sexo = int(input())
    if sexo == 1:
        if homem > idade:
            homem = idade
    elif sexo == 2:
        if idade_mulher < idade:
            idade_mulher = idade