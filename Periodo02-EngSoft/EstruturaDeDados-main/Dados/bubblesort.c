#include <stdio.h>

void FuncBubbleSort (int lista[], int tamanho) {
    int i, contador, auxiliar;

    for (contador = 1; contador < tamanho; contador++) {
        for(i=0; i < tamanho - 1; i++){
            if (lista[i] > lista[i + 1]) {
                auxiliar = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = auxiliar;
            }
        }
    }
}

int main(){
    int lista[] = {1,6,3,2,8,10,7,5,9,4};
    int tamanho = (int) sizeof(lista);
    int i;
    FuncBubbleSort(lista,tamanho);
    for(i=0; i < 10; i++){
        printf("%d", lista[i]);
    }
    return 0;
}