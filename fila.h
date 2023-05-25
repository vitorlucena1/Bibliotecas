#ifndef fila_h
#define fila_h
#include <iostream>
using namespace std;
#define MAX 100

typedef int tp_item;
typedef struct {
	tp_item item[MAX];
	int inicio, fim;
	// int tam
}tp_fila;

void inicializa_fila(tp_fila *f){
	f->inicio = f->fim = MAX-1;
	//f->tam=0;
}

int fila_vazia(tp_fila *f){
	if(f->inicio == f->fim) return 1;
	return 0;
}

int proximo (int posicao){
	if(posicao == MAX-1) return 0;
	return ++posicao;
}

int fila_cheia (tp_fila *f){
	if(proximo(f->fim)==f->inicio)
		return 1;
	return 0;
}

int insere_fila (tp_fila *f, tp_item e){
	if(fila_cheia(f))
	return 0; //não foi possível adicionar a fila
	f->fim = proximo(f->fim);
	f->item[f->fim]=e;
	// f->tam++;
	return 1;
}

int remove_fila (tp_fila *f, tp_item *e){
	if(fila_vazia(f))
	return 0; //Não foi possível remover da fila
	f->inicio = proximo(f->inicio);
	*e=f->item[f->inicio];
	//f->tam--;
	return 1;
}

void imprime_fila(tp_fila f){
	tp_item e;
	while(!fila_vazia(&f)){
		remove_fila(&f, &e);
		cout <<"\n"<< e;
	}
}

//int tamanho_fila(tp_fila *f){
//	if (fila_vazia(f)) return 0;
//	if(f->inicio < f->fim) return f->fim - f->inicio;
//	return MAX - 1 - f->inicio + f->fim +1;
//}

int tamanho_fila(tp_fila f){
	int cont = 0;
	tp_item e;
	while (!fila_vazia(&f)){
		remove_fila(&f, &e);
		cont++;
	}
	return cont;
}

void esvazia_fila(tp_fila *f, tp_item *e){
	while(!fila_vazia(f)){
	remove_fila(f, e);
	}
}

#endif

