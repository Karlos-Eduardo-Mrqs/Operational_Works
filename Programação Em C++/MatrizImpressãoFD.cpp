#include<iostream>
#include<stdlib.h>

int main(){
	int linha,coluna;
	std::cout<<"Voce quer quantas linhas na matriz?:";
	std::cin>>linha;
	std::cout<<"Voce quer quantas colunas na matriz?:";
	std::cin>>coluna;
	
	system("cls");
	int matriz [linha] [coluna];
	for(int contC = 0 ; contC < coluna; contC++){
		for(int contL = 0 ; contL < linha ; contL++){
			std::cout<<"Valor"<<"[" << contC << " coluna" << "," << contL << " linha" <<"]" <<":";
			std::cin>>matriz[contC][contL];
		}
	}
	
	system("cls");
	std::cout<<"Matriz"<< "|" << linha<< " X " << coluna << std::endl ;
	for(int contC=0 ; contC < coluna; contC++){
		std::cout<<std::endl;
		for(int contL = 0 ; contL < linha ; contL++){
			std::cout<< matriz[contC][contL] << " | ";
		}
	}
	
	return 0 ;
}