#include <iostream>
#include <stdlib.h>

int main(){
	char letra;
	std::cout<<"Digite uma letra:";
	std::cin>>letra;
	system("clear||cls");
	std::cout<<"A letra"<<letra<<"=";
	switch(letra){
		case 'A' :
		case 'E' :
		case 'I' :
		case 'O' :
		case 'U' :
			std::cout<<" VOGAL";
		break;
	
		default:
			std::cout<<" CONSOANTE";
		break;
	}
	return 0;
}