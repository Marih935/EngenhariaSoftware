#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define INVALIDO -1

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

void inserirInicio(Lista *l, int ch){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    novo->prox = l->inicio;
    l->inicio = novo;
    if(l->fim == NULL) l->fim = novo;
    l->tam++;
}

void inserirFim(Lista *l, int ch){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    novo->prox = NULL;
    if(l->fim != NULL) l->fim->prox = novo;
    l->fim = novo;
    if(l->inicio == NULL) l->inicio = novo;
    l->tam++;
}

void inserirOrdenado(Lista *l, int ch){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    if(l->inicio == NULL){
        novo->prox = NULL;
        l->inicio = novo;
        l->fim = novo;
    }else{
        No *aux = l->inicio;
        No *ant = NULL;
        while(aux != NULL && aux->chave < ch){
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            novo->prox = l->inicio;
            l->inicio = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
        if(aux == NULL) l->fim = novo;
    }
    l->tam++;
}

int remover(Lista *l, int ch){
    No *aux = l->inicio;
    No *ant = NULL;
    while(aux != NULL && aux->chave != ch){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL) return INVALIDO;
    if(ant == NULL) l->inicio = aux->prox;
    else ant->prox = aux->prox;
    if(aux->prox == NULL) l->fim = ant;
    free(aux);
    l->tam--;
    return ch;
}

int buscar(Lista *l, int ch){
    No *aux = l->inicio;
    while(aux != NULL && aux->chave != ch){
        aux = aux->prox;
    }
    if(aux == NULL) return INVALIDO;
    return aux->chave;
}

void imprimirLista(Lista *l){
    No *aux = l->inicio;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n\n");
}

int main(){
    Lista l;
    inicializarLista(&l);
    inserirInicio(&l, 10);
    inserirInicio(&l, 20);
    inserirInicio(&l, 30);
    inserirFim(&l, 40);
    inserirFim(&l, 50);
    inserirFim(&l, 60);
    inserirOrdenado(&l, 25);
    inserirOrdenado(&l, 35);
    inserirOrdenado(&l, 45);
    imprimirLista(&l);
    remover(&l, 10);
    remover(&l, 20);
    remover(&l, 30);
    remover(&l, 40);
    remover(&l, 50);
    remover(&l, 60);
    imprimirLista(&l);
    printf("Busca: %d \n", buscar(&l, 25));
}