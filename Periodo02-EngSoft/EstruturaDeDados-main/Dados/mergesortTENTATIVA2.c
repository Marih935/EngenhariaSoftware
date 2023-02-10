#include <stdio.h>
#include <stdlib.h>

void funcMerge(int lista[], int i, int j, int k, int meio, int fim, int auxiliar[]){

    if(i<=meio && (j>fim||lista[i]<lista[j])){
        auxiliar[k] = lista[i];
        funcMerge(lista, j, i+1, k+1, meio, fim, auxiliar);

    }else if(j<=fim){
        auxiliar[k] = lista[j];
        funcMerge(lista, i, j+1, k+1, meio, fim, auxiliar);
    }
}

void funcMergeSort(int lista[], int inicio, int fim, int auxiliar[]){
    int meio = (inicio + fim) / 2;

    if(inicio < fim){
        funcMergeSort(lista, inicio, meio, auxiliar);
        funcMergeSort(lista, meio+1, fim, auxiliar);
        funcMerge(lista, inicio, meio, meio+1, fim, 0, auxiliar);

        int f;
        for(f=0; f<fim-inicio+1; f++){
            lista[inicio+1] = auxiliar[f];
        }
    }
}

void funcMergeSort2 (int lista[], int tamanho){
    int *auxiliar = malloc(sizeof(int)*tamanho);
    funcMergeSort(lista, 0, tamanho, auxiliar);
    free(auxiliar);
}

int main(){
    int lista[] = {13, 7, 10, 2, 19, 5, 1, 12};
    
    printf("Lista Desordenada: {");
    int i;
    for(i=0; i < 8; i++){
        printf("%d",lista[i]);
        if(i<7){-
        printf("%s",",");
    }
  }

    funcMergeSort2(lista, 8);

    printf("Lista Ordenada: {");
    int g;
    for(g=0; g < 8; g++){
        printf("%d",lista[g]);
        if(g<7){
        printf("%s",",");
    }
  }

  printf("\"}\n");
}