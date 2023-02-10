#Frase diagonal na ordem inversa
frase = 'Boa tarde'
tamanho = len(frase)
aux = tamanho - 1
for i in range(0,tamanho):
    espaço = '   '
    letra = frase[aux]
    print(espaço * i,letra)
    aux = aux - 1