#include <stdio.h>

#define MAX 10

int ordenar(int array[], int n){
    int pos;
  int i;
    for (i = 0; i < MAX; i++) {
        if (array[i] == 0){
            pos = i;
            break;
        }
    }
    
    array[pos] = n;
    
    for (i = pos; i > 0; i--) {
        if (array[i] < array[i - 1]){
            int temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
        }
        else{
            break;
        }
    }
}

int main()
{
    int tamanho = 5;
    int lista[MAX] = {3, 5, 7, 8, 10};
    int resp = 1;
    while (resp == 1) {
        int valor;
        printf("Digite um número para adicionar na lista:\n");
        scanf("%d", &valor);
        
        ordenar(lista, valor);
        tamanho ++;
        
        if (tamanho == 10){
            break;
        }
        
        printf("Digite 1 para continuar ou 0 para parar...\n");
        scanf("%d", &resp);
    }

  int i;
    for (i = 0; i < MAX; i++){
        if (i == MAX - 1){
            printf("%d", lista[i]);
        }
        else{
            printf("%d, ", lista[i]);
        }
    }
    
    return 0;
}