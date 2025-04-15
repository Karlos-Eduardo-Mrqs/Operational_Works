#include <iostream>

int main(){
	int Matriz [4] [2];
	float MediaM = 0;	
	
	for(int linha = 0 ; linha <= 4 ; linha ++){
		std::cout<<std::endl;
		for(int coluna = 0 ; coluna < 2 ; coluna++){
			std::cout<< "Matriz ["<< linha <<coluna << "]:";
			std::cin>>Matriz [linha] [coluna] ;	
			MediaM += Matriz [linha] [coluna] ;
		}
	}
	
	MediaM/= 10;
	std::cout<< "A media de todos os elementos da matriz :" << MediaM <<std::endl;
	
	return 0;
}