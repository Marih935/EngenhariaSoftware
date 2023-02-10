#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTEIRO int
#define TIPO_IDENTIFICADOR INTEIRO

typedef struct aluno{
    TIPO_IDENTIFICADOR identificador;
    char* nome;
    char* matricula;
    int idade;
    int periodo_curso;
    int curso;
} REGISTRO_ALUNO;

#define CURSOS_TOTAL 6
char* CURSOS[CURSOS_TOTAL] = {"Informática", "Agroindústria", "Agropecuária", "Engenharia de Software", "Enfermagem", "Música"};

typedef struct node{
    REGISTRO_ALUNO* dado;
    struct node* esquerda;
    struct node* direita;
    struct node* pai;
} NODE;

typedef struct arvore_bin{
    TIPO_IDENTIFICADOR identificador;
    int qtdElementos;
    NODE* raiz;
} ARVORE_BIN;

void inicializar(ARVORE_BIN* arvore){
    arvore->identificador = 0;
    arvore->qtdElementos = 0;
    arvore->raiz = NULL;
}

void adiciona(ARVORE_BIN* arvore, REGISTRO_ALUNO* aluno){
    NODE* novo_node = (NODE*) malloc(sizeof(NODE));
    novo_node->dado = aluno;
    novo_node->esquerda = NULL;
    novo_node->direita = NULL;
    novo_node->pai = NULL;
    if(arvore->qtdElementos == 0){
        arvore->raiz = novo_node;
        arvore->qtdElementos++;
        return;
    }
    NODE* aux = arvore->raiz;
    while(1){
        if(aluno->identificador < aux->dado->identificador){
            if(aux->esquerda == NULL){
                aux->esquerda = novo_node;
                novo_node->pai = aux;
                arvore->qtdElementos++;
                return;
            }
            aux = aux->esquerda;
        }else{
            if(aux->direita == NULL){
                aux->direita = novo_node;
                novo_node->pai = aux;
                arvore->qtdElementos++;
                return;
            }
            aux = aux->direita;
        }
    }
}

void remove_node(ARVORE_BIN* arvore, NODE* node){
    if(node->esquerda == NULL && node->direita == NULL){
    if(node->pai != NULL){
    if(node->pai->esquerda == node)
    node->pai->esquerda = NULL;
    else
    node->pai->direita = NULL;
    }
    free(node);
    arvore->qtdElementos--;
    return;
}
if(node->esquerda != NULL && node->direita == NULL){
    if(node->pai != NULL){
    if(node->pai->esquerda == node)
    node->pai->esquerda = node->esquerda;
    else
    node->pai->direita = node->esquerda;
    }
    node->esquerda->pai = node->pai;
    free(node);
    arvore->qtdElementos--;
    return;
}
if(node->esquerda == NULL && node->direita != NULL){
    if(node->pai != NULL){
    if(node->pai->esquerda == node)
    node->pai->esquerda = node->direita;
    else
    node->pai->direita = node->direita;
    }
    node->direita->pai = node->pai;
    free(node);
    arvore->qtdElementos--;
    return;
}
if(node->esquerda != NULL && node->direita != NULL){
    NODE* sucessor = node->direita;
    while(sucessor->esquerda != NULL)
    sucessor = sucessor->esquerda;
    node->dado = sucessor->dado;
    remove_node(arvore, sucessor);
    }
}

void Remove(ARVORE_BIN* arvore, TIPO_IDENTIFICADOR identificador){
    NODE* aux = arvore->raiz;
    while(aux != NULL){
        if(aux->dado->identificador == identificador){
        remove_node(arvore, aux);
        return;
        }
        if(identificador < aux->dado->identificador)
        aux = aux->esquerda;
        else
        aux = aux->direita;
    }
}

void limpa(ARVORE_BIN* arvore){
    while(arvore->qtdElementos > 0)
    Remove(arvore, arvore->raiz->dado->identificador);
}

