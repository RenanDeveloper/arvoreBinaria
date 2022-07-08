#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct No *esquerda, *direita;
}No;

typedef struct{
    No *raiz;
}ArvoreBin;

void inserirEsquerda(No *no, int valor){
    if(valor != no->chave){
        if(valor < no->chave){
            if(no->esquerda == NULL){
                No *novo = (No*)malloc(sizeof(No));
                novo->chave = valor;
                novo->direita = NULL;
                novo->esquerda = NULL;
                no->esquerda = novo;
            }
            else{
                    inserirEsquerda(no->esquerda, valor);
            }
        }
        else{
            if(no->direita == NULL){
                No *novo = (No*)malloc(sizeof(No));
                novo->chave = valor;
                novo->direita = NULL;
                novo->esquerda = NULL;
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

}

void inserir(ArvoreBin *arvore, int valor){
    if(arvore->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->chave = valor;
        novo->direita = NULL;
        novo->esquerda = NULL;
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
