	#include <cstdio>
	int main(){
		float media=0;
		float bonus=0;
		float ved1=0,ved2=0,ved3=0;
		printf	("Escreva quais foram as suas tres ultimas vendas ?:");
		scanf("%f %f %f", &ved1, &ved2, &ved3);
		media=(ved1+ved2+ved3)/3;
		bonus=(media*10)/100;
		printf(" \n A Media das vendas e %f:",media);
		printf(" \n O Bonus das vendas e %f:",bonus);
	}