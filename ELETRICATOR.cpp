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
		printf("OPERA��ES COM CORRENTE ALTERNADA\n\n7 - Reat�ncia Indutiva\n8 - Reat�ncia Capacitiva\n9 - Imped�ncia\nDigite aqui: ");
		scanf("%s", &operacao);
		while(operacao != '1' && operacao != '2' && operacao != '3' && operacao != '4' && operacao != '5' && operacao != '6' && operacao != '7' && operacao != '8' && operacao != '9'){
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
