#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE *arquivo;
    /*arquivo = fopen ("teste.txt", "wt");
    if (arquivo == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       return 1;
    }
    char str[100],aux[100];
    printf("Entre com uma frase.\n");
    gets(str);
    fprintf(arquivo,"%s",str);
    printf ("Arquivo README criado com sucesso.\n");
    fclose (arquivo);*/
    int cont = 0,i=0,j,csh[20],linha = 0;
    char aux[1000],c,str[1000],let;
    for(i=0;i<20;i++){
        csh[i] = 0;
    }
	
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
    for(i=0;i<=tam;i++){
        if(str[i]!='\n'){
            printf("%c",str[i]);
        }
        else{
            printf(" Linha: %d\n",linha);
            linha++;
        }
        if(str[i]=='\0'){
            printf(" Linha: %d\n",linha);
        }
    }

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
                    aux[cont] = str[j];
                    str[j] = '*';
                }
            }
            cont++;
            if(str[i]=='>'){
                str[i]='*';
                linha++;
                cont--;
            }
        }
    }
    printf("\n");
    for(i=0;i<cont;i++){
        printf("String: %c ",aux[i]);
        printf("Quantidade: %d\n",csh[i]);
    }
    return 0;
}
