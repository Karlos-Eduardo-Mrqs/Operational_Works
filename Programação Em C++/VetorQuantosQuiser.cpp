#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

int main (){
	int quantos = 0;
	std::cout<<("Digite quantos numeros você quer ordenar?:");
	std::cin>>(quantos);
	std::vector<int> numeros(quantos);
	for(int i=0;i<quantos;i++){
		std::cout<<"Digite o "<< i <<" numero:";
		std::cin>>(numeros[i]);		
	}
	system("clear || cls");
	std::sort(numeros.begin(), numeros.end());
	std::cout<<("Ordem Crescente:");
	for(int num : numeros){
		std::cout<<(num)<<";";
	}	
	return 0;
}