#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* cria_lista(){
    return NULL;
}
Lista* inserir_lista(Lista* l,int valor,int valor2,char letra){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = valor;
    novo->qnt = valor2;
    novo->letter = letra;
    novo->prox = l;
    return novo;
}
void mostra_lista(Lista* l){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        printf("%c:(%d|%d)\n",p->letter,p->linha,p->qnt);
    }
}
void libera_lista(Lista* l){
    Lista* p = l;
    while(p!=NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int lista_vazia(Lista* l){
    return (l == NULL);
}

Lista* busca(Lista* l,int valor){
    /*Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->info == valor)
            return p;
    }*/
    return NULL;
}

Lista* retira_lista(Lista* l,int valor){
    /*Lista* ant = NULL;
    Lista* p = l;
    while(p!=NULL && p->info!=valor){
        ant = p;
        p = p->prox;
    }
    if(p==NULL)
        return l;
    if(ant==NULL){
        l = p->prox;
    }
    else{
        ant->prox = p->prox;
    }
    free(p);*/
    return l;
}
