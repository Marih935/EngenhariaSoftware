Unidade = ['zero', 'um', 'dois', 'três', 'quatro', 'cinco', 'seis', 'sete', 'oito', 'nove']
Dezena = ['','dez','vinte', 'trinta','quarenta','cinquenta','sessenta','setenta','oitenta','noventa']
Centena = ['cem','cento','duzentos','trezentos','quatrossentos','quinhentos','seissentos','setessentos','oitossentos','novessentos']

#UNIDADE
def exibe_unidade(N):
    global Unidade
    print(Unidade[N],'', end = '')

#DEZENA
def exibe_dezena(N):
    global Unidade
    global Dezena
    global Numero
    global Tamanho

    if Tamanho >= 3:
        unidade = 2
    else:
        unidade = 1
    if Numero[unidade] == '0':
        print(Dezena[N],' ', end = '')
    elif Numero[unidade-1] != '1':
        print(Dezena[N],'', end = '')
        print('e ', end = '')
        exibe_unidade(Unidades)
    else:
        if Numero[unidade] == '1':
            print('onze', end = '')
        elif Numero[unidade] == '2':
            print('doze', end = '')
        elif Numero[unidade] == '3':
            print('treze', end = '')
        elif Numero[unidade] == '4':
            print('quatorze', end = '')
        elif Numero[unidade] == '5':
            print('quinze', end = '')
        elif Numero[unidade] == '6':
            print('dezesseis', end = '')
        elif Numero[unidade] == '7':
            print('dezessete', end = '')
        elif Numero[unidade] == '8':
            print('dezoito', end = '')
        else:
            print('dezenove', end = '')

#CENTENA
def exibe_centena(N):
    global Centena
    print(Centena[N],'', end = '')

#UNIDADE MILHAR
def exibe_unidademilhar(N):
    global Numero
    if N == 1:
        print('mil')
    else:
        print(Unidade[N],' mil', end = '')

#DEZENA MILHAR
def exibe_dezenamilhar(N):
    global Unidade
    global Dezena
    global Numero
    global Tamanho

    unidademilhar = Numero[Tamanho - 4]
    print(Numero[unidademilhar])
    if Numero[unidademilhar] == '0':
        print(Dezena[N],' ', end = '')
    elif Numero[unidademilhar-1] != '1':
        print(Dezena[N],'', end = '')
        print('e ', end = '')
        exibe_unidade(Unidades)
    else:
        if Numero[unidademilhar] == '1':
            print('onze', end = '')
        elif Numero[unidademilhar] == '2':
            print('doze', end = '')
        elif Numero[unidademilhar] == '3':
            print('treze', end = '')
        elif Numero[unidademilhar] == '4':
            print('quatorze', end = '')
        elif Numero[unidademilhar] == '5':
            print('quinze', end = '')
        elif Numero[unidademilhar] == '6':
            print('dezesseis', end = '')
        elif Numero[unidademilhar] == '7':
            print('dezessete', end = '')
        elif Numero[unidademilhar] == '8':
            print('dezoito', end = '')
        else:
            print('dezenove', end = '')

#CENTENA MILHAR
def exibe_centenamilhar(N):
    global CentenaMilhar
    print(Centena[N],'', end = '')
    
Numero = input('Digite um número inteiro: ')
Tamanho = len(Numero)
if Tamanho == 6:
    CentenasMilhar = Numero[0]
    DezenasMilhar = Numero[1]
    UnidadesMilhar = Numero[2]
    Centenas = Numero[3]
    Dezenas = Numero[4]
    Unidades = Numero[5]
    CentenasMilhar = int(CentenasMilhar)
    DezenasMilhar = int(UnidadesMilhar)
    UnidadesMilhar = int(UnidadesMilhar)
    Centenas = int(Centenas)
    Dezenas = int(Dezenas)
    Unidades = int(Unidades)
elif Tamanho == 5:
    DezenasMilhar = Numero[0]
    UnidadesMilhar = Numero[1]
    Centenas = Numero[2]
    Dezenas = Numero[3]
    Unidades = Numero[4]
    DezenasMilhar = int(UnidadesMilhar)
    UnidadesMilhar = int(UnidadesMilhar)
    Centenas = int(Centenas)
    Dezenas = int(Dezenas)
    Unidades = int(Unidades)
elif Tamanho == 4:
    UnidadesMilhar = Numero[0]
    Centenas = Numero[1]
    Dezenas = Numero[2]
    Unidades = Numero[3]
    UnidadesMilhar = int(UnidadesMilhar)
    Centenas = int(Centenas)
    Dezenas = int(Dezenas)
    Unidades = int(Unidades)
elif Tamanho == 3:
    Centenas = Numero[0]
    Dezenas = Numero[1]
    Unidades = Numero[2]
    Centenas = int(Centenas)
    Dezenas = int(Dezenas)
    Unidades = int(Unidades)
elif Tamanho == 2:
    Dezenas = Numero[0]
    Unidades = Numero[1]
    Dezenas = int(Dezenas)
    Unidades = int(Unidades)
else:
    Unidades = Numero[0]
    Unidades = int(Unidades)


if Tamanho == 1:
    exibe_unidade(Unidades)
elif Tamanho == 2:
    exibe_dezena(Dezenas)
elif Tamanho == 3:
    exibe_centena(Centenas)
    print('e ', end = '')
    exibe_dezena(Dezenas)
elif Tamanho == 4:
   exibe_unidademilhar(UnidadesMilhar)