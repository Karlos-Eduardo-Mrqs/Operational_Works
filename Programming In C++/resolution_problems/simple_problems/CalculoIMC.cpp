#include <iostream>
#include <stdlib.h>

int main(){
	float peso,altura,imc;
	std::cout<<"Informe a sua altura:"<<std::endl;
	std::cin>>altura;
	std::cout<<"Informe a seu peso:"<<std::endl;
	std::cin>>peso;
	imc=peso/(altura*altura);
	system("clear||cls");
	std::cout<<"Seu IMC esta:";
	if(imc < 16.9){
		std::cout<<"MUITO ABAIXO DO PESO ("<<imc<<")";
	}if(imc > 17 && imc < 18.4){
		std::cout<<"ABAIXO DO PESO ("<<imc<<")";
	}if(imc > 18.5 && imc < 24.9){
		std::cout<<"PESO NORMAL ("<<imc<<")";
	}if(imc > 25 && imc < 29.9){
		std::cout<<"ACIMA DO PESO ("<<imc<<")";
	}if(imc > 30 && imc < 34){
		std::cout<<"OBESIDADE GRAU I ("<<imc<<")";
	}if(imc > 35 && imc < 40){
		std::cout<<"OBESIDADE GRAU II ("<<imc<<")";
	}if(imc >= 40){
		std::cout<<"OBESIDADE GRAU III ("<<imc<<")";
	}
	return 0;
}
