#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* cria_lista(){
    return NULL;
}
Lista* inserir_lista(Lista* l,char palavra,int linha,int qnt){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->indice = palavra;
    novo->linha = linha;
    novo->qnt = qnt;
    novo->segundo_no = NULL;
    novo->prox = l;
    return novo;
}
Lista* inserir_lista2(Lista* k,char palavra,int linha,int qnt){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->indice = palavra;
    novo->linha = linha;
    novo->qnt = qnt;
    k->segundo_no = novo;
    return novo;
}

Lista* inserir_lista3(Lista* k,char palavra,int linha,int qnt){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->indice = palavra;
    novo->linha = linha;
    novo->qnt = qnt;
    novo->prox = k;
    return novo;
}

void mostra_lista(Lista* l,Lista* k){
    Lista* p;
    Lista* q;
    for(p=l;p!=NULL;p=p->prox){
        if(p->segundo_no!=NULL){
            printf("%c(%d|%d)",p->indice,p->linha,p->qnt);
            q = p->segundo_no;
            do{
                printf(",(%d|%d)",q->linha,q->qnt);
                q=q->segundo_no;
            }while(q!=NULL);

            /*for(q=p->segundo_no;q->segundo_no!=NULL;q=q->segundo_no){
                printf(",(%d|%d)",q->linha,q->qnt);
            }*/
            printf("\n");
        }
        else{
            printf("%c(%d|%d)\n",p->indice,p->linha,p->qnt);
        }
    }
}
void libera_lista(Lista* l,Lista* k){
    Lista* p = l;
    Lista* q = k;
    while(p!=NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int lista_vazia(Lista* l){
    return (l == NULL);
}

Lista* busca(Lista* l,char valor){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->indice == valor)
            return p;
    }
    return NULL;
}

int verifica(Lista* l,char valor){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->indice == valor)
            return 1;
    }
    return 0;
}

int verificaK(Lista* k,char valor){
    Lista* p;
    for(p=k;p!=NULL;p=p->prox){
        if(p->indice == valor)
            return 1;
    }
    return 0;
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

void ordenar_string(int n,char *palavra,int *linha,int *qnt){
    int i,j;
    int aux3,aux2;
    char aux;
    for(i=0;i<(n-1);i++){
        for(j=0;j<n-i-1;j++){
            if(palavra[j]>palavra[j+1]){
                aux=palavra[j];
                palavra[j]=palavra[j+1];
                palavra[j+1]=aux;

                aux2=linha[j];
                linha[j]=linha[j+1];
                linha[j+1]=aux2;

                aux3=qnt[j];
                qnt[j]=qnt[j+1];
                qnt[j+1]=aux3;
            }
        }
    }
}
