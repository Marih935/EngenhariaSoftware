#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTEIRO int
#define PONTEIRO_PARA_NODE *NODE

typedef struct aluno {
    INTEIRO identificador;
    char *nome;
    char *matricula;
    INTEIRO idade;
    INTEIRO periodo;
    INTEIRO curso;
} REGISTRO_ALUNO;

typedef struct node {
    REGISTRO_ALUNO *dado;
    struct node *esquerda;
    struct node *direita;
    struct node *pai;
} NODE;

typedef struct arvore_bin {
    INTEIRO identificador;
    INTEIRO qtdElementos;
    NODE *raiz;
} ARVORE_BIN;

typedef struct fila {
    NODE *vetor;
    int tamanho;
    int inicio;
    int fim;
} FILA;

FILA *criarFila() {
    FILA *fila = (FILA*) malloc(sizeof(FILA));
    fila->vetor = (NODE*) malloc(sizeof(NODE) * 100);
    fila->tamanho = 100;
    fila->inicio = 0;
    fila->fim = 0;
    return fila;
}

void enfileirar(FILA *fila, NODE *valor) {
    if (fila->fim == fila->tamanho) {
        fila->tamanho *= 2;
        fila->vetor = (NODE*) realloc(fila->vetor, sizeof(NODE) * fila->tamanho);
        }
        fila->vetor[fila->fim++] = *valor;
}

NODE *desenfileirar(FILA *fila) {
    return fila -> vetor + fila->inicio++;
}

int filaVazia(FILA *fila) {
    return fila->inicio == fila->fim;
}

void destruirFila(FILA *fila) {
    free(fila->vetor);
    free(fila);
}

NODE *criarNovoNo(REGISTRO_ALUNO *aluno) {
    NODE *novoNo = (NODE*) malloc(sizeof(NODE));
    novoNo->dado = aluno;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->pai = NULL;
    return novoNo;
}

ARVORE_BIN *criarArvore() {
    ARVORE_BIN *arvore = (ARVORE_BIN*) malloc(sizeof(ARVORE_BIN));
    arvore->identificador = 0;
    arvore->qtdElementos = 0;
    arvore->raiz = NULL;
    return arvore;
}

void adicionar(ARVORE_BIN *arvore, REGISTRO_ALUNO *aluno) {
    NODE *novoNo = criarNovoNo(aluno);
    if (arvore->raiz == NULL) {
        arvore->raiz = novoNo;
    } else {
        NODE *atual = arvore->raiz;
        NODE *anterior;
        while (atual != NULL) {
        anterior = atual;
        if (aluno->identificador < atual->dado->identificador) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
        }
        if (aluno->identificador < anterior->dado->identificador) {
        anterior->esquerda = novoNo;
        } else {
        anterior->direita = novoNo;
        }
        novoNo->pai = anterior;
    }
    arvore->qtdElementos++;
}

NODE *buscar(ARVORE_BIN *arvore, INTEIRO identificador) {
    NODE *atual = arvore->raiz;
    while (atual != NULL) {
        if (identificador == atual->dado->identificador) {
        return atual;
        } else if (identificador < atual->dado->identificador) {
        atual = atual->esquerda;
        } else {
        atual = atual->direita;
        }
    }
    return NULL;
}

void remover(ARVORE_BIN *arvore, INTEIRO identificador) {
    NODE *no = buscar(arvore, identificador);
    if (no != NULL) {
        if (no->esquerda == NULL && no->direita == NULL) {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        } else {
            no->pai->direita = NULL;
        }
        } else if (no->esquerda == NULL || no->direita == NULL) {
        if (no->esquerda == NULL) {
            if (no->pai->esquerda == no) {
            no->pai->esquerda = no->direita;
            } else {
            no->pai->direita = no->direita;
            }
            no->direita->pai = no->pai;
        } else {
            if (no->pai->esquerda == no) {
            no->pai->esquerda = no->esquerda;
            } else {
            no->pai->direita = no->esquerda;
            }
            no->esquerda->pai = no->pai;
        }
        } else {
        NODE *sucessor = no->direita;
        while (sucessor->esquerda != NULL) {
            sucessor = sucessor->esquerda;
        }
        if (sucessor->pai->esquerda == sucessor) {
            sucessor->pai->esquerda = sucessor->direita;
        } else {
            sucessor->pai->direita = sucessor->direita;
        }
        if (sucessor->direita != NULL) {
            sucessor->direita->pai = sucessor->pai;
        }
        sucessor->pai = no->pai;
        sucessor->esquerda = no->esquerda;
        sucessor->direita = no->direita;
        if (no->pai->esquerda == no) {
            no->pai->esquerda = sucessor;
        } else {
            no->pai->direita = sucessor;
        }
        no->esquerda->pai = sucessor;
        no->direita->pai = sucessor;
        }
        free(no);
        arvore->qtdElementos--;
        }
}

