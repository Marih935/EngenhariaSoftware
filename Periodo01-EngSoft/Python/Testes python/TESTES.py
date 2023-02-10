import random
desafio = 0

#Volstagg
Volstagg = random.randint(1,100)
Loki = random.randint(1,100)
if Loki > Volstagg:
    print('Loki venceu')
    desafio = desafio + 1
else:
    print('Loki perdeu')

#Frandral
Loki = 0
Frandral = 0
for i in range(1,11):
    flecha = random.randint(1,60)
    Loki = Loki + flecha
    flecha = random.randint(1,60)
    Frandral = Frandral + flecha
if Loki < Frandral:
    print('Loki venceu')
    desafio = desafio + 1
else:
    print('Loki perdeu')

#Hogun
resultado = int(input('Loki venceu?\n1 - Sim\n2 - Não\n'))
if resultado == 1:
    print('Loki venceu')
    desafio = desafio + 1
else:
    print('Loki perdeu')

#Valquíria
n1 = 0
n2 = 1
resultado = 0
while n1 != n2:
    n1 = random.randint(1,60)
    n2 = random.randint(1,60)
    if resultado == 0 and n1 == n2:
        print('Loki vanceu')
        desafio = desafio + 1
        resultado = 1
    if resultado == 1 and n1 == n2:
        print('Loki perdeu')
        resultado = 0

#Lady Sif
pontoL = 0
pontoS = 0
for i in range(1,4):
    #Vez de Loki
    Loki = random.randint
    Sif = random.randint
    if ((Loki%2== 0 and Sif%2!= 0) or (Loki%2!= 0 and Sif%2== 0)):
        pontoS = pontoS + 1
if pontoS > pontoL:
    print('Loki venceu')
    desafio = desafio + 1
else:
    print ('Loki perdeu')

#Ponto extra de Loki
desafio = desafio + 1

#Resultado final
if desafio >= 3:
    print('Loki pode ser o protetor')
else:
    print('Loki não pode ser o protetor')