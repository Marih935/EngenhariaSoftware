#include <stdio.h>

int FuncImprimirLista(int lista[], int tamanho){
    int i;
    for(i=0; i < tamanho; i++){
        printf("%d",lista[i]);
        if(i < tamanho - 1){
            printf("%s",",");
        }
    }
    printf("%s","\n");
}

//dividir lista
int funcMergeSeparar(int lista2[], int meio2, int tamanhoLista2){
    int i;
    int listaMenor[5];
    int listaMaior[5];

    for(i=0; i < tamanhoLista2; i++){
        if(lista2[i] < meio2){
        listaMenor[i] = lista2[i];
        }else{
        listaMaior[i] = lista2[i];
        }
    }

    int tamanhoListaMenor = (int) sizeof(listaMenor) / 4;
    int tamanhoListaMaior = (int) sizeof(listaMaior) / 4;
    int meioListaMenor = (int) tamanhoListaMenor / 2;
    int meioListaMaior = (int) tamanhoListaMaior /2;

    FuncImprimirLista(listaMenor, tamanhoListaMenor);
    FuncImprimirLista(listaMaior, tamanhoListaMaior);
}

funcMergeSeparar(listaMenor, meioListaMenor, tamanhoListaMenor);
funcMergeSeparar(listaMaior, meioListaMaior, tamanhoListaMaior);

int main(){
    int lista[10] = {1,6,3,2,8,10,7,5,9,4};
    
    int tamanhoLista = (int) (sizeof(lista) / 4);
    int meio = (int) (sizeof(lista) / 4) / 2;

    printf("%s", "Lista Desorganizada: \n");
    FuncImprimirLista(lista, tamanhoLista);

    funcMergeSeparar(lista, meio, tamanhoLista);
}