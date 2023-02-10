#Add
arquivo=open("aluno.txt","a")
num = 0
for linha in range(1,101):
    num = num + 1
    palavra = str(num)
    arquivo.write("%s\n" % palavra)

arquivo.close()

#Read
arquivo=open("alunos.py","r")
for linha in arquivo.readlines():
    print(linha) 
arquivo.close()

#Criar
arquivo=open("num.pdf","w")
palavra = 'Eu amo programação'
arquivo.write("%s\n" % palavra)

arquivo.close()

#Ordenar
arquivo = open("arquivo.txt","r")
Lista = []
for linha in arquivo.readlines():
    Lista = Lista + [linha]
arquivo.close()
Lista.sort()
tamanho = len(Lista)
arquivo.close()
saida = open("arquivo_ordenado.txt","w")
for i in range(tamanho):
    palavra = Lista[i]
    print(palavra)
    if palavra[0] != ' ':
       saida.write("%s\n" % palavra)

saida.close()