#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>

bool Verificando(char letra){
	if(isdigit(letra) ){
		std::cout<<"Nao pode numero";
		return true;
	}if( ispunct(letra) ){
		std::cout<<"Nao pode simbolo";
		return true;
	}
	return false;
}

int main(){
	std::string palavra;
	int contV=0,contC=0;
	std::cout<<"Digite uma palavra:";
	std::cin>>palavra;
	
	for(char letra : palavra){
		if(!Verificando(letra)){
			
			switch ( toupper(letra) ){
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					contV+=1;
				break;
				default:
					contC+=1;
				break;
				
			}
		}
	}
	
	std::cout<<"A palavra "<<palavra<<" possui ao todo: ";
	std::cout<<contV<<" Vogais e "<<contC<<" Consoantes"<<std::endl;
	return 0;
}