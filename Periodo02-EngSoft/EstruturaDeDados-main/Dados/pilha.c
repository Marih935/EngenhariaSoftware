#include <stdio.h>

struct NODE{ //cada elemento da pilha = nó
    int numero; //amazenar números da pilha
    struct NODE *ponteiro; //ponteiro para começo da pilha
};

typedef struct NODE node; //definindo estrutura

int tamanho_pilha;



void INICIAR_PILHA(node *PILHA); //iniciar a pilha apontando para NULL(vazio)
int OPCOES(void); //escolher a ação quanto a pilha para o usuário
void OPCOES_PART2(node *PILHA, int numero_usuario); //interação usuário e pilha
void EXIBIR(node *PILHA); //exibe valores da pilha
void LIBERAR(node *PILHA); //libera espaço de memória
void PUSH(node *PILHA); //adiciona valor na pila
node *pop(node *PILHA); //remover último valor da pilha

int main(void){
    node *PILHA = (node*)malloc(sizeof(node)); //chama pilha(base)
    if(!PILHA){
        printf("Sem memória\n");
        exit(1); //finaliza função
    }else{
        INICIAR_PILHA(PILHA);
        int escolha_usuario;

        do{
            escolha_usuario=OPCOES();
            OPCOES_PART2(PILHA,escolha_usuario);
        }while(escolha_usuario);
        free(PILHA); //liberar armazenamento
        return 0;
    }
}


void INICIAR_PILHA(node *PILHA){
    PILHA->numero = NULL;
    tamanho_pilha = 0; //posição inicial da pilha
}


int OPCOES(void){
    int escolha_usuario;

    printf("Digite um número equivalente à ação desejada:\n");
    printf("0 - Sair\n");
    printf("1 - Zerar pilha\n");
    printf("2 - Exibir pilha\n");
    printf("3 - push/adicionar elemento\n");
    printf("4 - pop/remover elemento\n");
    printf("Ecolha: "); 
    scanf("%d", &escolha_usuario);

    return escolha_usuario;
}


void OPCOES_PART2(node *PILHA, int numero_usuario){
    node*temporaria;
    switch(numero_usuario){ //para diminuir complexidade
        case 0:
        LIBERAR(PILHA);
        break;

        case 1:
        LIBERAR(PILHA);
        INICIAR_PILHA(PILHA);
        break;

        case 2:
        EXIBIR(PILHA);
        break;

        case 3:
        PUSH(PILHA);
        break;

        case 4:
        temporaria = pop(PILHA);
        if(temporaria != NULL)
        printf("Retirou: %d\n\n", temporaria->numero);
        break;

        default:
        printf("Comando incorreto\n\n");
    }
}


int teste_vazia(node*PILHA){ //testar se pilha está vazia
    if(PILHA->ponteiro == NULL)
    return 1;
    else
    return 0;
}

node*alocar_nos(){ //aloca na memória os nós da pilha
    node*memoria=(node*)malloc(sizeof(node));
    if(!memoria){
        printf("Sem memória suficiente\n");
        exit(1);
    }else{
        printf("Digite novo elemento para pilha: ");
        scanf("%d", &memoria->numero);
        return memoria;
    }
}


void EXIBIR(node *PILHA){
    if(teste_vazia(PILHA)){
        printf("A pilha está vazian\n\n");
        return;
    }

    node*temporaria2;
    temporaria2 = PILHA->ponteiro;
    printf("Pilha:");
    while(temporaria2 != NULL){
        printf("%5d", temporaria2->numero);
        temporaria2 = temporaria2->ponteiro;
    }
    printf("\n        ");
    int contador;
    for(contador=0;contador<tamanho_pilha;contador++)
        printf("  ^  ");
    printf("\nOrdem:");
    for(contador=0;contador<tamanho_pilha;contador++)
        printf("%5d", contador+1);

    printf("\n\n");
}


void LIBERAR(node *PILHA){
    if(!teste_vazia(PILHA)){
        node*proximoNode,*atualNode;
        atualNode = PILHA->ponteiro;
        while(atualNode != NULL){
            proximoNode = atualNode->ponteiro;
            free(atualNode);
            atualNode = proximoNode;
        }
    }
}


void PUSH(node *PILHA){
    node*novoNumero = alocar_nos();
    novoNumero->ponteiro = NULL;
    if(teste_vazia(PILHA))
        PILHA->ponteiro=novoNumero;
    else{
        node*temporaria3 = PILHA->ponteiro;

        while(temporaria3->ponteiro != NULL)
            temporaria3 = temporaria3->ponteiro;
        temporaria3->ponteiro = novoNumero;
    }
    tamanho_pilha++;
}


node *pop(node *PILHA){
    if(PILHA->ponteiro==NULL){
        printf("A pilha já está vazia\n\n");
        return NULL;
    }else{
        node*ultimoElemento = PILHA->ponteiro,*penultimoElemento = PILHA;
        while(ultimoElemento->ponteiro != NULL){
            penultimoElemento = ultimoElemento;
            ultimoElemento = ultimoElemento->ponteiro;
        }
        penultimoElemento->ponteiro = NULL;
        tamanho_pilha--;
        return ultimoElemento;
    }
}