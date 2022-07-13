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

int main(){

    return 0;
}
