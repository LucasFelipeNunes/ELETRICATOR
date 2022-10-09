#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<unistd.h>
int main(){
	char escolha = '1';
	while(escolha == '1'){
    	char operacao;
    	setlocale(LC_ALL, "portuguese");
    	printf("\n\t\tE\t\t\t\t\t\t\t\tR\n\n\tL\t\tT\t\t\t\t\t\tO\n\nE\t\t\t\tR\t\t\t\tT\n\n\t\t\t\t\tI\t\tA\n\n\t\t\t\t\t\tC");
	    printf("\n\nPra voc� que n�o gosta de fazer contas de eletricidade, seus problemas acabaram!\nDigite a opera��o que o programa faz ela por voc�!");
	    printf("\n\nQual opera��o voce quer fazer?\n\nOPERACOES COM CORRENTE CONTINUA\n\n1 - Assoscia��o de resistores em Paralelo\n2 - Assoscia��o de resistores em Serie\n3 - Divisor de Corrente\n4 - Transforma��o Tri�ngulo-Estrela\n5 - Transforma��o Estrela-Tri�ngulo\n6 - Divisor de Tens�o\n\n");
		printf("OPERA��ES COM CORRENTE ALTERNADA\n\n7 - C�lculo de Reat�ncia Indutiva\n8 - C�lculo de Reat�ncia Capacitiva\n9 - C�lculo de Imped�ncia\n\n");
		printf("PROJETOS DE INSTALA��ES EL�TRICAS\n0 - C�lculo do n�mero e pot�ncia de tomadas por c�modo segundo a NBR 5410.\nDigite aqui: ");
		scanf("%s", &operacao);
		while(operacao != '1' && operacao != '2' && operacao != '3' && operacao != '4' && operacao != '5' && operacao != '6' && operacao != '7' && operacao != '8' && operacao != '9' && operacao != '0'){
		    printf("Valor invalido. Digite o valor de uma operacao, por favor: ");
		    scanf("%s", &operacao);
		}
		system("cls");
	    switch (operacao){
	        case '1':
	        	int resistorp, yp;
	    	    float parcial;
		        parcial = 0;
		        printf ("Digite a quantidade de resistores em paralelo: ");
	        	scanf("%d", &resistorp);
	        	for (yp = 1; yp <= resistorp; yp++){
	            	float valorp;
	            	printf("Digite o valor do resistor %d: ", yp);
	            	scanf("%f", &valorp);
	            	parcial = parcial + 1/valorp;
	        	}
	    	    float resultadop;
		        resultadop = 1/parcial;
		        printf("O resistor resultante dessa jun�ao vale %.2f ohms", resultadop);
	        break;
	        case '2':
				int resistors, ys;
	        	printf ("Digite a quantidade de resistores em s�rie: ");
	        	scanf("%d", &resistors);
	        	float valors, resultados;
	        	for(ys = 1;ys <= resistors;ys++){
		        	printf("Digite o valor do resistor %d (em ohms): ", ys);
		        	scanf("%f", &valors);
	    	    	resultados += valors;
	    		}
	        	printf("O resistor resultante dessa jun�ao vale %.2f ohms", resultados);	        	
	        break;
	        case '3':
		        float entrada, resistordc, resistoroposto, resultadodc;
		        printf("Qual a corrente de entrada? ");
		        scanf("%f", &entrada);
		        printf("Qual o valor do resistor do qual voc� quer a corrente? ");
		        scanf("%f", &resistordc);
		        printf("Qual o valor do outro resistor pra onde a corrrente vai? ");
		        scanf("%f", &resistoroposto);
		        resultadodc = entrada * resistoroposto / (resistoroposto + resistordc);
		        printf("A corrente no resistor � %.2f amp�rs", resultadodc);
		    break;
	        case '4':
	            char c [2], d [2], e [2];
	            float Rcd, Rde, Rce, Rc, Rd, Re;
	            printf("Vamos por partes\nQual o nome do primeiro ponto? ");
	            scanf("%s", &c);
	            printf("Qual o nome do segundo ponto? ");
	            scanf("%s", &d);
	            printf("Qual o nome do terceiro ponto? ");
	            scanf("%s", &e);
	            printf("Qual o valor do R%s%s?", c, d);
	            scanf("%f", &Rcd);
	            printf("Qual o valor do R%s%s?", d, e);
	            scanf("%f", &Rde);
	            printf("Qual o valor do R%s%s?", c, e);
	            scanf("%f", &Rce);
	            Rc = Rce * Rcd /(Rcd + Rce + Rde);
	            Rd = Rde * Rcd /(Rcd + Rce + Rde);
	            Re = Rce * Rde /(Rcd + Rce + Rde);
	            printf("\n\nO resultado de R%s � %.2f ohms", c, Rc);
	            printf("\nO resultado de R%s � %.2f ohms", d, Rd);
	            printf("\nO resultado de R%s � %.2f ohms", e, Re);
	        break;
	        case '5':
	            char c2 [2], d2 [2], e2 [2];
	            float Rc2, Rd2, Re2, Rcd2, Rde2, Rce2, somaprodutos;
	            printf("Qual o nome do primeiro ponto? ");
	            scanf("%s", &c2);
	            printf("\nQual o nome do segundo ponto? ");
	            scanf("%s", &d2);
	            printf("\nQual o nome do terceiro ponto? ");
	            scanf("%s", &e2);
		        printf("\nQual o valor de R%s ", &c2);
		        scanf("%f", &Rc2);
		        printf("\nQual o valor de R%s ", &d2);
		        scanf("%f", &Rd2);
		        printf("\nQual o valor de R%s ", &e2);
		        scanf("%f", &Re2);
		        somaprodutos = Rc2 * Rd2 + Rd2 * Re2 + Rc2 * Re2;
		        Rcd2 = somaprodutos / Re2;
		        Rce2 = somaprodutos / Rd2;
		        Rde2 = somaprodutos / Rc2;
		        printf("\nO valor de R%s%s � %f",c2,d2,Rcd2);
		        printf("\nO valor de R%s%s � %f",c2,e2,Rce2);
		        printf("\nO valor de R%s%s � %f",d2,e2,Rde2);
	        break;
	        case '6':
		        float tentrada, tresistordc, tresistoroposto, tresultadodc;
		        printf("Qual a tens�o de entrada? ");
		        scanf("%f", &tentrada);
		        printf("Qual o valor do resistor do qual voc� quer a tens�o? ");
		        scanf("%f", &tresistordc);
		        printf("Qual o valor do outro resistor pra onde a tens�o vai? ");
		        scanf("%f", &tresistoroposto);
		        tresultadodc = tentrada * tresistoroposto / (tresistoroposto + tresistordc);
		        printf("A tens�o no resistor � %.2f volts", tresultadodc);
	        break;
			case '7':
				float frequenciaL, L;
				double XL;
				printf("Digite o valor da frequ�ncia (em Hertz): ");
				scanf("%f", &frequenciaL);
				printf("Digite o valor da indut�ncia (em Henry): ");
				scanf("%f", &L);
				XL = 2 * M_PI * frequenciaL * L;
				printf("O valor da reat�ncia indutiva � %.2lf ohms", XL);
			break;
			case '8':
				float frequenciaC, C;
				double XC;
				printf("Digite o valor da frequ�ncia (em Hertz): ");
				scanf("%f", &frequenciaC);
				printf("Digite o valor da capacit�ncia (em Farad): ");
				scanf("%f", &C);
				XC = 1 / (2 * M_PI * frequenciaC * C);
				printf("O valor da reat�ncia capacitiva � %.2lf ohms", XC);
			break;
			case '9':
				double ZXx, ZR, Z;
				printf("Digite o valor da resist�ncia (em ohms): ");
				scanf("%lf", &ZR);
				printf("Digite o valor da diferen�a entre as reat�ncias (em ohms): ");
				scanf("%lf", &ZXx);
				Z = sqrt(pow(ZR, 2) + pow(ZXx, 2));
				printf("O valor da imped�ncia � %.2lf ohms", Z);
			break;
			case '0':
				int comodo, Piluminacao=100, tomada, sair;
				float area, perimetro;
				printf("\n\nPara qual c�modo voc� quer?\n\n1 - Banheiro\n2 - Cozinha, copa, �rea de servi�o, lavanderia ou afins\n3 - Varanda\n4 - Quarto, sala, dormit�rio ou afins\n5 - Outro c�modo\n\nDigite aqui: ");
				scanf("%d", &comodo);
				while (comodo < 1 || comodo > 5){
					system("cls");
					printf("Este n�mero � inv�lido, favor digitar um n�mero v�lido de c�modo:\n\n1 - Banheiro\n2 - Cozinha, copa, �rea de servi�o, lavanderia ou afins\n3 - Varanda\n4 - Quarto, sala, dormit�rio ou afins\n5 - Outro c�modo\n\nDigite aqui: ");
					scanf("%d", &comodo);
				}
				printf("\nDigite a �rea deste c�modo (em m�): ");
				scanf("%f", &area);
				printf("\nDigite o per�metro deste c�modo (em m): ");
				scanf("%f", &perimetro);
				system("cls");
				if(area > 6){
					Piluminacao += (area - 6) * 60;
				}
				printf("Resultados:\n\nA pot�ncia m�nima de ilumina��o deve ser de %d VA\n\n", Piluminacao);
				if(comodo == 1){
					printf("Deve ser colocada, pelo menos, 1 tomada, dentro do pr�prio c�modo");
				}
				else if(comodo == 2){
					tomada = perimetro/3.5;
					printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s)", tomada);
				}
				else if(comodo == 3){
					if(area > 2){
						printf("Deve ser colocada, pelo menos, 1 tomada, dentro do pr�prio c�modo (a n�o ser que a profundidade deste seja menor que 0,8 m)");
					}
					else{
						printf("Deve ser colocada, pelo menos, 1 tomada, fora, mas pr�xima do c�modo (at� 0,8 m distante da sua porta de acesso)");
					}
				}
				else if(comodo == 4){
					tomada = perimetro/5;
					printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s), dentro do pr�prio c�modo", tomada);
				}
				else if(comodo == 5){
					if(area <= 2.25){
						printf("Deve ser colocada, pelo menos, 1 tomada, fora, mas pr�xima do c�modo (at� 0,8 m distante da sua porta de acesso)");
					}
					else if(area > 2.25 && area <= 6){
						printf("Deve ser colocada, pelo menos, 1 tomada, dentro do pr�prio c�modo (a n�o ser que a profundidade deste seja menor que 0,8 m)");
					}
					else{
						tomada = perimetro/5;
						printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s), dentro do pr�prio c�modo", tomada);
					}
				}
				if(comodo == 1 || comodo == 2){
					if(tomada > 3){
						printf("\n\n3 tomadas tem que ter, no m�nimo, 600 VA, e as outras devem ter 100 VA no m�nimo");
					}
					else{
						printf("\n\nAs tomadas devem ter, no m�nimo, 600 VA cada");
					}
				}
				else{
					printf("\n\nAs tomadas devem ter, no m�nimo, 100 VA cada");
				}
			break;
	    }
	    printf("\n\nO que voc� deseja fazer?\n0 - Sair\n1 - Fazer outra opera��o\nDigite aqui: ");
	    scanf("%s", &escolha);
	    while(escolha != '0' && escolha != '1' && escolha != '2'){
			printf("\n\nEssa op��o n�o existe, por favor escolha outra op��o.");
	    	printf("\n\n\nO que voc� deseja fazer?\n0 - Sair\n1 - Fazer outra opera��o\nDigite aqui: ");
	    	scanf("%s", &escolha);
	    }
	    if(escolha == '1'){
		    printf("\n\nVoltando ao menu principal");
		    for(int i = 1;i <= 3;i++){
		    	sleep(1);
				printf(".");
			}
			system("cls");
		}
    }
}
