#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>
using namespace std;
int gravar(FILE *arq, char nomearq[]){
	char mensagem[1000];
	int quant;
	arq=fopen(nomearq, "w");
	if(!arq) return 0;
	cout<<"Digite a quantidade de mensagens: ";
	cin>>quant;
	fflush(stdin);
	for (int i=0; i<quant; i++){
	cout<<"Digite mensagem "<<i+1<< " para gravar no arquivo: ";
	gets(mensagem);
	if(i+1==quant)
	break;
	else
	fprintf(arq, strcat(mensagem, "\n"));
	}
	fputs(mensagem, arq);
	fclose(arq);
	return 1;
}

int alterar_no_final(FILE *arq, char nomearq[]){
	char mensagem[50];
	arq=fopen(nomearq, "a");
	if(!arq) return 0;
	cout<<"Digite mensagem para gravar no arquivo ";
	gets(mensagem);
	fprintf(arq, strcat(mensagem, "\n"));
	fclose(arq);
	return 1;
}

int ler(FILE *arq, char nomearq[]){
	setlocale(LC_ALL,"Portuguese_Brazil");
	char registro[100];
	arq=fopen(nomearq, "r");
	if(!arq) return 0;
	while (fgets(registro, sizeof(registro), arq)){
		cout<<registro;
	}
	fclose(arq);
	return 1;
}

int ler_formatado(FILE *arq, char nomearq[]){
	float nota1, nota2, nota3;
	arq=fopen(nomearq, "r");
	if(!arq) return 0;
	while(fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF){
	cout<<"Nota1: "<<nota1<<" Nota2: "<<nota2<<" Nota3: "<<nota3<<"\n";
	}
		fclose(arq);
		return 1;
}

int poema(FILE *arq, char nomearq[]){ //Função criada para a prova com o intuito de procurar a quantidade de vezes que a palavra burrinho aparece no poema O Menino Azul
	char registro[10000], mensagem[2];
	int i=0, cont=0;
	arq=fopen(nomearq, "r+");
	if(!arq) return 0;
	while(fscanf(arq, "%s", &registro[i]) != EOF){
		if(registro[i] =='b' &&registro[i+1] =='u'&&registro[i+2] =='r'&&registro[i+3] =='r'&&registro[i+4] =='i'&&registro[i+5] =='n'&&registro[i+6] =='h'&&registro[i+7] =='o')
		cont++;
	}
	fprintf(arq,"\n%d", cont);
	fclose(arq);
	return 1;
}

int ler_alterar_geral(FILE *arq, char nomearq[]){
	float notas[3][3];
	char registro[20];
	int i=0;
	arq=fopen(nomearq, "r+");
	if(!arq) return 0;
	while(fscanf(arq,"%f %f %f", &notas[i][0], &notas[i][1], &notas[i][2]) != EOF){
		cout<<"\nAluno "<<i+1<<"\n";
		cout<<"Nota 1 - Atual: "<<setprecision(1)<<notas[i][0]<<" Nova: ";
		cin>>notas[i][0];
		cout<<"Nota 2 - Atual: "<<setprecision(1)<<notas[i][1]<<" Nova: ";
		cin>>notas[i][1];
		cout<<"Nota 3 - Atual: "<<setprecision(1)<<notas[i][2]<<" Nova: ";
		cin>>notas[i][2];
		i++;
	}
	rewind(arq); //volta o cursor para o início do arquivo
	for (i=0; i<3; i++){
		sprintf(registro, "%.1f %.1f %.1f\n", notas[i][0], notas[i][1], notas[i][2]);
		fputs(registro, arq);
	}
	fclose(arq);
	return 1;
}

int soma_um(FILE *arq, char nomearq[]){
	float nota1, nota2, nota3;
	float notas[3][3];
	char registro[20];
	int i=0;
	arq=fopen(nomearq, "r+");
	if(!arq) return 0;
	while(fscanf(arq,"%f %f %f", &notas[i][0], &notas[i][1], &notas[i][2]) != EOF){
		notas[i][0]+=1;
		notas[i][1]+=1;
		notas[i][2]+=1;
		i++;
	}
	rewind(arq); //volta o cursor para o início do arquivo
	for (i=0; i<3; i++){
		sprintf(registro, "%.1f %.1f %.1f\n", notas[i][0], notas[i][1], notas[i][2]);
		fputs(registro, arq);
	}
	rewind(arq);
	while(fscanf(arq,"%f %f %f", &notas[i][0], &notas[i][1], &notas[i][2]) != EOF){
		cout<<"Nota1: "<<notas[i][0]<<" Nota2: "<<notas[i][1]<<" Nota3: "<<notas[i][2]<<"\n";
		i++;
	}
	fclose(arq);
	return 1;
}
#endif
