#include <stdio.h>

int main(void){
	char op;
	int tipo;
	int calc,num1,num2;
	
	printf("Digite o primeiro numero:");
	scanf("%d",&num1);
	printf("\n");
	printf("Digite o segundo numero:");
	scanf("%d",&num2);
	printf("\n");
	
	printf("Qual e o tipo de calculo que voce deseja fazer ? \n");
	printf(" |[1]Soma |[2]Subtracao| [3]Divisao| [4]Multiplicacao| \n");
	scanf("%d",&tipo);
	
	switch(tipo){
		case 1:
			calc=num1+num2;
			op='+';
		break;
		case 2:
			calc=num1-num2;
			op='-';
		break;
		case 3:
			calc=num1/num2;
			op='/';
		break;
		case 4:
			calc=num1*num2;
			op='x';
		break;
		default:
			return 0;
		break;
	}
	system("cls");
	printf("%d %c %d = %d",num1,op,num2,calc);
}