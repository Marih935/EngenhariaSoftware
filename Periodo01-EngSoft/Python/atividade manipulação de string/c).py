#Frase na ordem inversa
frase = 'Bom dia'
tamanho = len(frase)
aux = tamanho - 1
for i in range(0,tamanho):
    letra = frase[aux]
    print(letra, end = '')
    aux = aux - 1

#Correção
#frase = 'Belo Jardim'
#tamanho = len(frase)
#temp = tamanho-1
#for i in range(0,tamanho):
#    letra = frase[temp]
#    print(letra, end = '')
#    temp = temp-1