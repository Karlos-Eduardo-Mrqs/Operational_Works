#include <iostream>


int Somar(int num1 , int num2){
	std::cout << num1 << "+" << num2 <<"=" << num1+num2;
	return 0;
}

int main(){
	int num1,num2;
	std::cout<<"Digite o primeiro numero:";
	std::cin>>num1;
	std::cout<<"Digite o segundo numero:";
	std::cin>>num2;
	Somar(num1,num2);
}