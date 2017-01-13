#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    FILE *arquivo;
    int cont = 0,i,j,csh[10000],linha = 0,line[10000];
    char aux[1000],c,str[1000],let;

    for(i=0;i<10000;i++){
        csh[i] = 0;
    }
    for(i=0;i<10000;i++){
        line[i] = 0;
    }
    printf("Testando Lista\n");
    Lista *l = cria_lista();

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
    printf("\n");
    for(i=0;i<cont;i++){
        l = inserir_lista(l,line[i],csh[i],aux[i]);
        printf("Linha: %d ",line[i]);
        printf("String: %c ",aux[i]);
        printf("Quantidade: %d\n",csh[i]);
    }

    mostra_lista(l);
    libera_lista(l);
    return 0;
}
