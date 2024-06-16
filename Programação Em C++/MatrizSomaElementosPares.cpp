#include <iostream>

int main(){
	int Matriz [5] [5] ;
	int ContadorPar = 0 , SomaN3L = 0 ;
	
	for(int linha = 0 ; linha < 5 ; linha++){
		std::cout<<std::endl;
		for(int coluna = 0 ; coluna < 5 ; coluna++){
			std::cout<<"Valor da Matriz["<<linha<<coluna<<"]:";
			std::cin>> Matriz[linha] [coluna];
			ContadorPar = (Matriz[linha] [coluna] % 2 == 0) ? ContadorPar + 1 :ContadorPar ;
			SomaN3L = (linha == 2) ? SomaN3L + Matriz[linha] [coluna] : SomaN3L ;
		}
	}
	
	system("cls");
	std::cout<<"Matriz 5 X 5" << std::endl;
	for(int linha = 0 ; linha < 5 ; linha++){
		std::cout<<std::endl;
		for(int coluna = 0 ; coluna < 5 ; coluna++){
			std::cout<<" | Valor["<<linha<<coluna<<"]:"<< Matriz[linha] [coluna]<< "| " << std::endl;
		}
	}
	
	std::cout<<"A soma dos elementos da Terceira Linha:"<< SomaN3L << std::endl;
	std::cout<<"Quantidade de Numeros Pares na Matriz:"<< ContadorPar << std::endl;
	
	std::cout<<"Matriz 5 X 5 repaginada" << std::endl;
	for(int linha = 0 ; linha < 5 ; linha++){
		std::cout<<std::endl;
		for(int coluna = 0 ; coluna < 5 ; coluna++){
			if(linha == coluna){		
				Matriz[linha] [coluna] = 0 ;
			}
			std::cout<<" | Valor["<<linha<<coluna<<"]:"<< Matriz[linha] [coluna]<< "| ";
		}
	}
	
	return 0 ;	
}