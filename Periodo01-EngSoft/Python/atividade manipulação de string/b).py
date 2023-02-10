#Frase lida na diagonal
frase = 'Belo Jardim'
tamanho = len(frase)
for i in range(0,tamanho):
    espaço = '  '
    letra = frase[i]
    print(espaço * i, letra)

#Correção
#frase = 'Belo Jardim'
#branco = ' '
#tamanho = len(frase)
#for i in range(0,tamanho):
#    letra = frase[i]
#    print(branco, letra)
#    branco = branco + ' '