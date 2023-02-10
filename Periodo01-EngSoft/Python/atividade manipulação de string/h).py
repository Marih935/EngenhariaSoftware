#Ler 2 palavras, se a primeira estiver na frase, substitua pela segunda
palavra1 = input('Digite uma palavra: ')
palavra2 = input('Digite outra palavra: ')
frase = input('Digite uma frase: ')
tamanho = len(frase)
frasenova = str()
teste = str()
for i in range (0,tamanho):
    letra = frase[i]
    if letra == ' ' or i == (tamanho - 1):
        if i == (tamanho - 1):
            teste += letra
            if palavra1 == teste:
                frasenova += ' ' + palavra2
            else:
                frasenova += ' ' + teste
        else:    
            if palavra1 == teste:
                frasenova += ' ' + palavra2
                teste = ''
            else:
                frasenova += ' ' + teste
                teste = ''
    if letra != ' ':
        teste += letra
print(frasenova)