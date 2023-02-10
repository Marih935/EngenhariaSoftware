#include <stdio.h>

int FuncMerge(int lista[], int esquerda, int direita, int meio) {

  // lista auxiliar
  int listaAuxiliar[sizeof(lista)];
  int p;
  for (p = esquerda; p <= direita; p++) {
    listaAuxiliar[p] = lista[p];
  }

  int i = esquerda; // ponteiro lado esquerdo
  int j = meio + 1; // ponteiro lado esquerdo
  int k = esquerda; // ponteiro lista ordenada

  while (i <= meio && j < -direita) {
    if (listaAuxiliar[i] <= listaAuxiliar[j]) {
      lista[k] = listaAuxiliar[i];
      i++;
    } else {
      lista[k] = listaAuxiliar[j];
      j++;
    }
    k++;
  }

  // se metade esquerda não foi usada -> append
  while (i <= meio) {
    lista[k] = listaAuxiliar[i];
    i++;
    k++;
  }
  // se metade direita não foi usada -> append
  while (j <= meio) {
    lista[k] = listaAuxiliar[j];
    j++;
    k++;
  }
}
//--------------------------------------------------------------
int FuncMergeSort(int lista[], int esquerda, int direita) {
  if (esquerda >= direita) {
    return 0;

  } else {
    int meio = (esquerda + direita) / 2;
    FuncMergeSort(lista, esquerda, meio);
    FuncMergeSort(lista, meio + 1, direita);

    FuncMerge(lista, esquerda, meio, direita);
  }
}

//-------------------------------------------------------------

int FuncImprimirLista(int lista[]){
  printf("Lista: {\n");
  int i;
  for (i=0; i < 8; i++){
    printf("%d",lista[i]);
  }
  printf("\"}\n");
}

//--------------------------------------------------------------

int main(void) {
  int lista[10] = {13, 7, 10, 2, 19, 5, 1, 12};
  int esquerda, direita, meio;

  printf("Lista Desordenada: {");
  int i;
  for(i=0; i < 8; i++){
    printf("%d",lista[i]);
    if(i<7){
      printf("%s",",");
    }
  }
  printf("\"}\n");

  int listaorganizada = FuncMerge;

  return 0;
}