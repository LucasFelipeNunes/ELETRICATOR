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
	    printf("\n\nPra você que não gosta de fazer contas de eletricidade, seus problemas acabaram!\nDigite a operação que o programa faz ela por você!");
	    printf("\n\nQual operação voce quer fazer?\n\nOPERACOES COM CORRENTE CONTINUA\n\n1 - Assosciação de resistores em Paralelo\n2 - Assosciação de resistores em Serie\n3 - Divisor de Corrente\n4 - Transformação Triângulo-Estrela\n5 - Transformação Estrela-Triângulo\n6 - Divisor de Tensão\n\n");
		printf("OPERAÇÕES COM CORRENTE ALTERNADA\n\n7 - Cálculo de Reatância Indutiva\n8 - Cálculo de Reatância Capacitiva\n9 - Cálculo de Impedância\n\n");
		printf("PROJETOS DE INSTALAÇÕES ELÉTRICAS\n0 - Cálculo do número e potência de tomadas por cômodo segundo a NBR 5410.\nDigite aqui: ");
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
		        printf("O resistor resultante dessa junçao vale %.2f ohms", resultadop);
	        break;
	        case '2':
				int resistors, ys;
	        	printf ("Digite a quantidade de resistores em série: ");
	        	scanf("%d", &resistors);
	        	float valors, resultados;
	        	for(ys = 1;ys <= resistors;ys++){
		        	printf("Digite o valor do resistor %d (em ohms): ", ys);
		        	scanf("%f", &valors);
	    	    	resultados += valors;
	    		}
	        	printf("O resistor resultante dessa junçao vale %.2f ohms", resultados);	        	
	        break;
	        case '3':
		        float entrada, resistordc, resistoroposto, resultadodc;
		        printf("Qual a corrente de entrada? ");
		        scanf("%f", &entrada);
		        printf("Qual o valor do resistor do qual você quer a corrente? ");
		        scanf("%f", &resistordc);
		        printf("Qual o valor do outro resistor pra onde a corrrente vai? ");
		        scanf("%f", &resistoroposto);
		        resultadodc = entrada * resistoroposto / (resistoroposto + resistordc);
		        printf("A corrente no resistor é %.2f ampérs", resultadodc);
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
	            printf("\n\nO resultado de R%s é %.2f ohms", c, Rc);
	            printf("\nO resultado de R%s é %.2f ohms", d, Rd);
	            printf("\nO resultado de R%s é %.2f ohms", e, Re);
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
		        printf("\nO valor de R%s%s é %f",c2,d2,Rcd2);
		        printf("\nO valor de R%s%s é %f",c2,e2,Rce2);
		        printf("\nO valor de R%s%s é %f",d2,e2,Rde2);
	        break;
	        case '6':
		        float tentrada, tresistordc, tresistoroposto, tresultadodc;
		        printf("Qual a tensão de entrada? ");
		        scanf("%f", &tentrada);
		        printf("Qual o valor do resistor do qual você quer a tensão? ");
		        scanf("%f", &tresistordc);
		        printf("Qual o valor do outro resistor pra onde a tensão vai? ");
		        scanf("%f", &tresistoroposto);
		        tresultadodc = tentrada * tresistoroposto / (tresistoroposto + tresistordc);
		        printf("A tensão no resistor é %.2f volts", tresultadodc);
	        break;
			case '7':
				float frequenciaL, L;
				double XL;
				printf("Digite o valor da frequência (em Hertz): ");
				scanf("%f", &frequenciaL);
				printf("Digite o valor da indutância (em Henry): ");
				scanf("%f", &L);
				XL = 2 * M_PI * frequenciaL * L;
				printf("O valor da reatância indutiva é %.2lf ohms", XL);
			break;
			case '8':
				float frequenciaC, C;
				double XC;
				printf("Digite o valor da frequência (em Hertz): ");
				scanf("%f", &frequenciaC);
				printf("Digite o valor da capacitância (em Farad): ");
				scanf("%f", &C);
				XC = 1 / (2 * M_PI * frequenciaC * C);
				printf("O valor da reatância capacitiva é %.2lf ohms", XC);
			break;
			case '9':
				double ZXx, ZR, Z;
				printf("Digite o valor da resistência (em ohms): ");
				scanf("%lf", &ZR);
				printf("Digite o valor da diferença entre as reatâncias (em ohms): ");
				scanf("%lf", &ZXx);
				Z = sqrt(pow(ZR, 2) + pow(ZXx, 2));
				printf("O valor da impedância é %.2lf ohms", Z);
			break;
			case '0':
				int comodo, Piluminacao=100, tomada, sair;
				float area, perimetro;
				printf("\n\nPara qual cômodo você quer?\n\n1 - Banheiro\n2 - Cozinha, copa, área de serviço, lavanderia ou afins\n3 - Varanda\n4 - Quarto, sala, dormitório ou afins\n5 - Outro cômodo\n\nDigite aqui: ");
				scanf("%d", &comodo);
				while (comodo < 1 || comodo > 5){
					system("cls");
					printf("Este número é inválido, favor digitar um número válido de cômodo:\n\n1 - Banheiro\n2 - Cozinha, copa, área de serviço, lavanderia ou afins\n3 - Varanda\n4 - Quarto, sala, dormitório ou afins\n5 - Outro cômodo\n\nDigite aqui: ");
					scanf("%d", &comodo);
				}
				printf("\nDigite a área deste cômodo (em m²): ");
				scanf("%f", &area);
				printf("\nDigite o perímetro deste cômodo (em m): ");
				scanf("%f", &perimetro);
				system("cls");
				if(area > 6){
					Piluminacao += (area - 6) * 60;
				}
				printf("Resultados:\n\nA potência mínima de iluminação deve ser de %d VA\n\n", Piluminacao);
				if(comodo == 1){
					printf("Deve ser colocada, pelo menos, 1 tomada, dentro do próprio cômodo");
				}
				else if(comodo == 2){
					tomada = perimetro/3.5;
					printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s)", tomada);
				}
				else if(comodo == 3){
					if(area > 2){
						printf("Deve ser colocada, pelo menos, 1 tomada, dentro do próprio cômodo (a não ser que a profundidade deste seja menor que 0,8 m)");
					}
					else{
						printf("Deve ser colocada, pelo menos, 1 tomada, fora, mas próxima do cômodo (até 0,8 m distante da sua porta de acesso)");
					}
				}
				else if(comodo == 4){
					tomada = perimetro/5;
					printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s), dentro do próprio cômodo", tomada);
				}
				else if(comodo == 5){
					if(area <= 2.25){
						printf("Deve ser colocada, pelo menos, 1 tomada, fora, mas próxima do cômodo (até 0,8 m distante da sua porta de acesso)");
					}
					else if(area > 2.25 && area <= 6){
						printf("Deve ser colocada, pelo menos, 1 tomada, dentro do próprio cômodo (a não ser que a profundidade deste seja menor que 0,8 m)");
					}
					else{
						tomada = perimetro/5;
						printf("Deve(m) ser colocada(s), pelo menos, %d tomada(s), dentro do próprio cômodo", tomada);
					}
				}
				if(comodo == 1 || comodo == 2){
					if(tomada > 3){
						printf("\n\n3 tomadas tem que ter, no mínimo, 600 VA, e as outras devem ter 100 VA no mínimo");
					}
					else{
						printf("\n\nAs tomadas devem ter, no mínimo, 600 VA cada");
					}
				}
				else{
					printf("\n\nAs tomadas devem ter, no mínimo, 100 VA cada");
				}
			break;
	    }
	    printf("\n\nO que você deseja fazer?\n0 - Sair\n1 - Fazer outra operação\nDigite aqui: ");
	    scanf("%s", &escolha);
	    while(escolha != '0' && escolha != '1' && escolha != '2'){
			printf("\n\nEssa opção não existe, por favor escolha outra opção.");
	    	printf("\n\n\nO que você deseja fazer?\n0 - Sair\n1 - Fazer outra operação\nDigite aqui: ");
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
