#Número de palavras
#Correção
frase = 'Boa tarde, mas quero ir embora'
tamanho = len(frase)
espaço = 1
for i in range(0,tamanho):
    letra = frase[i]
    if letra == ' ':
        espaço = espaço + 1
print("Número de palavras =", espaço)