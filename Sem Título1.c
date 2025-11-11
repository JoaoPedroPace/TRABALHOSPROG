#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Item{
	char nome[30];
	int quantidade;
	struct Item *proximo_item;
}Item;

void inserirNoInicio(struct Item **inicio, int valor, char* nome){
	Item* atual = (Item*) malloc (sizeof(Item));
	
	if(atual == NULL){
		printf("Erro ao alocar memoria! ");
	}
	
	strcpy(atual->nome, nome);
	atual->quantidade = valor;
	atual->proximo_item = *inicio;
	*inicio = atual;
	
}

void removerDoInicio(struct Item **inicio){
	if(*inicio != NULL){
	
	Item *temp;
	temp = *inicio;
	*inicio = temp->proximo_item;
	free(temp);
	
	}

}

void imprimirLista(struct Item *inicio){
	Item *atual = inicio;
	
	int i = 1;
	while(atual != NULL){
		printf("Nome do item[%d]: %s // Quantidade: %d // \n", i, atual->nome, atual->quantidade);
		i++;
		atual = atual->proximo_item;
	}
	
	
}

Item* buscar(struct Item *inicio, char* nome){
	Item *atual = inicio;
	
	while(atual != NULL){
		int i = 1;
		if(strcmp(atual->nome, nome) == 0){
			return atual;
		}
		i++;
		atual = atual->proximo_item;
	}
	return NULL;
}

int main() {
    Item *listaDeItens = NULL;

    // Testando inserções
    inserirNoInicio(&listaDeItens, 5, "Pocao");
    inserirNoInicio(&listaDeItens, 1, "Espada");
    inserirNoInicio(&listaDeItens, 3, "Escudo");

    printf("--- Lista Inicial ---\n");
    imprimirLista(listaDeItens);

    // Testando busca (Sucesso)
    printf("\nBuscando 'Espada'...\n");
    Item* itemBuscado = buscar(listaDeItens, "Espada");
    if (itemBuscado != NULL) {
        printf("Encontrado: %s (Qtd: %d)\n", itemBuscado->nome, itemBuscado->quantidade);
    } else {
        printf("Item nao encontrado.\n");
    }

    // Testando busca (Falha)
    printf("\nBuscando 'Adaga'...\n");
    itemBuscado = buscar(listaDeItens, "Adaga");
    if (itemBuscado != NULL) {
        printf("Encontrado: %s (Qtd: %d)\n", itemBuscado->nome, itemBuscado->quantidade);
    } else {
        printf("Item nao encontrado.\n");
    }

    // Testando remoção
    printf("\nRemovendo do inicio...\n");
    removerDoInicio(&listaDeItens);
    printf("--- Lista Final ---\n");
    imprimirLista(listaDeItens);

    // Liberando o resto da memória (boa prática)
    removerDoInicio(&listaDeItens);
    removerDoInicio(&listaDeItens);
    
    return 0;
}
/*
typedef struct No{
	int dado;
	struct No* proximo;
}No;

void criarLista(){
	
}

void inserirNoInicio(struct No** inicio, int valor){
	No *atual = (No*) malloc(sizeof(No));
	
	if(atual == NULL){
	printf("Erro ao alocar memoria! ");
	return;
}
	atual->dado = valor;
	atual->proximo = *inicio;
	*inicio = atual;
}

void imprimirLista(No *inicio){
	No *atual = inicio;
	while(atual != NULL){
		printf("Dado: %d \n", atual->dado);
		atual = atual->proximo;
	}

}

void removerDoInicio(struct No** inicio){
	if(*inicio!=NULL){
		No* temp;
		temp = *inicio;
		*inicio = temp->proximo;
		free(temp);
	}
}

int main(){
	No *inicio = NULL;
	
	inserirNoInicio(&inicio, 10);	
	inserirNoInicio(&inicio, 20);
	inserirNoInicio(&inicio, 30);
	
	imprimirLista(inicio);
	
	removerDoInicio(&inicio);
	
	imprimirLista(inicio);
	
	return 0;
		
}

*/

/*
typedef struct{
	int dia;
	int mes;
	int ano;
}Data;
typedef struct{
	char descricao[100];
	Data data_comp;
}Compromisso;

int main(){
	Compromisso minha_agenda;
	
	char descricao[100];
	printf("Escreva a descricao do evento: ");
	scanf("%s", &descricao);
	
	strcpy(minha_agenda.descricao, descricao);
	
	printf("Dia do evento: ");
	scanf("%d", &minha_agenda.data_comp.dia);
	
	printf("Mes do evento: ");
	scanf("%d", &minha_agenda.data_comp.mes);
	
	printf("Ano do evento: ");
	scanf("%d", &minha_agenda.data_comp.ano);
	
	printf("Descricao: %s || Data: %d/%d/%d .", minha_agenda.descricao,minha_agenda.data_comp.dia,minha_agenda.data_comp.mes,minha_agenda.data_comp.ano);
	
	return 0;
}
*/

 /*
typedef struct{
	char nome[50];
	char matricula[30];
	float media;
	
}Aluno;

int main(){
	Aluno turma[3];
	
	for(int i = 0; i < 3; i++){
		char nome[50];
		char matricula[30];
		
		printf("Escreva o nome do aluno: ");
		scanf("%s", &nome);
		
		strcpy(turma[i].nome, nome);
		
		printf("Escreva a matricula: ");
		scanf("%s", &matricula);
		
		strcpy(turma[i].matricula, matricula);
		
		printf("Escreva a media de %s: ", nome);
		scanf("%f", &turma[i].media);
	}
	
	for(int i = 0; i < 3; i++){
		printf("\n\nNome: %s", turma[i].nome);
		printf("\nMatricula: %s", turma[i].matricula);
		printf("\nMedia: %.2f", turma[i].media);
	}
}

*/


/*
typedef struct{
	char username[50];
	int id_usuario;
}Usuario;

int main(){
	char nome[30];
	Usuario *p_user = (Usuario *) malloc (1 * sizeof(Usuario));
	
	if(!p_user){
		printf("Falha ao alocar memoria dinamicamente! ");
	}
	
	printf("Digite o nome do usuario: ");
	scanf("%s", &nome);
	strcpy(p_user->username, nome);
	p_user->id_usuario = 1;
	printf("\n Nome: %s \n ID: %d", p_user->username, p_user->id_usuario);
	
	free(p_user);
	
	return 0;
}

*/

/*
typedef struct{
	char nome[50];
	int codigo;
	float preco;
}Produto;

int main(){
	Produto item1;
	
	item1.codigo = 1;
	strcpy(item1.nome, "Morango");
	item1.preco = 8.00;
	
	printf("Nome: %s Preço: %.2f Codigo: %d .",item1.nome,item1.preco, item1.codigo);
	Produto *ptr_item;
	ptr_item = &item1;
	
	ptr_item->preco = 8.50;
	
	printf("\nNome: %s Preço: %.2f Codigo: %d .",item1.nome,item1.preco, item1.codigo);
}

*/