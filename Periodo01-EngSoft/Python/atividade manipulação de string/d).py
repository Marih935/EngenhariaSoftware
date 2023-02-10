#Frase na diagonal invertida
frase = 'Boa tarde'
tamanho = len(frase)
espaço = ' '
for i in range(0,tamanho):
    espaço = espaço + ' '

for i in range(0,tamanho):
    letra = frase[i]
    print(espaço,letra)
    espaço = espaço[0:tamanho-i]


#Correção
frase = 'Diagonal inversa'
tamanho = len(frase)
branco = ' '
for i in range(0, tamanho):
    branco = branco + ' '

for i in range(0,tamanho):
    letra = frase[i]
    print(branco,letra)
    branco = branco[0:tamanho-i]