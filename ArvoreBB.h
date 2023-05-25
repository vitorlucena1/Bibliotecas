#ifndef ArvoreBB_H
#define ArvoreBB_H
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int tp_item;
typedef struct tp_no{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
} tp_no;

typedef tp_no * tp_arvore;

tp_arvore inicializa_arvore(){
	return NULL;
}

int arvore_vazia(tp_arvore raiz){
	if(raiz==NULL) return 1;
	else return 0;
}

tp_no *aloca_no(){// aloca e retorna o endereço
	tp_no *no;
	no=(tp_no*)malloc(sizeof(tp_no));
	return no;
}

int insere_no(tp_arvore *raiz, tp_item e){
	tp_no *pai=NULL, *novo, *p=*raiz; //*p=ponteiro auxiliar
	novo=aloca_no(); //cria um novo elemento e coloca o endereço dele no novo
	if(!novo) return 0; //não deu para alocar (novo==NULL)
	novo->info=e;
	novo->esq=NULL;
	novo->dir=NULL;
	while(p!=NULL){ //busca a posição onde será inserido o novo nó
	pai=p;
		if(e<p->info)
		p=p->esq;
		else
		p=p->dir;
	}
	if(pai!=NULL){ //Qual ponteiro do pai (esq ou dir) irá apontar para o novo
		if(e < pai->info)
		pai->esq=novo;
		else
			pai->dir=novo;
}
	else
	*raiz=novo;
	
	return 1;
}

void pre_ordem(tp_no *p){ //imprime os lementos em pre-ordem
	if(p!=NULL){
		cout<<"\n"<<p->info;
		pre_ordem(p->esq);
		pre_ordem(p->dir);
	}
}

void em_ordem(tp_no *p){ //imprime os elementos em ordem
	if(p!=NULL){
		em_ordem(p->esq);
		cout<<"\n"<<p->info;
		em_ordem(p->dir);
	}
}

void pos_ordem(tp_no *p){ //imprime os elementos pós-ordem
	if(p!=NULL){
		pos_ordem(p->esq);
		pos_ordem(p->dir);
		cout<<"\n"<<p->info;
	}
}

tp_no* busca_no(tp_no *p, tp_item e){
	while(p!=NULL){
		if(e<p->info)
		p=p->esq;
		else
			if(e>p->info)
			p=p->dir;
			else
			return (p);
	}
	return (NULL);
}

tp_arvore busca_no_rec(tp_arvore p, tp_item e){
	if(p!=NULL){
		if(e<p->info)
		return busca_no_rec(p->esq, e);
		else
			if(e>p->info)
			return busca_no_rec(p->dir, e);
			else
			return (p);
	}
	else
		return (NULL);
}

int quant_nivel(tp_arvore raiz){
	if(raiz==NULL) return 0;
	int alt_esq=quant_nivel(raiz->esq);
	int alt_dir=quant_nivel(raiz->dir);
	if(alt_esq > alt_dir){
		return alt_esq + 1;
	}else{
		return alt_dir + 1;
	}
}

int qtde_nos(tp_arvore raiz){
	if(raiz==NULL) return 0;
	int tot_esq= qtde_nos(raiz->esq);
	int tot_dir=qtde_nos(raiz->dir);
	return (tot_esq + tot_dir + 1);
}

int remove_no(tp_arvore *raiz, tp_item e){
	tp_no *p=*raiz, *ant=NULL, *sub, *pai, *filho;
	while(p!=NULL && p->info!=e){
		ant=p;
		if(e<p->info)
			p=p->esq;
			else
			p=p->dir;
	}
	if(p==NULL) //Não encontrou
	return 0;
	//Nó tem no máximo um filho
	if(p->esq==NULL)
	sub=p->dir;
	
	else
		if(p->dir==NULL)
		sub=p->esq;
		else{ //Nó tem dois filhos
		pai=p; sub=p->dir; filho =sub->esq;
		while(filho!=NULL){
			pai=sub; sub=filho; filho=sub->esq;
		}
		//Neste ponto, sub é o sucessor em ordem de p
		if(pai!=NULL){
			//P não é o pai de sub e sub==pai->esq
			pai->esq=sub->dir;
			//Remove o nó apontado por sub de sua atual posição e substitui pelo filho direito de p
			//Sub ocupa o lugar de p
			sub->dir=p->dir;
		}
		//Define filho esq de sub para que sub ocupe o lugar de p
		sub->esq=p->esq;
		}
	//Insere sub na posição ocupada por p
	if(ant==NULL)
	*raiz=sub; //P era raiz
	else
		if(p==ant->esq)
			ant->esq=sub;
		else
			ant->dir=sub;
			
	free(p);
	return 1;	
}

void destroi_no(tp_no *no){
	if(no==NULL) return;
	destroi_no(no->esq);
	destroi_no(no->dir);
	//cout<<"\n"<<no->info/
	free(no);
	no=NULL;
	return;
}

void destroi_arvore(tp_arvore *raiz){
	if(*raiz==NULL) return;
	destroi_no(*raiz);
	//free(*raiz);
	*raiz=NULL;
}
#endif
