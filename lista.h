/*typedef struct dicionario{
	char palavra[100];
	int linha[10000],qnt[10000];
}Dicionario;*/

struct lista{
    char indice;
    int linha,qnt;
    struct lista *prox;
    struct lista *segundo_no;
};
typedef struct lista Lista;
Lista* cria_lista();
Lista* inserir_lista(Lista* l,char palavra,int linha,int qnt);
Lista* inserir_lista2(Lista* k,char palavra2,int linha2,int qnt2);
Lista* inserir_lista3(Lista* k,char palavra2,int linha2,int qnt2);
void mostra_lista(Lista* l,Lista* k);
void libera_lista(Lista* l,Lista* k);
int lista_vazia(Lista* l);
int verificaK(Lista* k,char valor);
Lista* busca(Lista* l,char valor);
int verifica(Lista* l,char valor);
Lista* retira_lista(Lista* l,int valor);
void ordenar_string(int n,char *palavra,int *linha,int *qnt);
