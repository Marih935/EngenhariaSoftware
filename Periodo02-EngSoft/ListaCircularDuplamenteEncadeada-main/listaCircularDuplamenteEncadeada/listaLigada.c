#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
}REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox; //proxima posicao livre
}ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio; //primeiro elemento da lista
    int dispo; //primeira posicao disponivel
}LISTA;

void inicializarLista(LISTA *l){
    int i;
    for(i=0; i<MAX-1; i++)
        l->A[i].prox = i+1;
    l->A[MAX-1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanhoLista(LISTA *l){
    int i = l->inicio;
    int tam = 0;
    while(i != INVALIDO){
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}

void exibirLista(LISTA *l){
    int i = l->inicio;
    printf("Lista: \" ");
    while(i != INVALIDO){
        printf("%i ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}

//lista ordenada
int buscaSequencial(LISTA *l, TIPOCHAVE ch){
    int i = l->inicio;
    while(i != INVALIDO){
        if(ch == l->A[i].reg.chave) return i; 
        else i = l->A[i].prox;
    }
    return -1;
}

//função auxiliar
int obterNo(LISTA *l){ //retorna a primeira posicao disponivel
    int resultado = l->dispo;
    if(l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    return resultado;
}

int inserirElemListaOrd(LISTA *l, REGISTRO reg){
    if(l->dispo == INVALIDO) return 0;
    TIPOCHAVE ch = reg.chave;
    int ant = INVALIDO;
    int i = l->inicio;
    while(i != INVALIDO && l->A[i].reg.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    i = obterNo(l);
    l->A[i].reg = reg;
    if(ant == INVALIDO){
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return 1;
}

int excluirElemLista(LISTA *l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    while(i != INVALIDO && l->A[i].reg.chave < ch){
        ant = i;
        i = l->A[i].prox;
    }
    if(i == INVALIDO) return 0;
    if(ant == INVALIDO) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    l->A[i].prox = l->dispo;
    l->dispo = i;
    return 1;
}

void devolverNo(LISTA *l, int j){
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

void reinicializarLista(LISTA *l){
    inicializarLista(l);
}

int main(){
    LISTA l;
    inicializarLista(&l);
    REGISTRO reg;
    reg.chave = 10;
    inserirElemListaOrd(&l, reg);
    reg.chave = 20;
    inserirElemListaOrd(&l, reg);
    reg.chave = 30;
    inserirElemListaOrd(&l, reg);
    exibirLista(&l);
    printf("Tamanho: %i elementos na lista \n", tamanhoLista(&l));
}