#Frase com vogais miúsculas
#Correção
frase = 'Gostaria de ir embora'
tamanho = len(frase)
for i in range(0,tamanho):
    letra = frase[i]
    if letra == 'a':
        letra = 'A'
    elif letra == 'e':
        letra = 'E'
    elif letra == 'i':
        letra = 'I'
    elif letra == 'o':
        letra = 'O'
    elif letra == 'u':
        letra = 'U'
    else:
        letra = letra
    print(letra, end = '')