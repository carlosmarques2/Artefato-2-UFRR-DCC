#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    printf("Testanto Lista!\n");
    FILE *arquivo;
    int cont = 0,i=0,j=0,csh[10000],linha = 0,line[10000];
    int cont_lista = 0;//Contador de Listas Auxiliares
    char aux[1000],c,str[1000],let;
    //Lista** vetor =(Lista**) malloc(sizeof(Lista)*100);
    for(i=0;i<10000;i++){
        csh[i] = 0;
    }
    for(i=0;i<10000;i++){
        line[i] = 0;
    }
    Lista *l = cria_lista();
    Lista *k = cria_lista();
    k = inserir_lista3(k,' ',1,1);
    arquivo = fopen("teste.txt", "rt");
    if (arquivo == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       return 1;
    }
    while(1){
        c = fgetc(arquivo);
        if(feof(arquivo)){
            break ;
        }
        printf("%c", c);
        if(c!=' '){
            str[cont] = c;
            cont++;
        }
    }
    fclose(arquivo);
    str[cont] = '>';
    str[cont+1] = '\0';
    printf("\nTestando String\n");
    int tam = strlen(str);
    printf("Tamanho: %d\n",tam);
    printf("\n");
    for(i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }

    printf("\n\n");

    for(i=0;i<tam;i++){
        if(str[i]=='\n')
            str[i] = '>';
    }

    for(i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    cont = 0;
    for(i=0;i<tam;i++){
        if(str[i]!='*'){
            let = str[i];
            for(j=0;str[j]!='>';j++){
                if(let==str[j]){
                    csh[cont]++;
                    line[cont] = linha;
                    aux[cont] = str[j];
                    str[j] = '*';
                }
            }
            cont++;
            if(str[i]=='>'){
                cont--;
                str[i]='/';
                linha++;
            }
        }
    }

    for(i=0;i<cont;i++){
        printf("Linha: %d ",line[i]);
        printf("String: %c ",aux[i]);
        printf("Quantidade: %d\n",csh[i]);
    }
    ordenar_string(cont,aux,line,csh);
    printf("\n");
    for(i=0;i<cont;i++){
        if(verifica(l,aux[i])){
            if(k->indice==aux[i]){
                k = inserir_lista2(k,aux[i],line[i],csh[i]);
                k->segundo_no = NULL;
                //vetor[cont_lista-1] = k;
            }
            else{
                k = cria_lista();
                k = busca(l,aux[i]);
                k = inserir_lista2(k,aux[i],line[i],csh[i]);
                k->segundo_no = NULL;
                //vetor[cont_lista] = k;
                //cont_lista++;
            }
            printf("Linha: %d ",line[i]);
            printf("String: %c ",aux[i]);
            printf("Quantidade: %d\n",csh[i]);
        }
        else{
            l = inserir_lista(l,aux[i],line[i],csh[i]);
            printf("Linha: %d ",line[i]);
            printf("String: %c ",aux[i]);
            printf("Quantidade: %d\n",csh[i]);
        }
    }
    mostra_lista(l,k);
    libera_lista(l,k);
    return 0;
}
