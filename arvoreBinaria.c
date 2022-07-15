#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct No *esquerda, *direita;
}No;

typedef struct{
    No *raiz;
}ArvoreBin;

ArvoreBin *criarArvore(){
    ArvoreBin *arvore = (ArvoreBin*)malloc(sizeof(ArvoreBin));
    arvore->raiz = NULL;
    return  arvore;
}

No *criarNo(int ch){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void inserirEsquerda(No *no, int valor){
    if(valor != no->chave){
        if(valor < no->chave){
            if(no->esquerda == NULL){
                No *novo = criarNo(valor);
                no->esquerda = novo;
            }
            else{
                    inserirEsquerda(no->esquerda, valor);
            }
        }
        else{
            if(no->direita == NULL){
                No *novo = criarNo(valor);
                no->direita = novo;
            }
            else{
                inserirDireita(no->direita, valor);
            }
        }
    }else{
        printf("negado, elemento existente");
    }
}

void inserirDireita(No *no, int valor){
    if(valor != no->chave){
        if(valor > no->chave){
            if(no->direita == NULL){
                No *novo = criarNo(valor);
                no->direita = novo;
            }
            else{
                inserirDireita(no->direita, valor);
            }
        }
        else{
            if(no->esquerda == NULL){
                No *novo = criarNo(valor);
                no->esquerda = novo;
            }
            else{
                inserirEsquerda(no->esquerda, valor);
            }
        }
    }else{
        printf("negado, elemento existente");
    }
}
//insere um novo nó na árvore
void inserir(ArvoreBin *arvore, int valor){
    if(arvore->raiz == NULL){
        No *novo = criarNo(valor);
        arvore->raiz = novo;
    }else{
        if(valor < arvore->raiz->chave)
            inserirEsquerda(arvore->raiz, valor);
        else
            inserirDireita(arvore->raiz, valor);
    }
}
//imprime os nós, recursivamente, de forma ordenada
void imprimirOrdem(No *no){
    if(no != NULL){
        imprimirOrdem(no->esquerda);
        printf("%d ",no->chave);
        imprimirOrdem(no->direita);
    }
}
//imprime os nós, recursivamente, em pre-ordem
void imprimirPreOrdem(No *no){
    if(no != NULL){
        printf("%d ",no->chave);
        imprimirPreOrdem(no->esquerda);
        imprimirPreOrdem(no->direita);
    }
    
}
//imprime os nós, recursivamente, em pos-ordem
void imprimirPosOrdem(No *no){
    if(no != NULL){
        imprimirPosOrdem(no->esquerda);
        imprimirPosOrdem(no->direita);
        printf("%d ",no->chave);
    }
}
//imprime a Árvore completa na ordem escolhida pelo usuário
void imprimirArvore(ArvoreBin *arvore){
    if(arvore->raiz == NULL){
        printf("\nArvore vazia\n");
    }else{
        int ordem;
        printf("\nEscolha a ordem de impressao:\n1 - Arvore ordenada\n2 - Arvore em pre-ordem\n3 - Arvore em pos-ordem\n");
        scanf("%d", &ordem);
        if(ordem == 1)
            imprimirOrdem(arvore->raiz);
        else if(ordem == 2)
            imprimirPreOrdem(arvore->raiz);
        else if(ordem == 3)
            imprimirPosOrdem(arvore->raiz);
        else
            printf("\nValor invalido, escolha\n1 - Arvore ordenada\n2 - Arvore em pre-ordem\n3 - Arvore em pos-ordem\n");  
    }
}

int main(){
    int menu, chave;

    ArvoreBin *arvore = criarArvore();

    while(menu != 9){
        printf("\n1 - Inserir no na arvore\n2 - Imprimir arvore\n9 - Sair\n");
        scanf("%d", &menu);

        switch(menu){
        case 1:
            printf("Digite o valor da chave: ");
            scanf("%d", &chave);
            inserir(arvore, chave);
            break;
        case 2:
            printf("\nImprimir arvore binaria:\n");
            imprimirArvore(arvore);
            break;
        case 9:
            printf("\nFechando programa...\n");
            break;
        default:
            printf("\nOpção invalida, escolha entre uma das opcoes\n");
        }
    }

    return 0;
}
