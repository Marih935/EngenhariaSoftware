#Informe quantes vezes 'i' aparece na frase
frase = input('Digite uma frase: ')
tamanho = len(frase)
repeticoes = 0
for i in range(tamanho):
    letra = frase[i]
    if letra == 'i' or letra == 'I':
        repeticoes += 1
print('O termo "i" se repetiu',repeticoes,'vezes')