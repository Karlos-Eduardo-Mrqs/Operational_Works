#include <cstdio>
#include <vector>
#include <stdlib.h>

int main(){
	std::vector<int> NumPar;
	std::vector<int> NumImpar;
	int TamPar,TamImpar,num=0,indice=0;
	
	for(indice = 1 ;indice <= 50 ;indice++){
		printf("Digite o %d numero:",indice);
		scanf("%d",&num);
		if(num % 2==0){
			NumPar.push_back(num++);
		}else{
			NumImpar.push_back(num--);
		}
	}
	system("cls");
	
	TamPar=NumPar.size();
	printf("\n Todos os numeros pares encontrados foram: \n");
	for(indice = 0 ;indice < TamPar ;indice++){
		printf("%d",NumPar[indice],"/");
	}
	
	TamImpar=NumImpar.size();
	printf("\n Todos os numeros impares encontrados foram: \n");
	for(indice = 0 ;indice < TamImpar ;indice++){
		printf("%d",NumImpar[indice],"/");
	}
	
}