void limpar(ARVORE_BIN *arvore) {
    FILA *fila = criarFila();
    enfileirar(fila, arvore->raiz);
    while (!filaVazia(fila)) {
        NODE *no = desenfileirar(fila);
        if (no->esquerda != NULL) {
        enfileirar(fila, no->esquerda);
        }
        if (no->direita != NULL) {
        enfileirar(fila, no->direita);
        }
        free(no);
    }
    destruirFila(fila);
    arvore->raiz = NULL;
    arvore->qtdElementos = 0;
}

void imprimirOrdenado(ARVORE_BIN *arvore) {
    FILA *fila = criarFila();
    enfileirar(fila, arvore->raiz);
    while (!filaVazia(fila)) {
        NODE *no = desenfileirar(fila);
        printf("%d ", no->dado->identificador);
        if (no->esquerda != NULL) {
        enfileirar(fila, no->esquerda);
        }
        if (no->direita != NULL) {
        enfileirar(fila, no->direita);
        }
    }
    destruirFila(fila);
}

void imprimirEsparsa(ARVORE_BIN *arvore) {
    FILA *fila = criarFila();
    enfileirar(fila, arvore->raiz);
    while (!filaVazia(fila)) {
        NODE *no = desenfileirar(fila);
        if (no->esquerda != NULL) {
        enfileirar(fila, no->esquerda);
        }
        if (no->direita != NULL) {
        enfileirar(fila, no->direita);
        }
        printf("%d ", no->dado->identificador);
    }
    destruirFila(fila);
}

void profundidade(ARVORE_BIN *arvore) {
    FILA *fila = criarFila();
    enfileirar(fila, arvore->raiz);
    while (!filaVazia(fila)) {
        NODE *no = desenfileirar(fila);
        if (no->esquerda != NULL) {
        enfileirar(fila, no->esquerda);
        }
        if (no->direita != NULL) {
        enfileirar(fila, no->direita);
        }
        printf("%d ", no->dado->identificador);
    }
    destruirFila(fila);
}

int main() {
    ARVORE_BIN *arvore = criarArvore();
    adicionar(arvore, 10);
    adicionar(arvore, 5);
    adicionar(arvore, 15);
    adicionar(arvore, 3);
    adicionar(arvore, 7);
    adicionar(arvore, 12);
    adicionar(arvore, 18);
    adicionar(arvore, 1);
    adicionar(arvore, 4);
    adicionar(arvore, 6);
    adicionar(arvore, 8);
    adicionar(arvore, 11);
    adicionar(arvore, 13);
    adicionar(arvore, 16);
    adicionar(arvore, 19);
    adicionar(arvore, 2);
    adicionar(arvore, 9);
    adicionar(arvore, 14);
    adicionar(arvore, 17);
    adicionar(arvore, 20);
    printf("Lista Ordenada");
    imprimirOrdenado(arvore);
    printf("Lista Esparsa");
    imprimirEsparsa(arvore);
    printf("Profundidade da Lista");
    profundidade(arvore);
    printf("Removendo o 10, 5 e 15");
    remover(arvore, 10);
    remover(arvore, 5);
    remover(arvore, 15);
    printf("Lista Ordenada");
    imprimirOrdenado(arvore);
    printf("Lista Esparsa");
    imprimirEsparsa(arvore);
    printf("Profundidade da Lista");
    profundidade(arvore);
    printf("Inserindo o 10, 5 e 15");
    adicionar(arvore, 10);
    adicionar(arvore, 5);
    adicionar(arvore, 15);
    printf("Lista Ordenada");
    imprimirOrdenado(arvore);
    printf("Lista Esparsa");
    imprimirEsparsa(arvore);
    printf("Profundidade da Lista");
    profundidade(arvore);
    printf("Limpando a Lista");
    limpar(arvore);
    printf("Lista Ordenada");
    imprimirOrdenado(arvore);
    printf("Lista Esparsa");
    imprimirEsparsa(arvore);
    printf("Profundidade da Lista");
    profundidade(arvore);
}