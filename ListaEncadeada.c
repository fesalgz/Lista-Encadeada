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

//func. que exibe os valores dos nós das list encad
//tbm vai receber um pont. do tipo nó que chama list_enc
void exibe(no *list_enc) {
    if (vazia(list_enc)){ //verifica se a lista está vazia
        printf("Mano, a lista não tem nada!\n\n");
        return; //finaliza o if
    }
//se a lista nao estiver vazia, vamos criar uma var. temporaria tipo nó de ponteiro
    no *tmp;
    tmp = list_enc -> prox; //temp vai receber nossa lista -> proximo elemento

    while (tmp != NULL){ //enquanto tmp for diferente de NULL
        printf("%d", tmp -> valor); // exibe o valor de tmp
        tmp = tmp -> prox; //tmp recebe o prox valor
    }
    printf("\n\n");
}

//func que insere um valor no inicio da lista
void insereInicio(no *list_enc) {
    no *novo = (no*)malloc(sizeof(no));
    /*vamos criar uma nova variavel que sera o novo nó, ele vai retornar um ponteiro
    para o nó e vamos utilizar o malloc que vai alocar a memoria para esse novo nó.
    o sizeof vai alocar o espaço necessario. Se a lista tiver varias variaveis, ele
    vai alocar a memoria para caber tudo.*/

    if(!novo) { //se nao tiver memoria disponivel
        printf("Sem memória disponivel!\n");
        exit(1); //faz o programa terminar a execução
    }
//caso tenha memória disponivel
    printf("Informe o valor: ");
    scanf("%d", &novo->valor); //le o valor do novo nó que o usuario digitou

    //criamos a "novacabeça" a list_enc proximo vai apontar para o novo
    no *oldHead = list_enc->prox;

    //pegamos a cabeça anterior , vamos apontar para o prox
    list_enc -> prox = novo;

    //vamos pegar a nossa lista proximo e apostar para o novo
    novo -> prox = oldHead;

}

