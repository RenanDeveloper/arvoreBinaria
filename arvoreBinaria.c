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

}
