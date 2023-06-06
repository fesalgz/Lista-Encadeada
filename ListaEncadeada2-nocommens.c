#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct estrutura_no{
	int valor;
	struct estrutura_no *prox;
};

typedef struct estrutura_no no;

int vazia(no *list_Enc){
	if(list_Enc -> prox == NULL){
		return 1;
	}else{
		return 0;
	}
}

void inicia(no *list_Enc){
	list_Enc->prox = NULL;
}

void libera(no *list_Enc){
	if(!vazia(list_Enc)){
		no *proxNo, *atual;
		atual = list_Enc->prox;
		while(atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = proxNo;
		}
	}
}

void exibe(no *list_Enc){
	if(vazia(list_Enc)){
		printf("Lista esta vazia!\n\n");
		return;
	}

	no *tmp;
	tmp = list_Enc->prox;

	while(tmp != NULL){
		printf("%d ", tmp->valor);
		tmp = tmp->prox;
	}

	printf("\n\n");
}

void insereInicio(no *list_Enc){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);
	no *oldHead = list_Enc->prox;
	list_Enc->prox = novo;
	novo->prox = oldHead;
}

void insereFim(no *list_Enc){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);
	novo->prox = NULL;
	if(vazia(list_Enc)){
		list_Enc->prox = novo;
	}else{
		no *tmp = list_Enc->prox;
		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
}

void opcao(no *list_Enc, int op){
    switch(op){
		case 0:
			libera(list_Enc);
			break;
		case 1:
			exibe(list_Enc);
			break;
		case 2:
			insereInicio(list_Enc);
			break;
		case 3:
			insereFim(list_Enc);
			break;
		case 4:
			inicia(list_Enc);
			break;
		default:
			printf("Comando inválido\n\n");

	}
}

int menu(){

	int opt;

	printf("Escolha a opcao: \n");
	printf("[0] - Sair: \n");
	printf("[1] - Exibir: \n");
	printf("[2] - Adicionar no no inicio: \n");
	printf("[3] - Adicionar no no fim: \n");
	printf("[4] - Zerar lista: \n");
	printf("Opcao: ");
	scanf("%d", &opt);

	return opt;
}


//
int main(){


	no *list_Enc = (no*)malloc(sizeof(no));

	if(!list_Enc){
		printf("Sem memória disponível: ");
		exit(1);
	}
	inicia(list_Enc);
	int opt;

	do{
		opt=menu();
		opcao(list_Enc, opt);
	}while(opt);

	free(list_Enc);//

	return 0;
}
