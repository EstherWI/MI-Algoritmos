//Sistema Antidoping - COPA 2018 


/***************************
Autora: ESTHER DE SANTANA ARAUJO
Componente Curricular: Algoritmos e Programa��o I
Concluido em: 
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista{
	char nome[30], selecao[15], posicao_time[20];
	int ano_nascimento, numero_camisa;
	struct lista* proximo;
} Jogador;

void Cadastro (Jogador* inicio, FILE* entrada);
//Jogador* RemoveCadastro (Jogador* inicio);
void ExibeTodos(Jogador* inicio);
Jogador* AumentaLista (Jogador* inicio);
void Organiza_Saida (char* nome);
void AlteraDados(Jogador* inicio, FILE* entrada);

int main(int argc, char *args[])
{
	
	Jogador *inicio=NULL;
	int resposta;
	
	FILE *entrada;
	entrada = fopen(args[1], "r");
	
	
	if (entrada!=NULL)
	{
		do{
		
		fscanf(entrada, "%d", &resposta);
		printf("%d", resposta);
		switch(resposta)
		{
			case 1:
				//Realizando novo cadastro
				inicio=AumentaLista(inicio);
				Cadastro(inicio, entrada);
		
			case 2:
			    //Alterando dados de um jogador
			    AlteraDados(inicio, entrada);
			    break;
			    
			case 3:
				//Removendo determinado jogador
				
				//inicio=RemoveCadastro(inicio);
				break;
				
			case 4:
				//Sorteia
				break;
				
			case 5:
				//Filtra pela posi��o
				break;
				
			case 6:
				//Exibe todos os jogadores
				ExibeTodos(inicio);
				break;
				
			case 7:
				//Exibe jogadores sorteados
				break;
			
			case 8:
				//sai do programa
			break;
		}
	printf("%s", inicio->nome);
	}while(resposta!=8);
	}
	else
		printf("Arquivo n�o encontrado!");
   	
}

void Cadastro(Jogador* inicio, FILE* entrada)
{
	int lixo;
	//Coleta de dados do jogador
		fscanf(entrada,"%d", &lixo);
		fgets(inicio->nome, 30, entrada);
		Organiza_Saida (inicio->nome);
		printf("%s", inicio->nome);
		fscanf(entrada, "%d", &inicio->ano_nascimento);
		fscanf(entrada, "%d", &lixo);
		fgets(inicio->selecao, 15, entrada);
		Organiza_Saida (inicio->selecao);
		fscanf(entrada, "%d", &inicio->numero_camisa);
		fscanf(entrada, "%d", &lixo);
		fgets(inicio->posicao_time, 20, entrada);
		Organiza_Saida (inicio->posicao_time);
	printf("%s", inicio->nome);
}


void ExibeTodos(Jogador* inicio)
{
	Jogador* agora;
	
	FILE *saida;
	saida = fopen("saida.txt", "a");
	
	fprintf(saida, "EXIBICAO DE TODOS OS JOGADORES\n");
	
	for(agora=inicio; agora!= NULL; agora=agora->proximo)
	{
		fprintf(saida,"%s\t%d\t%s\t%d\t%s\n", agora->nome, agora->ano_nascimento, agora->selecao, agora->numero_camisa, agora->posicao_time);
	}
	
	fclose(saida);
}

Jogador* AumentaLista (Jogador* inicio)
{
	Jogador *Novalista = (Jogador*)malloc(sizeof(Jogador));
	Novalista->proximo=inicio;
	
	return Novalista;
}

void Organiza_Saida (char* nome)
{
	int i=0;
	
	while(nome[i]!='\0')
	{
		if(nome[i]=='\n')
		{
			nome[i]='\0';
		}
		i++;
	}
}

void AlteraDados(Jogador* inicio, FILE* entrada)
{
	fgets(inicio->nome, 30, entrada);
	fscanf(entrada, "%d", inicio->numero_camisa);
}
