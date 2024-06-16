#include <iostream>

int main(){
	int Matriz [2] [2];
	for(int linha = 0 ; linha < 2 ;linha++){
		for(int coluna = 0 ; coluna < 2 ; coluna++){
			std::cout<<"Imprima o valor ["<< linha << coluna <<"]:";
			std::cin>>Matriz[linha][coluna];
		}
	}
	return 0;
}