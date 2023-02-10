#idade e nome ordenados
lista = []
listanome = []
listaidade = []
escolha = int(input('Escolha uma ação:\n1-Adicionar dados\n2-Encerrar\n'))
while escolha == 1:
    nome = input('Digite o nome: ')
    idade = int(input('Digite a idade: '))
    listanome = listanome + [nome]
    listaidade = listaidade + [idade]
    escolha = int(input('Escolha uma ação:\n1-Adicionar dados\n2-Encerrar\n'))

trocou = True
fim = len(listanome)-1
while fim > 0 and trocou:
    trocou = False
    for i in range (fim):
        if listanome[i] > listanome[i+1]:
            trocou = True
            temp = listanome[i]
            listanome[i] = listanome[i+1]
            listanome[i+1] = temp

            temp = listaidade[i]
            listaidade[i] = listaidade[i+1]
            listaidade[i+1] = temp
    fim = fim-1
print(listanome)

trocou = True
fim = len(listaidade)-1
while fim > 0 and trocou:
    trocou = False
    for i in range (fim):
        if listaidade[i] > listaidade[i+1]:
            trocou = True
            temp = listaidade[i]
            listaidade[i] = listaidade[i+1]
            listaidade[i+1] = temp

            temp = listanome[i]
            listanome[i] = listanome[i+1]
            listanome[i+1] = temp
    fim = fim-1
print(listanome)