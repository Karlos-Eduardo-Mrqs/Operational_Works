#include<stdio.h>
int main(){
	int num1,num2,sub;
	printf("Escreva dois numeros na tela: \n");
	scanf("%d",&num1);
	scanf("%d",&num2);
	sub=num1-num2;
	printf("%d - %d = %d\n",num1,num2,sub);
}