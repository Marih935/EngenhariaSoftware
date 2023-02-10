#listar 40 números aleatórios
import random
lista = []
for i in range(0,40):
    d = random.randint(0,100)
    lista = lista + [d]
    print(lista[i])

#correção
#import random
#lista = []
#for i in range(0,40):
#    d = random.randint(0,100)
#    lista = lista + [d]
#for i in range(0,40):
#   print(lista[i])