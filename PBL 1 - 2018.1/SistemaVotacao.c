//Sistema de Votaçao TSEc


/***************************
Autora: ESTHER DE SANTANA ARAUJO
Componente Curricular: Algoritmos e Programação I
Concluido em: 29 de abril de 2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************/
	
	#include <stdio.h>
	#include <stdlib.h>

	int main(){
			
			double numtitulo;
			int confirma, votopres, votogov, votosen, votodepfed, votodepest, resposta, totalvotos=0;
			int validospres=0, validosgov=0, validossen=0, validosfed=0, validosest=0;
			int maeli=0, antonio_do_brasil=0, lissandro_progresso=0, brancopres=0, nulopres=0, feminpres=0, mascpres=0;
			int maia_da_ana=0, gentil=0, dona_selma_silva=0, brancogov=0, nulogov=0, femingov=0, mascgov=0;
			int gutemberg_silva=0, fernando_fernandes=0, brancosen=0, nulosen=0, feminsen=0, mascsen=0;
			int ana_vitoria=0, paulo_guilherme=0, brancofed=0, nulofed=0, feminfed=0, mascfed=0;
			int ana_rita_pacheco=0, ana_guilherme=0, adalberto_campos=0, brancoest=0, nuloest=0, feminest=0, mascest=0;
			
		do //esse laço de repetição servirá para realizar um número de votações nao determinado previamente (linha 29 até linha 316)
			{ 
				printf("Digite o numero do seu titulo de eleitor:\n");
				scanf("%lf", &numtitulo);
			
			system("cls");
			
			do //esse laço de repetição servirá para permitir a confirmação do voto, e está presente no processo de votação dos demais cargos políticos
			{
				printf("Indique o numero correspondente ao seu candidato a presidencia.\n");
				printf("(17) Sra. Maeli Gente Boa\n");
				printf("(22) S r. Antonio do Brasil\n");
				printf("(31) Dr. Lissandro Progresso\n");
				printf("(0) Branco\n");
				printf("Numeros invalidos serao computados como nulos.\n");
				scanf("%d", &votopres);
				printf("Para confirmar seu voto no candidato de numero %d , digite 1. Para corrigir seu voto digite 2\n", votopres);
				scanf("%d", &confirma);
			}while(confirma==2);
			
			// os seguintes operadores condicionais irão adicionar os votos nos candidatos escolhidos, para que o calculo de porcentagem seja realizado
			if(votopres==17)
			{
				maeli++;
				feminpres++;
				validospres++;
			}
			else if(votopres==22)
			{
				antonio_do_brasil++;
				mascpres++;
				validospres++;
			}
			else if(votopres==31)
			{
				lissandro_progresso++;
				mascpres++;
				validospres++;
			}
			else if(votopres==0)
			{
				brancopres++;
			}
			else
				nulopres++;
			
		
			system("cls");
			
			do{
				printf("Indique o numero correspondente ao seu candidato a Governador.\n");
				printf("(38) Sr. Maia da Ana\n");
				printf("(40) Sr. Gentil\n");
				printf("(18) Sra. Dona Selma Silva\n");
				printf("(0) Branco\n");
				printf("Numeros invalidos serao computados como nulos.\n");
				scanf("%d", &votogov);
				printf("Para confirmar seu voto no candidato de numero %d , digite 1. Para corrigir seu voto digite 2\n", votogov);
				scanf("%d", &confirma);
			}while(confirma==2);
			
			// os seguintes operadores condicionais irão adicionar os votos nos candidatos escolhidos, para que o calculo de porcentagem seja realizado
			if(votogov==38)
			{
				maia_da_ana++;
				mascgov++;
				validosgov++;
			}
			else if(votogov==40)
			{
				gentil++;
				mascgov++;
				validosgov++;
			}
			else if(votogov==18)
			{
				dona_selma_silva++;
				femingov++;
				validosgov++;
			}
			else if(votogov==0)
			{
				brancogov++;
			}
			else
				nulogov++;
				
			system("cls");
				
			do{	
				printf("Indique o numero correspondente ao seu candidato a Senador.\n");
				printf("(04) Sr. Gutemberg Silva\n");
				printf("(67) Sr. Fernando Fernandes\n");
				printf("(0) Branco\n");
				printf("Numeros invalidos serao computados como nulos.\n");
				scanf("%d", &votosen);
				printf("Para confirmar seu voto no candidato de numero %d , digite 1. Para corrigir seu voto digite 2\n", votosen);
				scanf("%d", &confirma);
			}while(confirma==2);
			
			// os seguintes operadores condicionais irão adicionar os votos nos candidatos escolhidos, para que o calculo de porcentagem seja realizado
			if(votosen==04)
			{	
				gutemberg_silva++;
				mascsen++;
				validossen++;
			}
			else if(votosen==67)
			{
				fernando_fernandes++;
				mascsen++;
				validossen++;
			}
			else if(votosen==0)
			{
				brancosen++;
			}
			else
				nulosen++;
				
			system("cls");
			
			do{
				printf("Indique o numero correspondente ao seu candidato a Deputado Federal.\n");
				printf("(56) Sra. Ana Vitoria\n");
				printf("(33) Sr. Paulo Guilherme\n");
				printf("(0) Branco\n");
				printf("Numeros invalidos serao computados como nulos.\n");
				scanf("%d", &votodepfed);
				printf("Para confirmar seu voto no candidato de numero %d , digite 1. Para corrigir seu voto digite 2\n", votodepfed);
				scanf("%d", &confirma);
			}while(confirma==2);
			
			// os seguintes operadores condicionais irão adicionar os votos nos candidatos escolhidos, para que o calculo de porcentagem seja realizado
			if(votodepfed == 56)
			{
				ana_vitoria++;
				feminfed++;
				validosfed++;
			}
			else if(votodepfed == 33)
			{
				paulo_guilherme++;
				mascfed++;
				validosfed++;
			}
			else if(votodepfed == 0)
			{
				brancofed++;
			}
			else
				nulofed++;
				
			system("cls");
			do{
				printf("Indique o numero correspondente ao seu candidato a Deputado Estadual.\n");
				printf("(51) Dra. Ana Rita Pacheco\n");
				printf("(34) Sra. Ana Guilherme\n");
				printf("(11) Sr. Adalberto Campos\n");
				printf("(0) Branco\n");
				printf("Numeros invalidos serao computados como nulos.\n");
				scanf("%d", &votodepest);
				printf("Para confirmar seu voto no candidato de numero %d , digite 1. Para corrigir seu voto digite 2\n", votodepest);
				scanf("%d", &confirma);
			}while(confirma==2);
			
			// os seguintes operadores condicionais irão adicionar os votos nos candidatos escolhidos, para que o calculo de porcentagem seja realizado
			
			if(votodepest == 51)
			{
				ana_rita_pacheco++;
				feminest++;
				validosest++;
			}
			else if(votodepest == 34)
			{
				ana_guilherme++;
				feminest++;
				validosest++;
			}
			else if(votodepest == 11)
			{
				adalberto_campos++;
				mascest++;
				validosest++;
			}
			else if(votodepest == 0)
			{
				brancoest++;
			}
			else
				nuloest++;
			
				system ("cls");
				printf("Espelho de votacao do eleitor: %.0f\n", numtitulo);
			
			// os seguintes operadores condicionais servem para printar na tela os votos do usuario, fornecendo seu espelho de votação
			if(votopres==17)
			{
				printf("Presidente: (17)- Sra. Maeli Gente Boa\n");
			}
			else if(votopres==22)
			{
				printf("Presidente: (22)- Sr. Antonio do Brasil\n");
			}
			else if(votopres==31)
			{
				printf("Presidente:(31)- Dr. Lissandro Progresso\n");
			}
			else if(votopres==0)
			{
				printf("Presidente: (0)- Branco\n");
			}
			else
			{
				printf("Presidente: Nulo\n");
			}
		
			if(votogov==38)
			{
				printf("Governador: (38)- Sr. Maia da Ana\n");
			}
			else if(votogov==40)
			{
				printf("Governador: (40)- Sr. Gentil\n");
			}
			else if(votogov==18)
			{
				printf("Governadora: (18)- Sra. Dona Selma Silva\n");
			}
			else if(votogov==0)
			{
				printf("Governador: (0)- Branco\n");
			}
			else
			 {
				printf("Governador: Nulo\n"); 
			}
			
			if(votosen==04)
			{	
				printf("Senador: (04)- Sr. Gutemberg Silva\n");
			}
			else if(votosen==67)
			{	
				printf("Senador: (67)- Sr. Fernando Fernandes\n");
		    }
		    else if(votosen==0)
		    {
		    	printf("Senador: (0)- Branco\n");
			}
			else
			{
				printf("Senador: Nulo\n");
			}
			
			if(votodepfed==56)
			{
				printf("Deputada Federal: (56)- Sra. Ana Vitoria\n");
			}
			else if(votodepfed==33)
			{
				printf("Deputado Federal: (33)- Sr. Paulo Guilherme\n");
		    }
		    else if(votodepfed==0)
		    {
		    	printf("Deputado Federal: (0)- Branco\n");
			}
			else
			{
				printf("Deputado Federal: Nulo\n");
			}
			
			if(votodepest==51)
			{
				printf("Deputada Estadual: (51)- Dra. Ana Rita Pacheco\n");
			}
			else if(votodepest==34)
			{
				printf("Deputada Estadual: (34)- Sra. Ana Guilherme\n");
			}
			else if(votodepest==11)
			{
				printf("Deputado Estadual: (11)- Sr. Adalberto Campos\n");
			}
			else if(votodepest==0)
			{
				printf("Deputado Estadual: (0)- Branco\n");
			}
			else
			{
				printf("Deputado Estadual: Nulo\n");
			}
			
			totalvotos++;
			
				printf("Para encerrar a eleicao, digite 1. Se ainda houver eleitores, digite 2.\n");
				scanf("%d",&resposta);
			}while(resposta!=1);
			
				printf("\n\n");
				printf("Cargo: Presidente\n");
			if(validospres>0)
			{			
				// os condicionais da linha 336 até a linha 343 informam se ha necessidade da realização do segundo turno, de acordo com as regras do TSE
				if((maeli * 100 / validospres)<=50 && (antonio_do_brasil * 100 / validospres)<=50 && (lissandro_progresso * 100 / validospres)<=50)
				{
					printf("Havera segundo turno.");
				}
				else
				{
					printf("Nao havera segundo turno.");
				}
				printf("Sra. Maeli Gente Boa obteve um total de %d votos, correspondendo a %.2f %% \n", maeli, (float) maeli * 100 / validospres);
				printf("Sr. Antonio do Brasil obteve um total de %d votos, correspondendo a %.2f %% \n", antonio_do_brasil, (float) antonio_do_brasil * 100 / validospres);
				printf("Dr. Lissandro Progresso obteve um total de %d votos, correspondendo a %.2f %% \n", lissandro_progresso, (float) lissandro_progresso * 100 / validospres);
				printf("Nessa categoria, houve um total de %d votos em mulheres, correspondendo a %.2f %% \n", feminpres, (float) feminpres * 100 / validospres);
				printf("Nessa categoria, houve um total de %d votos em homens, correspondendo a %.2f %% \n", mascpres, (float) mascpres * 100/ validospres);
			}
			else
			{
				printf("Nao houveram votos validos para este cargo.\n");
			}
				printf("Houve um total de %d votos brancos, correspondendo a %.2f %% do total \n", brancopres, (float) brancopres * 100/ totalvotos);
				printf("Houve um total de %d votos nulos, correspondendo a %.2f %% do total \n\n", nulopres, (float) nulopres * 100/ totalvotos);
				printf("\n\n");
				
				printf("Cargo: Governador\n");
			if(validosgov>0)
			{
				printf("Sr. Maia da Ana obteve um total de %d votos, correspondendo a %.2f %% \n", maia_da_ana, (float) maia_da_ana * 100 / validosgov);
				printf("Sr. Gentil obteve um total de %d votos, correspondendo a %.2f %% \n", gentil, (float) gentil * 100 / validosgov);
				printf("Sra. Dona Selma Silva obteve um total de %d votos, correspondendo a %.2f %% \n", dona_selma_silva, (float) dona_selma_silva * 100 / validosgov);
				printf("Nessa categoria, houve um total de %d votos em mulheres, correspondendo a %.2f %% \n", femingov, (float) femingov * 100 / validosgov);
				printf("Nessa categoria, houve um total de %d votos em homens, correspondendo a %.2f %% \n", mascgov, (float) mascgov * 100/ validosgov);
			}
			else
			{
				printf("Nao houveram votos validos para este cargo.\n");
			}
				printf("Houve um total de %d votos brancos, correspondendo a %.2f %% do total \n", brancogov, (float) brancogov * 100/ totalvotos);
				printf("Houve um total de %d votos nulos, correspondendo a %.2f %% do total \n", nulogov, (float) nulogov * 100/ totalvotos);
				printf("\n\n");
			
				printf("Cargo: Senador\n");
			if(validossen>0)
			{
				printf("Sr. Fernando Fernandes obteve um total de %d votos, correspondendo a %.2f %% \n", fernando_fernandes, (float) fernando_fernandes * 100 / validossen);
				printf("Sr. Gutemberg Silva obteve um total de %d votos, correspondendo a %.2f %% \n", gutemberg_silva, (float) gutemberg_silva * 100 / validossen);
				printf("Nessa categoria, houve um total de %d votos em mulheres, correspondendo a %.2f %% \n", feminsen, (float) feminsen * 100 / validossen);
				printf("Nessa categoria, houve um total de %d votos em homens, correspondendo a %.2f %% \n", mascsen, (float) mascsen * 100/ validossen);
			}
			else
			{
				printf("Não houveram votos validos para este cargo.\n");
			}
				printf("Houve um total de %d votos brancos, correspondendo a %.2f %% do total \n", brancosen, (float) brancosen * 100/ totalvotos);
				printf("Houve um total de %d votos nulos, correspondendo a %.2f %% do total \n", nulosen, (float) nulosen * 100/ totalvotos);
				printf("\n\n");
			
				printf("Cargo: Deputado Federal\n");
			if(validosfed>0)
			{
				printf("Sra. Ana Vitoria obteve um total de %d votos, correspondendo a %.2f %% \n", ana_vitoria, (float) ana_vitoria * 100 / validosfed);
				printf("Sr. Paulo Guilherme obteve um total de %d votos, correspondendo a %.2f %% \n", paulo_guilherme, (float) paulo_guilherme * 100 / validosfed);
				printf("Nessa categoria, houve um total de %d votos em mulheres, correspondendo a %.2f %% \n", feminfed, (float) feminfed * 100 / validosfed);
				printf("Nessa categoria, houve um total de %d votos em homens, correspondendo a %.2f %% \n", mascfed, (float) mascfed * 100/ validosfed);
			}
			else
			{
				printf("Não houveram votos validos para este cargo.\n");
			}
				printf("Houve um total de %d votos brancos, correspondendo a %.2f %% do total \n", brancofed, (float) brancofed * 100/ totalvotos);
				printf("Houve um total de %d votos nulos, correspondendo a %.2f %% do total \n", nulofed, (float) nulofed * 100/ totalvotos);
				printf("\n\n");
			
			printf("Cargo: Deputado Estadual\n");
			if(validosest>0)
			{
				printf("Dra. Ana Rita Pacheco obteve um total de %d votos, correspondendo a %.2f %% \n", ana_rita_pacheco, (float) ana_rita_pacheco * 100 / validosest);
				printf("Sra. Ana Guilherme obteve um total de %d votos, correspondendo a %.2f %% \n", ana_guilherme, (float) ana_guilherme * 100 / validosest);
				printf("Sr. Adalberto Campos obteve um total de %d votos, correspondendo a %.2f %% \n", adalberto_campos, (float) adalberto_campos * 100 / validosest);
				printf("Nessa categoria, houve um total de %d votos em mulheres, correspondendo a %.2f %% \n", feminest, (float) feminest * 100 / validosest);
				printf("Nessa categoria, houve um total de %d votos em homens, correspondendo a %.2f %% \n", mascest, (float) mascest * 100/ validosest);
			}
			else
			{
				printf("Não houveram votos validos para este cargo.\n");
			}
				printf("Houve um total de %d votos brancos, correspondendo a %.2f %% do total \n", brancoest, (float) brancoest * 100/ totalvotos);
				printf("Houve um total de %d votos nulos, correspondendo a %.2f %% do total \n", nuloest, (float) nuloest * 100/ totalvotos);
				printf("\n\n");
			
				return 0;
		}
