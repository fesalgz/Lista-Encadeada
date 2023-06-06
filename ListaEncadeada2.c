/*
lista encadeada - Lista ligada - listas - Linked List

A lista encadeada possui além do seu valor,
um ponteiro apontando para o próximo elemento

esse elemento, ele tem o valor 1
se não tiver sem uma outra lista ele vai apontar para NULL
----
[1] | -> NULL
----

Essa lista anterior - aponta para essa nova - e essa nova lista aponta para NULL
----     ----
[1] | -> [4] | -> NULL
----     ----

Vamos adicionar um novo elemento na lista
Esse 7 vai apontar para NULL
Ela é encadeada por que dentro dos valores dela
além dos valores tem um ponteiro - apontando para o proximo elemento da lista
se for o ultimo vai apontar para NULL
----     ----      ----
[1] | -> [4] | -> [7] | -> NULL
----     ----      ----
*/

#include <stdio.h>
#include <stdlib.h> //Inclui a biblioteca padrão para usar funções como malloc(), free() e exit().
#include <locale.h>

// Lista Encadeada
//                    ----
//cada elemento desse [1] |  é chamado de nó
//                    ----
struct estrutura_no{ //estrutura chamada no
	int valor; //Armazena um valor inteiro no nó.
	struct estrutura_no *prox;
	//estrutura_no que é um Ponteiro apontando para o próximo nó da lista encadeada.
};

typedef struct estrutura_no no;
//Define um apelido 'nó' para a estrutura estrutura_no,
//facilitando a utilização da estrutura no código.


//Essa função informará se a lista encadeada está vazia ou não.
// Ela vai receber um ponteiro do tipo nó que chamaremos list_Enc
int vazia(no *list_Enc){
	if(list_Enc -> prox == NULL){
//Se a nossa List_Enc se o proximo elemento da lista apontar para NULL,
//a lista está vazia.
		return 1;//Retorna 1 se a lista estiver vazia.
	}else{
		return 0;//Retorna 0 se a lista não estiver vazia.
	}
}//Se o proximo elemento da lista [1] | -> NULL



//Função 'inicia' que vai inicializar a lista encadeada,
// Também vai receber um ponteiro do tipo nó que chamaremos list_Enc
void inicia(no *list_Enc){
	list_Enc->prox = NULL;
	//Vamos fazer a List_Enc - apontar para NULL.
}//Ela vai inicializar vazia [1] | -> NULL



//Função 'libera' que libera a memória alocada para os nós da lista encadeada:
// Também vai receber um ponteiro do tipo nó que chamaremos list_Enc
void libera(no *list_Enc){  //estamos sempre recebendo o ponto para a List_Enc
	if(!vazia(list_Enc)){ //Se a lista não está vazia
		no *proxNo, *atual;
//criaremos duas variáveis do tipo ponteiro para nó: proxNo e atual.
		atual = list_Enc->prox;//O atual vai receber a nossa list_Enc proximo
		while(atual != NULL){ //Enquanto o atual for diferente de Null
			proxNo = atual->prox;//O próximo Nó vai receber o atual próximo
			free(atual);//Vamos liberar a memória alocada do nó atual.
			atual = proxNo;//E o Atual vai receber o próximo Nó.
		}
	}
}//com isso estamos zerando, estamos passando por cada um dos nós
//liberando a lista encadeada



//Função que exibe os valores dos nós da lista encadeada:
// Também vai receber um ponteiro do tipo nó que chamaremos list_Enc
void exibe(no *list_Enc){
	if(vazia(list_Enc)){ //Verifica se a lista está vazia
		printf("Lista esta vazia!\n\n");//Exibe uma mensagem se a lista estiver vazia.
		return; //finaliza não precisa por zero por ser void
	}
//Caso a lista não esteja vazia,
//vamos criar uma variável do tipo ponteiro para nó (tmp)
	no *tmp;
	tmp = list_Enc->prox;//tmp vai receber nossa lista -> proximo elemento

	while(tmp != NULL){//Enquanto tmp for diferente de Null
		printf("%d ", tmp->valor);//Exibe o valor do nó atual.
		tmp = tmp->prox;//E o tmp vai receber tmp próximo nó.
	}
	printf("\n\n");// pular umas linhas
}



