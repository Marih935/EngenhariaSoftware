#Informe quantas consoantes estão na frase
frase = input('Digite uma frase: ')
tamanho = len(frase)
consoantes = 0
for i in range(tamanho):
    letra = frase[i]
    if letra != 'a' and letra != 'A' and letra != 'e' and letra != 'E' and letra != 'i' and letra != 'I' and letra != 'o' and letra != 'O' and letra != 'u' and letra != 'U' and letra != ' ':
        consoantes += 1
print('Tem',consoantes,'consoantes')