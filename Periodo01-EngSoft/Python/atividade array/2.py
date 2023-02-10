#exibir números pares e ímpares
import random
lista = []
listapar= []
listaimpar = []
for i in range(0,40):
    d = random.randint(0,100)
    lista = lista + [d]
    if d % 2 == 0:
        listapar = listapar + [d]
    else:
        listaimpar = listaimpar + [d]
print('Números aleatórios:',lista,'\nNúmeros ímpares:',listaimpar,'\nNúmeros pares:',listapar)