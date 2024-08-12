#include <iostream>
#include <string>

int main(){
	int n1,n2,media;
	std::string situacao;
	std::cout<<"Primeira nota:";
	std::cin>>n1;
	std::cout<<"Segunda Nota:";
	std::cin>>n2;
	if(n1 > 10 || n2 > 10){
		std::cout<<"Uma das notas ultrapassou o limite";
		return 0;
	}
	media=(n1+n2)/2;
	situacao = media >= 6 ? "Aprovado" : "Reprovado";
	std::cout<<"Sua media foi:"<<media<<"| entao voce foi :"<<situacao<<std::endl;
	return 0;
}