void imprimir_ordenado(NODE* node){
    if(node == NULL)
    return;
    imprimir_ordenado(node->esquerda);
    printf("Identificador: %d, Nome: %s, Matrícula: %s, Idade: %d, Período: %d, Curso: %s\n", node->dado->identificador, node->dado->nome, node->dado->matricula, node->dado->idade, node->dado->periodo_curso, CURSOS[node->dado->curso]);
    imprimir_ordenado(node->direita);
}

void imprimir_ordenado_arvore(ARVORE_BIN* arvore){
    imprimir_ordenado(arvore->raiz);
}

void imprimir_esparsa(NODE* node){
    if(node == NULL)
    return;
    printf("Identificador: %d, Nome: %s, Matrícula: %s, Idade: %d, Período: %d, Curso: %s\n", node->dado->identificador, node->dado->nome, node->dado->matricula, node->dado->idade, node->dado->periodo_curso, CURSOS[node->dado->curso]);
    imprimir_esparsa(node->esquerda);
    imprimir_esparsa(node->direita);
}

void imprimir_esparsa_arvore(ARVORE_BIN* arvore){
    imprimir_esparsa(arvore->raiz);
}

int calcular_profundidade(NODE* node){
    if(node == NULL)
    return 0;
    int esquerda = calcular_profundidade(node->esquerda);
    int direita = calcular_profundidade(node->direita);
    if(esquerda > direita)
    return esquerda+1;
    return direita+1;
}

int calcular_profundidade_arvore(ARVORE_BIN* arvore){
    return calcular_profundidade(arvore->raiz);
}

int main(){
    ARVORE_BIN* arvore = (ARVORE_BIN*) malloc(sizeof(ARVORE_BIN));
    inicializar(arvore);
    REGISTRO_ALUNO* aluno1 = (REGISTRO_ALUNO*) malloc(sizeof(REGISTRO_ALUNO));
    aluno1->identificador = 1;
    aluno1->nome = "João";
    aluno1->matricula = "123456";
    aluno1->idade = 21;
    aluno1->periodo_curso = 3;
    aluno1->curso = 0;
    adiciona(arvore, aluno1);
    REGISTRO_ALUNO* aluno2 = (REGISTRO_ALUNO*) malloc(sizeof(REGISTRO_ALUNO));
    aluno2->identificador = 2;
    aluno2->nome = "Maria";
    aluno2->matricula = "654321";
    aluno2->idade = 19;
    aluno2->periodo_curso = 1;
    aluno2->curso = 4;
    adiciona(arvore, aluno2);
    REGISTRO_ALUNO* aluno3 = (REGISTRO_ALUNO*) malloc(sizeof(REGISTRO_ALUNO));
    aluno3->identificador = 3;
    aluno3->nome = "José";
    aluno3->matricula = "987654";
    aluno3->idade = 20;
    aluno3->periodo_curso = 2;
    aluno3->curso = 1;
    adiciona(arvore, aluno3);
    REGISTRO_ALUNO* aluno4 = (REGISTRO_ALUNO*) malloc(sizeof(REGISTRO_ALUNO));
    aluno4->identificador = 4;
    aluno4->nome = "Ana";
    aluno4->matricula = "456789";
    aluno4->idade = 22;
    aluno4->periodo_curso = 4;
    aluno4->curso = 3;
    adiciona(arvore, aluno4);
    printf("Impressão em ordem:\n\n");
    imprimir_ordenado_arvore(arvore);
    printf("\nImpressão esparsa:\n\n");
    imprimir_esparsa_arvore(arvore);
    printf("\nProfundidade da árvore: %d\n", calcular_profundidade_arvore(arvore));
    Remove(arvore, 3);
    printf("\nImpressão em ordem após remoção de um elemento:\n\n");
    imprimir_ordenado_arvore(arvore);
    limpa(arvore);
    printf("\nImpressão em ordem após limpeza da árvore:\n");
    imprimir_ordenado_arvore(arvore);
}