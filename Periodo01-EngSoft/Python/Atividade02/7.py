aprovados = 0
import random
for i in range(20):
    média = int(input('Digite a média do aluno:\n'))
    if média >= 7:
        aprovados = aprovados + 1
print(aprovados, 'alunos foram aprovados')