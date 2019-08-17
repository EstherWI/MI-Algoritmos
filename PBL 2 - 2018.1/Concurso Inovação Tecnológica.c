//Concurso de inovação tecnológica


/***************************
Autora: ESTHER DE SANTANA ARAUJO
Componente Curricular: Algoritmos e Programação I
Concluido em: 10 de junho de 2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int codigo;
	char nome_equipe[30], categoria[20];
	float C1, C2, C3, C4, C5, media;
	} equipe;

void ler_manualmente (equipe [], int[]);
void ler_arquivo (equipe[], int []);
void ordenanotas (equipe[], int);
void calculacriteriosmanual (equipe [], int);
void calculamedia (equipe[], int);
void gerasaida(equipe[], equipe[], equipe[], equipe [], int[], int);
void desempate (equipe[], int);
void separacategorias (equipe[], equipe[], equipe [], equipe [], int);

int main ()
{
	int resposta, qntequipes=0, p, contador[]={0,0,0};

 	equipe vetor [11];
 	equipe gestao[10], projeto_social[10], educacao[10];

	printf("Seja bem-vindo!\n");
	printf("Digite 1 para entrar com os dados das equipes manualmente e 2 para que o programa leia um arquivo de texto com as informacoes\n");
	scanf("%d", &resposta);

		if(resposta==2)
		{
			ler_arquivo (vetor, contador);
			p= contador[0] + contador[1] + contador[2]; //p é o numero total de equipes, sendo a soma dos contadores de cada categoria
			calculamedia(vetor, p);
			ordenanotas(vetor, p);
			desempate (vetor, p);
			separacategorias (vetor, gestao, educacao, projeto_social, p);
			gerasaida(gestao, projeto_social, educacao, vetor, contador, p);
		}
		else
		{
			ler_manualmente (vetor, contador);
			printf("A proxima etapa sera inserir as notas para que a media de cada equipe seja calculada.\n");
			p= contador[0] + contador[1] + contador[2];//p é o numero total de equipes, sendo a soma dos contadores de cada categoria
			calculacriteriosmanual (vetor, p);
			calculamedia(vetor, p);
			ordenanotas(vetor, p);
			desempate(vetor, p);
			separacategorias (vetor, gestao, educacao, projeto_social, p);
			gerasaida(gestao, projeto_social, educacao, vetor, contador, p);

		}
		
		return 0;
}

void ler_arquivo (equipe vetor[11], int contador[])
{
	float somacriterio1[10], somacriterio2[10],somacriterio3[10], somacriterio4[10], somacriterio5[10];
	int i=0, j=0, c=0, b=0, retorno;
	char lixo[5];
	
	for(i=0; i<10; i++)
	{
	somacriterio1[i]=0; // para que nao fiquem valores lixo na soma das notas de cada jurado
	somacriterio2[i]=0;
	somacriterio3[i]=0;
	somacriterio4[i]=0;
	somacriterio5[i]=0;
    } 
	i=0;
	FILE *arquivo_entrada;
	arquivo_entrada = fopen ("entrada.txt", "r");

	if(arquivo_entrada != NULL)
	{
		do{
			fscanf(arquivo_entrada, "%d", &vetor[i].codigo);
			fscanf(arquivo_entrada, "%s", &vetor[i].categoria);
			fscanf(arquivo_entrada, "%s", &vetor[i].nome_equipe);
			retorno=strcasecmp(vetor[i].categoria, "J1"); // quando o leitor chegar no j1, quer dizer que a parte do cadastro das equipes acabou
			i++;
		  }while(retorno!=0); 
			i=0;

				while(b!=48)// como dois J's ja foram pegos, um pela variavel de categoria e outro pela do nome da equipe, vão sobrar 48 elementos de J's e C's
				{
					fscanf(arquivo_entrada, "%s",lixo);//a variável lixo irá ler os C's e J's do arquivo, que não precisarão ser utilizados 
					b++;
				}
				
				do //nesse laço começa a leitura da matriz com as notas
				{
					fscanf(arquivo_entrada, "%s", vetor[i].nome_equipe); 
					fscanf(arquivo_entrada, "%s", vetor[i].categoria);
					
					if(strcasecmp(vetor[i].categoria, "E")==0)
					{
						contador[0]++; //contador para as equipes de educacao
					}
					else if (strcasecmp(vetor[i].categoria, "P")==0)
					{
						contador[1]++; //contador para as equipes de projeto social
					}
					else 
					{
						contador[2]++; //contador para as equipes de gestao
					}
				
					while(c!=5) //le as notas de 5 em 5, podendo ja fazer a soma das notas de todos os jurados em determinado criterio para calcular a media
					{
						fscanf(arquivo_entrada, "%f %f %f %f %f ", &vetor[i].C1, &vetor[i].C2, &vetor[i].C3, &vetor[i].C4, &vetor[i].C5);
						somacriterio1[i]= somacriterio1[i] + vetor[i].C1;
						somacriterio2[i]= somacriterio2[i] + vetor[i].C2;
						somacriterio3[i]= somacriterio3[i] + vetor[i].C3;
						somacriterio4[i]= somacriterio4[i] + vetor[i].C4;
						somacriterio5[i]= somacriterio5[i] + vetor[i].C5;
						c++;
					}
				
					c=0; 
					i++;
			    }while(!feof(arquivo_entrada));// arquivo sendo lido até o final

		for(j=0;j<i;j++)//este laço usa a soma anteriormente feita para calcular a media de cada criterio de cada equipe
	 	{
		 	vetor[j].C1 = somacriterio1[j]/5.0;
		 	vetor[j].C2 = somacriterio2[j]/5.0;
		 	vetor[j].C3 = somacriterio3[j]/5.0;
		 	vetor[j].C4 = somacriterio4[j]/5.0;
		 	vetor[j].C5 = somacriterio5[j]/5.0;
		 }

	 fclose(arquivo_entrada);
	}
	else
	{
		printf("Arquivo nao encontrado!\n");
	}
}


void ler_manualmente(equipe vetor [],int contador[])
{
	int i=0, j, resposta, opcao, confirma, equipes=0;

	do
	{
		printf("Digite 1 para Educacao, 2 para Projeto Social e 3 para Gestao.\n");
		scanf("%d", &opcao);
		if(opcao==1)
		{
			strcpy(vetor[i].categoria, "E");
			do{
				printf("Digite o codigo da equipe %d.\n", i+1);
				scanf("%d", &vetor[i].codigo);
				contador[0]++;//contador do numero de equipes da categoria educacao
				for(j=0; j<i; j++)
				{
					if(vetor[j].codigo == vetor[i].codigo)//verificação a respeito de códigos iguais pedida no descritivo
					{
						printf("Esse codigo ja foi cadastrado. Digite outro para a equipe.\n");
						scanf("%d", &vetor[i].codigo); //opção de registrar um outro código
					}
				}
				confirma=1;
			  }while(confirma!=1);

			printf("Digite o nome da equipe %d.\n", i+1);
			scanf("%s", &vetor[i].nome_equipe);
			system ("cls");

		}
		else if(opcao==2)
		{
			strcpy(vetor[i].categoria, "P");
			do{

					printf("Digite o codigo da equipe %d.\n", i+1);
					scanf("%d", &vetor[i].codigo);
					contador[1]++;//contador do numero de equipes da categoria projeto social
					for(j=0; j<i; j++)
					{
						if(vetor[j].codigo == vetor[i].codigo)
						{
							printf("Esse codigo ja foi cadastrado. Digite outro para a equipe.\n");
							scanf("%d", &vetor[i].codigo);
						}
					}
					confirma=1;
		       }while(confirma!=1);

			printf("Digite o nome da equipe %d.\n", i+1);
			scanf("%s", &vetor[i].nome_equipe);
			system ("cls");
		}
		else
		{
			strcpy(vetor[i].categoria, "G");
			do{
					printf("Digite o codigo da equipe %d.\n", i+1);
					scanf("%d", &vetor[i].codigo);
					contador[2]++;//contador do numero de equipes da categoria gestao
					for(j=0; j<i; j++)
					{
						if(vetor[j].codigo == vetor[i].codigo)
						{
							printf("Esse codigo ja foi cadastrado. Digite outro para a equipe.\n");
							scanf("%d", &vetor[i].codigo);
						}
					}
					confirma=1;
			   }while(confirma!=1);

			printf("Digite o nome da equipe %d.\n", i+1);
			scanf("%s", &vetor[i].nome_equipe);
			system ("cls");
		}

			i++;
			if(i<10)//verificação para impedir que mais de 10 equipes sejam registradas
			{
				printf("Digite 1 para registrar outra equipe e 2 se nao houver mais nenhuma equipe.\n");
				scanf("%d", &resposta);
			}
			else
			{
				printf("Limite de equipes foi atingido.\n");
				resposta=2;
			}

	}while(resposta==1);
}

void calculacriteriosmanual (equipe vetor[10], int p)
{
	int i;
	float n1, n2, n3, n4, n5, soma1[10], soma2[10], soma3[10], soma4[10], soma5[10];


	for(i=0; i<p;i++)
	{
		printf("Digite a nota do jurado 1 do criterio: Nivel de Organizacao para a equipe %d\n", i+1);
		scanf("%f", &n1);
		printf("Digite a nota do jurado 2 do criterio: Nivel de Organizacao para a equipe %d\n", i+1);
		scanf("%f", &n2);
		printf("Digite a nota do jurado 3 do criterio: Nivel de Organizacao para a equipe %d\n", i+1);
		scanf("%f", &n3);
		printf("Digite a nota do jurado 4 do criterio: Nivel de Organizacao para a equipe %d\n", i+1);
		scanf("%f", &n4);
		printf("Digite a nota do jurado 5 do criterio: Nivel de Organizacao para a equipe %d\n", i+1);
		scanf("%f", &n5);

		soma1[i]= n1 + n2 + n3 + n4 + n5; //somatorio para tirar a media dos criterios
	}
	for(i=0; i<p;i++)
	{
		printf("Digite a nota do jurado 1 do criterio: Estrategia de venda para a equipe %d\n", i+1);
		scanf("%f", &n1);
		printf("Digite a nota do jurado 2 do criterio: Estrategia de venda para a equipe %d\n", i+1);
		scanf("%f", &n2);
		printf("Digite a nota do jurado 3 do criterio: Estrategia de venda para a equipe %d\n", i+1);
		scanf("%f", &n3);
		printf("Digite a nota do jurado 4 do criterio: Estrategia de venda para a equipe %d\n", i+1);
		scanf("%f", &n4);
		printf("Digite a nota do jurado 5 do criterio: Estrategia de venda para a equipe %d\n", i+1);
		scanf("%f", &n5);

		soma2[i]= n1 + n2 + n3 + n4 + n5;
	}
	for(i=0; i<p;i++)
	{
		printf("Digite a nota do jurado 1 do criterio: Grau de usabilidade do produto para a equipe %d\n", i+1);
		scanf("%f", &n1);
		printf("Digite a nota do jurado 2 do criterio: Grau de usabilidade do produto para a equipe %d\n", i+1);
		scanf("%f", &n2);
		printf("Digite a nota do jurado 3 do criterio: Grau de usabilidade do produto para a equipe %d\n", i+1);
		scanf("%f", &n3);
		printf("Digite a nota do jurado 4 do criterio: Grau de usabilidade do produto para a equipe %d\n", i+1);
		scanf("%f", &n4);
		printf("Digite a nota do jurado 5 do criterio: Grau de usabilidade do produto para a equipe %d\n", i+1);
		scanf("%f", &n5);

		soma3[i]= n1 + n2 + n3 + n4 + n5;
	}
	for(i=0; i<p;i++)
	{
		printf("Digite a nota do jurado 1 do criterio: Nivel de maturidade da area de atuacao para a equipe %d\n", i+1);
		scanf("%f", &n1);
		printf("Digite a nota do jurado 2 do criterio: Nivel de maturidade da area de atuacao para a equipe %d\n", i+1);
		scanf("%f", &n2);
		printf("Digite a nota do jurado 3 do criterio: Nivel de maturidade da area de atuacao para a equipe %d\n", i+1);
		scanf("%f", &n3);
		printf("Digite a nota do jurado 4 do criterio: Nivel de maturidade da area de atuacao para a equipe %d\n", i+1);
		scanf("%f", &n4);
		printf("Digite a nota do jurado 5 do criterio: Nivel de maturidade da area de atuacao para a equipe %d\n", i+1);
		scanf("%f", &n5);

		soma4[i]= n1 + n2 + n3 + n4 + n5;
	}
	for(i=0; i<p;i++)
	{
		printf("Digite a nota do jurado 1 do criterio: Grau de inovacao do produto para a equipe %d\n", i+1);
		scanf("%f", &n1);
		printf("Digite a nota do jurado 2 do criterio: Grau de inovacao do produto para a equipe %d\n", i+1);
		scanf("%f", &n2);
		printf("Digite a nota do jurado 3 do criterio: Grau de inovacao do produto para a equipe %d\n", i+1);
		scanf("%f", &n3);
		printf("Digite a nota do jurado 4 do criterio: Grau de inovacao do produto para a equipe %d\n", i+1);
		scanf("%f", &n4);
		printf("Digite a nota do jurado 5 do criterio: Grau de inovacao do produto para a equipe %d\n", i+1);
		scanf("%f", &n5);

		soma5[i]= n1 + n2 + n3 + n4 + n5;
	}

	 	for(i=0; i<p;i++)//laço para calcular a media de cada criterio de todas as equipes
	 	{
		 		vetor[i].C1 = soma1[i]/5.0;
		 		vetor[i].C2 = soma2[i]/5.0;
		 		vetor[i].C3 = soma3[i]/5.0;
		 		vetor[i].C4 = soma4[i]/5.0;
		 		vetor[i].C5 = soma5[i]/5.0;
		 }
}

void ordenanotas (equipe vetor[11], int p)
{
	int i=0, j;
	char auxi[30];
	float guarda, aux;

	for(i=0; i<p-1; i++)//método bubblesort, ordenando decrescentemente com respeito a média de cada equipe
	{
		for(j=0; j<p-1-i; j++) 
		{
			if(vetor[j].media < vetor[j+1].media)//caso a equipe da posição seguinte tenha media maior, as duas equipes trocam a posição
			{
				aux = vetor[j+1].media;
				vetor[j+1].media= vetor[j].media;
				vetor[j].media = aux;
				
				strcpy(auxi, vetor[j+1].nome_equipe);
				strcpy(vetor[j+1].nome_equipe, vetor[j].nome_equipe);
				strcpy(vetor[j].nome_equipe, auxi);
				
				strcpy(auxi, vetor[j+1].categoria);
				strcpy(vetor[j+1].categoria, vetor[j].categoria);
				strcpy(vetor[j].categoria, auxi);
				
				guarda = vetor[j+1].C1;
				vetor[j+1].C1= vetor[j].C1;
				vetor[j].C1 = guarda;
				
				guarda = vetor[j+1].C2;
				vetor[j+1].C2= vetor[j].C2;
				vetor[j].C2 = guarda;
				
				guarda = vetor[j+1].C3;
				vetor[j+1].C3= vetor[j].C3;
				vetor[j].C3= guarda;
				
				guarda = vetor[j+1].C4;
				vetor[j+1].C4 = vetor[j].C4;
				vetor[j].C4 = guarda;
				
				guarda = vetor[j+1].C5;
				vetor[j+1].C5 = vetor[j].C5;
				vetor[j].C5 = guarda;
				
			}
		}	
	}	
}
	
void separacategorias (equipe vetor [11], equipe gestao [10], equipe educacao [10], equipe projeto_social [10], int p)
{
	int i, e=0, g=0, ps=0;

	for(i=0; i<p; i++)
	{
		
		if(strcasecmp(vetor[i].categoria, "E")==0)//verificaçao para preencher o vetor educacao com suas respectivas equipes
		{
			educacao[e].media = vetor[i].media;
			strcpy(educacao[e].nome_equipe, vetor[i].nome_equipe);
			strcpy(educacao[e].categoria, vetor[i].categoria);
			educacao[e].C1 = vetor[i].C1;
			educacao[e].C2 = vetor[i].C2;
			educacao[e].C3 = vetor[i].C3;
			educacao[e].C4 = vetor[i].C4;
			educacao[e].C5 = vetor[i].C5;
			e++;
		}
		
		if(strcasecmp(vetor[i].categoria, "G")==0)//verificaçao para preencher o vetor gestao com suas respectivas equipes
		{
			gestao[g].media=vetor[i].media;
			strcpy(gestao[g].nome_equipe, vetor[i].nome_equipe);
			strcpy(gestao[g].categoria, vetor[i].categoria);
			gestao[g].C1 = vetor[i].C1;
			gestao[g].C2 = vetor[i].C2;
			gestao[g].C3 = vetor[i].C3;
			gestao[g].C4 = vetor[i].C4;
			gestao[g].C5 = vetor[i].C5;
			g++;
		}
		if(strcasecmp(vetor[i].categoria, "P")==0)//verificaçao para preencher o vetor projeto_social com suas respectivas equipes
		{
			projeto_social[ps].media=vetor[i].media;
			strcpy(projeto_social[ps].nome_equipe, vetor[i].nome_equipe);
			strcpy(projeto_social[ps].categoria, vetor[i].categoria);
			projeto_social[ps].C1 = vetor[i].C1;
			projeto_social[ps].C2 = vetor[i].C2;
			projeto_social[ps].C3 = vetor[i].C3;
			projeto_social[ps].C4 = vetor[i].C4;
			projeto_social[ps].C5 = vetor[i].C5;
			ps++;
		}
	}
}

void calculamedia (equipe vetor[11], int p)
{
	int i;
	for(i=0; i<p; i++)
	{	
		vetor[i].media = ((vetor[i].C1)+(vetor[i].C2)+(vetor[i].C3*2)+(vetor[i].C4*3)+ (vetor[i].C5*3))/10.0;
	} 
}
void desempate (equipe vetor [11], int p)
{
	int i, j;
	float aux, guarda;
	char auxi [30];
	
	for(i=0; i<p-1; i++) 
	{
		for(j=0; j<p-1-i; j++) 
		{
			if(vetor[j].media==vetor[j+1].media) 
			{	
				if(vetor[j].C4<vetor[j+1].C4)//o critério 4 é o de desempate, como pedido no descritivo
				{
					aux = vetor[j+1].media; //da linha 460 até a 490 é feita a troca das equipes no ranking, junto a todas as informações que elas possuem
					vetor[j+1].media= vetor[j].media;
					vetor[j].media = aux;
					
					strcpy(auxi, vetor[j+1].nome_equipe);
					strcpy(vetor[j+1].nome_equipe, vetor[j].nome_equipe);
					strcpy(vetor[j].nome_equipe, auxi);
					
					strcpy(auxi, vetor[j+1].categoria);
					strcpy(vetor[j+1].categoria, vetor[j].categoria);
					strcpy(vetor[j].categoria, auxi);
					
					guarda = vetor[j+1].C1;
					vetor[j+1].C1= vetor[j].C1;
					vetor[j].C1 = guarda;
					
					guarda = vetor[j+1].C2;
					vetor[j+1].C2= vetor[j].C2;
					vetor[j].C2 = guarda;
					
					guarda = vetor[j+1].C3;
					vetor[j+1].C3= vetor[j].C3;
					vetor[j].C3= guarda;
					
					guarda = vetor[j+1].C4;
					vetor[j+1].C4 = vetor[j].C4;
					vetor[j].C4 = guarda;
					
					guarda = vetor[j+1].C5;
					vetor[j+1].C5 = vetor[j].C5;
					vetor[j].C5 = guarda;
				
			   }
		   }
		}
   }
}

void gerasaida(equipe gestao[10], equipe projeto_social[10], equipe educacao[10], equipe vetor [11], int contador[3], int p)
{
 	
 	int i;
 	char arquivo[20];
 	
 	printf("O resultado do concurso esta pronto.\n");
 	printf("Digite o nome do arquivo de saida.\n");
 	scanf("%s", arquivo);
 	printf("Confira o resultado do concurso no arquivo gerado que esta na mesma pasta do programa.\n");
 	
 	strcat(arquivo, ".txt");
 	
 	FILE *arquivo_saida;
 	arquivo_saida = fopen(arquivo, "w");// o arquivo sera salvo no mesmo diretorio que o programa estiver
 	
 	fprintf(arquivo_saida, "RANKING\n");
 	fprintf(arquivo_saida, "        			C1		C2		C3		C4		C5		M\n");
 	
 	fprintf(arquivo_saida, "Educacao\n");
	for(i=0; i<contador[0]; i++)
	 {
	 	fprintf(arquivo_saida, "%s				%.2f		%.2f		%.2f		%.2f		%.2f		%.2f\n", educacao[i].nome_equipe, educacao[i].C1, educacao[i].C2, educacao[i].C3, educacao[i].C4, educacao[i].C5, educacao[i].media); 
	 }
	fprintf(arquivo_saida, "\nProjeto Social\n");
	 for(i=0; i<contador[1]; i++)
	 {
	 	fprintf(arquivo_saida, "%s				%.2f		%.2f		%.2f		%.2f		%.2f		%.2f\n", projeto_social[i].nome_equipe, projeto_social[i].C1, projeto_social[i].C2, projeto_social[i].C3, projeto_social[i].C4, projeto_social[i].C5, projeto_social[i].media); 
	 }
	 fprintf(arquivo_saida, "\nGestao\n");
	 for(i=0; i<contador[2]; i++)
	 {
	 	fprintf(arquivo_saida, "%s				%.2f		%.2f		%.2f		%.2f		%.2f		%.2f\n", gestao[i].nome_equipe, gestao[i].C1, gestao[i].C2, gestao[i].C3, gestao[i].C4, gestao[i].C5, gestao[i].media); 
	 }
	 
	 fprintf(arquivo_saida, "\n\nRESULTADO FINAL\n");
	 if(contador[0]>0)
	 {
	 	fprintf(arquivo_saida, "Educacao: %s\n", educacao[0].nome_equipe);
	 }
	 if(contador[1]>0)
	  {
	  	fprintf(arquivo_saida, "Projeto Social: %s\n",  projeto_social[0].nome_equipe);
	  }
	 if(contador[2]>0)
	 {
	 	fprintf(arquivo_saida, "Gestao: %s\n", gestao[0].nome_equipe);
	 }
	 
	 fprintf(arquivo_saida, "\n\nEquipes desclassificadas:\n");
	 for(i=0; i<p; i++)
	 {
	 	if(vetor[i].media<7)
	 	{
	 		fprintf(arquivo_saida, "%s\n", vetor[i].nome_equipe);
		}
	 }
	 fclose(arquivo_saida);
 }
