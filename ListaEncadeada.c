#include <stdio.h>
#include <stdlib.h> //para utilizar funções como: malloc(), free() e exit().

struct estrutura_no {
    int valor; //armazena um valor inteiro no nó
    struct estrutura_no *prox; //estrutura _no que é um ponteiro apontando para o prox nó da lista encad.
};

typedef struct estrutura_no no; //define um apelido para a estrutura_no facilitando sua utilização

//funcao que verificará se a lista esta vazia ou não, ela vai receber um ponteiro do tipo nó que chamaremos List_Enc
//Verificar se o proximo elemento da lista é NULL
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

//funcao para liberar a memoria alocada para os nós da lista encadeada
void libera(no *list_enc){
    if(!vazia(list_enc)) { //se a lista não estiver vazia antes de liberar a memória
        no *proxNo, *atual; //criamos duas var. do tipo ponteiro para nó
        atual = list_enc -> prox; //
        while(atual != NULL) { //enquanto o atual for diferente de null
            proxNo = atual -> prox;
            free(atual);
            atual = proxNo;
        }
    }
}
