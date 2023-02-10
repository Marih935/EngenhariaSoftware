#include <stdio.h>

int funcSlectionSort(int *lista, int tamanho){
  int i, j, menorValor, troca;
  //seleção menor valor
  for(i=0; i < tamanho; i++){
    menorValor = i;
    for(j = i + 1; j < tamanho; j++){
      if(lista[i] < lista[menorValor])
        menorValor = j;
    }
    if(i != menorValor){
      troca = lista[i];
      lista[i] = lista[menorValor];
      lista[menorValor] = troca;
    }
  }
}

int main(void) {
  int lista[] = {2,5,3,1,4};
  int tamanhoLista = (int) sizeof(lista) / 4;

  funcSlectionSort(lista, tamanhoLista);
}