//Quando temos uma lista encadeada, podemos inserir elementos no inicio ou no fim
//Função que insere um novo nó no início da lista encadeada:
// Também vai receber um ponteiro do tipo nó que chamaremos list_Enc
void insereInicio(no *list_Enc){
	no *novo = (no*)malloc(sizeof(no));
// Vamos criar uma nova variável que será o novo nó ele vai retornar um ponteiro para o nó
//e vamos utilizar o malloc que vai alocar a memória para esse novo nó.
//sizeof vai alocar o espaço necessário para o nó
//se a lista tiver várias variáveis ele vai alocar memoria para que caiba tudo
	if(!novo){ //Se não tiver memoria disponível
		printf("Sem memória disponível!\n");
		exit(1);
//faz com que o programa termine sua execução imediatamente e retorne o valor 1 ao sistema operacional.
	}
	//caso tenha memoria disponível pedimos o valor
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);
	// Lê o valor do novo nó que o usuário digitou.

	//Criamos a "novacabeça"  a List_Enc proximo vai apontar para o novo
	no *oldHead = list_Enc->prox;
	//Pegamos a cabeça anterior e vamos apontar para o próximo

	list_Enc->prox = novo; //e vamos pegar a nossa lista - proximo e apontar para o novo
	novo->prox = oldHead;//E o novo proximo vai apontar para o antigo primeiro nó
}// esse ultimo é tipo fazer a troca



//Função que insere um novo nó no fim da lista encadeada:
// Também vai receber um ponteiro do tipo nó que chamaremos list_Enc
void insereFim(no *list_Enc){
	no *novo = (no*)malloc(sizeof(no));
// Vamos criar uma nova variável que será o novo nó ele vai retornar um ponteiro para o nó
//e vamos utilizar o malloc que vai alocar a memória para esse novo nó.
//sizeof vai alocar o espaço necessário para o nó
//se a lista tiver várias variáveis ele vai alocar memoria para que caiba tudo
	if(!novo){ //Se não tiver memoria disponível
		printf("Sem memória disponível!\n");
		exit(1);
//faz com que o programa termine sua execução imediatamente e retorne o valor 1 ao sistema operacional.
	}
//caso tenha memoria disponível pedimos o valor
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);
// Lê o valor do novo nó que o usuário digitou.


	novo->prox = NULL;//e vamos pegar a nossa lista - proximo e apontar para NUll

	if(vazia(list_Enc)){ //Verifica se a lista_Enc estiver vazia.
		list_Enc->prox = novo; //O proximo elemento vai apontar para o novo
	}else{ //caso não
		no *tmp = list_Enc->prox;
    //cria uma nova variável do tipo ponteiro TMP temporária
    //e atribui o valor do ponteiro prox do nó list_Enc a ela.

		while(tmp->prox != NULL){ //Enquanto o temporário proximo for diferente de NULL
			tmp = tmp->prox;//O tmp vai receber tmp  proximo
		}
		tmp->prox = novo;//O tmp proximo recebe o novo.
	}
}




//Vamos criar uma função chamada opcao que vai receber um ponteiro
//para a Lista_Enc e um int que é a nossa opção
//Caso o usuário selecione 0 .....
void opcao(no *list_Enc, int op){
    switch(op){
		case 0:
			libera(list_Enc);//limpar nossa lista
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

//criar a função que sera o menu
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

	return opt;//retorna o valor da variável opt para a função menu int
}


//
int main(){


	no *list_Enc = (no*)malloc(sizeof(no));
// Vamos criar uma nova variável que será o novo nó ele vai retornar um ponteiro para o nó
//e vamos utilizar o malloc que vai alocar a memória para esse novo nó.
//sizeof vai alocar o espaço necessário para o nó
//se a lista tiver várias variáveis ele vai alocar memoria para que caiba tudo

	if(!list_Enc){ //Se for diferente de NULL
		printf("Sem memória disponível: ");
		exit(1);//faz com que o programa termine sua execução imediatamente e retorne o valor 1 ao sistema operacional.
	}
	inicia(list_Enc);//Caso ele conseguiu sem problema Inicializa a lista encadeada.
	int opt; //criamos uma variavel opt

	do{
		opt=menu();//Lê a opção selecionada pelo usuário da função do menu
		opcao(list_Enc, opt);
    //Executa a operação selecionada pelo usuário na opção e na função menu
	}while(opt);
//Continua o loop até que a opção selecionada seja 0 (sair), porque zero é falso no while

	free(list_Enc);// Libera a memória alocada para a cabeça da lista encadeada.

	return 0;//Retorna 0, indicando que o programa foi encerrado com sucesso.
}
