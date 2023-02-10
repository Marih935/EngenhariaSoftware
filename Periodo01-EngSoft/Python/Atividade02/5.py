import random
lucro = 0
for veículo in range(1,401):
    print('Escolha o veículo:\n1 - Moto\n2 - Carro\n3 - Ônibus\n')
    opção = random.randint(1,3)
    if opção == 1:
        lucro = lucro + 4
    elif opção == 2:
        lucro = lucro + 8
    elif opção == 3:
        lucro =  lucro + 25
    else:
        print('Erro na escolha do veículo')
        
print('O lucro do estacionamento foi R$', lucro)