#include <iostream>
#include <vector>
#include <algorithm>
int main(){
	std::vector<int> numeros(10);
	int Maior=0,Soma=0;
	for(int i = 0 ; i < 10; i++){
		std::cout<<"Digite o "<< i+1 << " numero:";
		std::cin>>numeros[i];
		Soma+=numeros[i];
	}
	std::sort(numeros.begin() , numeros.end());
	Maior=numeros.back();
	std::cout<<"O Maior Numero e: "<<Maior<<" e a soma de todos os numeros e:"<<Soma;
	return 0 ;
}