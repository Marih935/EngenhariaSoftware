#include <stdio.h>
#include <stdlib.h>

void FuncMerge(int *lista, int inicio, int meio, int fim){
    int *temporaria, ponteiro1, ponteiro2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    ponteiro1 = inicio;
    ponteiro2 = meio + 1;
    temporaria = (int *) malloc(tamanho*sizeof(int));
    if(temporaria != NULL){
        for(i=0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(lista[ponteiro1] < lista[ponteiro2])
                    temporaria[i] = lista[ponteiro1++];
                else
                    temporaria[i] = lista[ponteiro2++];

                if(ponteiro1 > meio) fim1 = 1;
                if(ponteiro2 > fim) fim2 = 1;
            }else{
                if(!fim1)
                    temporaria[i] = lista[ponteiro1++];
                else
                    temporaria[i] = lista[ponteiro2++];
            }
        }
        for(j=0, k = inicio; j < tamanho; j++)
            lista[k] = temporaria[j];
    }
    free(temporaria);
}

void FuncMergeSort(int *lista, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (int) ((inicio + fim) / 2);
        FuncMergeSort(lista, inicio, meio);
        FuncMergeSort(lista, meio+1, fim);
        FuncMerge(lista, inicio, meio, fim);
    }
}

int main(){
    int lista[] = {1,6,3,2,8,10,7,5,9,4};
    int inicio = lista[0];
    int fim = lista[10];
    int i;

    FuncMergeSort(lista, inicio, fim);
    for(i=0; i < 10; i++){
        printf("%d", lista[i]);
    }
    return 0;
}