#potência
def pot():
    base = int(input('Digite base: '))
    exp = int(input('Digite expoente: '))
    if exp == 0:
        print('1')
    elif exp == 1:
        print(base)
    elif exp == -1:
        print(f'1/{base}')
    else:
        a = base
        for i in range(2, abs(exp)+1):
            a = a * base
        if exp < 0:
            print(f'1/{a}')
        else:
            print(a)

#megasena
import random
def mega():
    palpites = int(input('Digite número de palpites da megasena: '))
    for i in range(palpites):
        lista = []
        n1 = random.randint(1,60)
        n2 = random.randint(1,60)
        while n1 == n2:
            n2 = random.randint(1,60)
        n3 = random.randint(1,60)
        while n3 == n1 or n3 == n2:
            n3 = random.randint(1,60)
        n4 = random.randint(1,60)
        while n4 == n1 or n1 == n2 or n4 == n3:
            n4 = random.randint(1,60)
        n5 = random.randint(1,60)
        while n5 == n1 or n5 == n2 or n5 == n3 or n5 == n4:
            n5 = random.randint(1,60)
        n6 = random.randint(1,60)
        while n6 == n1 or n6 == n2 or n6 == n3 or n6 == n4 or n6 == n5:
            n6 = random.randint(1,60)
        lista = lista + [n1] + [n2] + [n3] + [n4] + [n5] + [n6]

        trocou = True
        fim = len(lista)-1
        while fim > 0 and trocou:
            trocou = False
            for i in range(fim):
                if lista[i] > lista[i+1]:
                    trocou = True
                    temp = lista[i]
                    lista[i] = lista[i+1]
                    lista[i+1] = temp
            fim = fim -1
        
        for c in range(0, len(lista)):
            if lista[c] < 10:
                print(f'0{lista[c]}', end=' | ')
            else:
                print(lista[c], end=' | ')
        print()
pot()
mega()