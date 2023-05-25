#ifndef LISTASE_H
#define LISTASE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int tp_item;

typedef struct tp_no{
	tp_item info;
	struct  tp_no *prox;
} tp_listase;

tp_listase * inicializa_listase(){
	return NULL;
}

int listase_vazia(tp_listase *lista){	
	if(lista == NULL) return 1;
	return 0;
}

tp_listase * aloca_listase(){ //ela irá alocar um espaço na memória
	tp_listase *novo_no;
	novo_no = (tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

/*Esse **L é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da listase*, o que está apontnado para o NULL */

int insere_listase_no_fim(tp_listase **l, tp_item e){
	tp_listase *novo_no, *atu;
	novo_no =aloca_listase(); //aqui está pegando o novo nó e apontando para o NULL
	if(novo_no==NULL) return 0; //Não alocou memória
	//atribuir os valores para o novo nó;
	novo_no->info= e;
	novo_no->prox=NULL;
//finaliza o encadeamento do nó
if(listase_vazia(*l)){// se for o primeiro nó entra aqui
	*l = novo_no;

} else{
	//atu é atual
	atu = *l;
	while(atu->prox!=NULL){
		atu=atu->prox; //aponta para o último nó
	}
	atu->prox=novo_no;
}
return 1;
}

void imprime_listase(tp_listase *lista){
	tp_listase *atu;
	atu=lista;
	while (atu!=NULL){
		cout <<atu->info <<"\n";
		atu=atu->prox;
	}
}

int remove_listase(tp_listase **lista, tp_item e){
	tp_listase *ant, *atu;
	atu=*lista;
	ant=NULL;
	while((atu!=NULL) &&(atu->info!=e)){
		ant=atu;
		atu=atu->prox;
	}
	if(atu==NULL) return 0; //não foi encontrado o elemento
	if(ant==NULL){//se for retirado o primeiro termo
		*lista=atu->prox; //fazendo a lsita apontar para o termo subsequente que foi retirado
	}
	else{
		ant->prox=atu->prox; //fazendo a interligação entre o termo anterior e o termo subsequente ao termo retirado
	}
	free(atu);
	atu=NULL;
	return 1;
}

tp_listase *busca_listase(tp_listase *lista, tp_item e){
	tp_listase *atu;
	atu=lista;
	while((atu!=NULL) && (atu->info!=e)){
		atu=atu->prox;
	}
	if(atu==NULL) return NULL;
	return atu;
}

int tamanho_listase(tp_listase *lista){
	int cont = 0;
	tp_listase *atu;
	atu=lista;
	while(atu!=NULL){
		cont++;
		atu=atu->prox;
	}
	return cont;
}

int maior_listase(tp_listase *lista, int n){
	int cont=0;
	tp_listase *atu;
	atu=lista;
	while(atu!=NULL){
		if(atu->info > n){
		cont++;
	}
	atu=atu->prox;

	}
	return cont;
}

void destroi_listase(tp_listase **l){
	tp_listase *atu;
	atu=*l;
	while(atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	*l=NULL;
}

int listase_iguais(tp_listase *lista1, tp_listase *lista2){
	tp_listase *atu1, *atu2;
	atu1 = lista1;
	atu2 = lista2;

	if(tamanho_listase(lista1) != tamanho_listase(lista2)){
		cout<<"Sao diferentes!\n";
	return 0;
	}
	else{
		while(atu1 != NULL && atu2 != NULL){
			if(atu1->info != atu2->info){
			cout<<"Sao diferentes!\n";
	return 0;
	}
	atu1=atu1->prox;
	atu2=atu2->prox;

		}
}	
	cout<<"Sao iguais\n";
	return 1;
}

int insere_em_ordem(tp_listase **lista, tp_item e){// Esse **lista é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da listase*, o que está apontando para o NULL
	tp_listase *novo_no, *atu, *ant;
	novo_no=aloca_listase(); //aqui está pegando o novo nó e alocando ele (criando a struct);
	if(novo_no==NULL) return 0;//Não alocou memória
//atribuir os valores para o novo nó;
	novo_no->info= e;//atribuindo valores para o novo nó
	atu=*lista;
	ant=NULL;
//laço para percorrer a lista encadeada enquanto não chegar no fim
	while((atu!=NULL && (atu->info < novo_no->info))){
	ant=atu;
	atu=atu->prox;
}
	if(ant==NULL){//inserir antes do primeiro
	*lista=novo_no;
	}
	else{
	ant->prox=novo_no;
}
	novo_no->prox=atu;
	return 1;
}

//int metodo_josephus(tp_listase **l, int s){
//    if (*l == NULL) {
//        return 0; // retorna um valor indicando erro (por exemplo)
//    }
//    
//    tp_listase *aux, *ant;
//    aux = *l;
//    int cont = 0;
//    while (aux->prox != NULL){
//        cont++;
//        aux = aux->prox;
//    }
//    ant = aux;
//    aux->prox = *l;
//    aux = *l;
//
//    while (cont > 1){
//        for (int i = 0; i < s-1; i++){
//            ant = aux;
//            aux = aux->prox;
//        }
//        ant->prox = aux->prox;
//        free(aux);
//        aux = ant->prox;
//        cont--;
//    }
//    return aux->info;
//}


#endif
