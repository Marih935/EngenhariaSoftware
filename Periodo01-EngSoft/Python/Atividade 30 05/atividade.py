arquivo = open("aluno.txt","r")
for linha in arquivo.readlines():
    print(linha) 
arquivo.close()