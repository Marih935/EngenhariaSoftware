lista = ['Emma Frost','Kurt Wagner','Dick Garyson','Roberto da Costa','Alex Summers','Bruce Wayne','Lex Luthor','Hall Jordan','Cable','Vampira']
trocou = True
fim = len(lista)-1
while fim > 0 and trocou:
    trocou = False
    for i in range (fim):
        if lista[i] > lista[i+1]:
            trocou = True
            temp = lista[i]
            lista[i] = lista[i+1]
            lista[i+1] = temp
    fim = fim-1
print(lista)