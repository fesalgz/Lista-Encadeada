#include <stdio.h>
#include <stdlib.h> //para utilizar fun��es como: malloc(), free() e exit().

struct estrutura_no {
    int valor; //armazena um valor inteiro no n�
    struct estrutura_no *prox; //estrutura _no que � um ponteiro apontando para o prox n� da lista encad.
};

typedef struct estrutura_no no; //define um apelido para a estrutura_no facilitando sua utiliza��o

//funcao que verificar� se a lista esta vazia ou n�o, ela vai receber um ponteiro do tipo n� que chamaremos List_Enc
//Verificar se o proximo elemento da lista � NULL
int vazia(no *list_enc){
    if(list_enc -> prox = NULL){ //se a nossa list_enc o prox elemento dessa list estiver apontando para null
        return 1; //1 para vazia
    } else {
        return 0;//A lista nao esta vazia
    }
}

void inicia(no *list_enc){
    list_enc -> prox = NULL; //vamos fazer a list_enc apontar para NULL
}

//funcao para liberar a memoria alocada para os n�s da lista encadeada
void libera(no *list_enc){
    if(!vazia(list_enc)) { //se a lista n�o estiver vazia antes de liberar a mem�ria
        no *proxNo, *atual; //criamos duas var. do tipo ponteiro para n�
        atual = list_enc -> prox; //
        while(atual != NULL) { //enquanto o atual for diferente de null
            proxNo = atual -> prox;
            free(atual);
            atual = proxNo;
        }
    }
}
