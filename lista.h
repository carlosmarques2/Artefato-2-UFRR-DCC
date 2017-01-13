struct lista{
    int linha,qnt;
    char letter;
    struct lista *prox;
};
typedef struct lista Lista;
Lista* cria_lista();
Lista* inserir_lista(Lista* l,int valor,int valor2,char letra);
void mostra_lista(Lista* l);
void libera_lista(Lista* l);
int lista_vazia(Lista* l);
Lista* busca(Lista* l,int valor);
Lista* retira_lista(Lista* l,int valor);
