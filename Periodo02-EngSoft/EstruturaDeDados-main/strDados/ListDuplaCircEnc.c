#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* proximo;
    struct no* anterior;
} NO;

typedef struct lista{
    int tamanho;
    NO* inicio;
    NO* fim;
} LISTA;

LISTA* criar_lista(){
    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void inserir_inicio(LISTA* lista, int valor){
    NO* novo_no = (NO*) malloc(sizeof(NO));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = lista->fim;
    if(lista->tamanho == 0){
        lista->inicio = novo_no;
        lista->fim = novo_no;
        novo_no->proximo = novo_no;
        novo_no->anterior = novo_no;
    }else{
        lista->inicio->anterior = novo_no;
        lista->fim->proximo = novo_no;
        lista->inicio = novo_no;
    }
    lista->tamanho++;
}

void inserir_fim(LISTA* lista, int valor){
    NO* novo_no = (NO*) malloc(sizeof(NO));
    novo_no->valor = valor;
    novo_no->proximo = lista->inicio;
    novo_no->anterior = lista->fim;
    if(lista->tamanho == 0){
        lista->inicio = novo_no;
        lista->fim = novo_no;
        novo_no->proximo = novo_no;
        novo_no->anterior = novo_no;
    }else{
        lista->fim->proximo = novo_no;
        lista->inicio->anterior = novo_no;
        lista->fim = novo_no;
    }
    lista->tamanho++;
}

void remover_inicio(LISTA* lista){
    if(lista->tamanho == 0){
        printf("A lista está vazia!\n");
        return;
    }
    NO* aux = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->fim->proximo = lista->inicio;
    lista->inicio->anterior = lista->fim;
    free(aux);
    lista->tamanho--;
}

void remover_fim(LISTA* lista){
    if(lista->tamanho == 0){
    printf("A lista está vazia!\n");
    return;
    }
    NO* aux = lista->fim;
    lista->fim = lista->fim->anterior;
    lista->inicio->anterior = lista->fim;
    lista->fim->proximo = lista->inicio;
    free(aux);
    lista->tamanho--;
}

void imprimir_lista(LISTA* lista){
    if(lista->tamanho == 0){
    printf("A lista está vazia!\n");
    return;
    }
    NO* aux = lista->inicio;
    printf("Lista: ");
    do{
        printf("%d ", aux->valor);
        aux = aux->proximo;
        }while(aux != lista->inicio);
            printf("\n");
}

int main(){
LISTA* lista = criar_lista();
inserir_inicio(lista, 1);
imprimir_lista(lista);
inserir_inicio(lista, 2);
imprimir_lista(lista);
inserir_fim(lista, 3);
imprimir_lista(lista);
inserir_fim(lista, 4);
imprimir_lista(lista);
remover_inicio(lista);
imprimir_lista(lista);
remover_fim(lista);
imprimir_lista(lista);
}