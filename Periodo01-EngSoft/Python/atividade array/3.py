#apresentar em ordem usando bolha
import random
lista = []
listapar= []
listaimpar = []
for i in range(0,10):
    d = random.randint(0,100)
    lista = lista + [d]
    if d % 2 == 0:
        listapar = listapar + [d]
    else:
        listaimpar = listaimpar + [d]
#BOLHA
trocou = True
fim = len(lista)-1
while fim > 0 and trocou:
    trocou = False
    for i in range (fim):
        if lista[i] > lista[i+1]:
            trocou = True
            temp = lista[i]
            lista[i] = lista[i+1]
            lista[i+1] = temp
    fim = fim-1
print('Números aleatórios:',lista,'\nNúmeros pares:',listaimpar,'\nNúmeros ímpares:',listapar)