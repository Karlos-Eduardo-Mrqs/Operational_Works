#include <iostream>

int main(){
	int num1=0, num2=0;
	std::cout<<"\n Digite o primeiro numero:";
	std::cin>>num1;
	std::cout<<" Digite o segundo numero:";
	std::cin>>num2;
	
	if(num1 > num2){
		std::cout<< num1 <<" e MAIOR que "<<num2;
	}else if(num1 < num2){
		std::cout<<num1<<" e MENOR que "<<num2;
	}else{
		std::cout<<"\nOs dois numeros sao iguais";
	}
	return 0;
}