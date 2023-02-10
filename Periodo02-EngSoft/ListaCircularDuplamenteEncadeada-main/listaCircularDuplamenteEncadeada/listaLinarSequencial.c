//Lista linear sequencial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX+1];
    int nroElem;
}LISTA;

void inicializarLista(LISTA *l){
    l->nroElem = 0;
}

int tamanhoLista(LISTA *l){
    return l->nroElem;
}

void exibirLista(LISTA *l){
    int i;
    printf("Lista: \" ");
    for(i=0; i<l->nroElem; i++)
        printf("%i ", l->A[i].chave);
    printf("\"\n");
}


int buscaSequencial(LISTA *l, TIPOCHAVE ch){
    int i = 0;
    while(i < l->nroElem){
        if(ch == l->A[i].chave) return i; 
        else i++;
    }
    return -1;
}

//mais eficiente do que busca sequencial -> apenas 1 teste
int buscaSentinela(LISTA *l, TIPOCHAVE ch){
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) i++;
    if(i == l->nroElem) return -1;
    else return i;
}

int buscaBinaria(LISTA *l, TIPOCHAVE ch){
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem-1;
    while(esq <= dir){
        meio = (esq + dir)/2;
        if(ch == l->A[meio].chave) return meio;
        if(ch > l->A[meio].chave) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

//inserção em posição específica
int inserirPodEsp(LISTA *l, REGISTRO reg, int i){
    int j;
    if((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return 0;
    for(j = l->nroElem; j > i; j--) 
    l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return 1;
}

int inserirElemOrd(LISTA *l, REGISTRO reg){
    if(l->nroElem >= MAX) return 0;
    TIPOCHAVE ch = reg.chave;
    int i = l->nroElem;
    while(i > 0 && l->A[i-1].chave > ch){
        l->A[i] = l->A[i-1];
        i--;
    }
    l->A[i] = reg;
    l->nroElem++;
    return 1;
}

int excluirElem(LISTA *l, TIPOCHAVE ch){
    int pos, j;
    pos = buscaSequencial(l, ch);
    if(pos == -1) return 0;
    for(j = pos; j < l->nroElem-1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return 1;
}

void reinicializarLista(LISTA *l){
    l->nroElem = 0;
}