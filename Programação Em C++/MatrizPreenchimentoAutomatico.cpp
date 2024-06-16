#include<iostream>

int main(){
	int Matriz[4] [4];
	
	for(int linha = 0 ; linha <= 3 ; linha++){
		for(int coluna = 0 ; coluna <= 3 ; coluna ++){
			switch(coluna){
				case 0: 
					Matriz[linha] [coluna] = 1;				
				break;
				
				case 1: 
					Matriz[linha] [coluna] = 1 * 10 ;				
				break;
				
				case 2: 
					Matriz[linha] [coluna] = 1 * 100;				
				break;
				
				case 3: 
					Matriz[linha] [coluna] = 1 * 1000;				
				break;
			}	
		}
	}
	
	for(int linha = 0 ; linha < 4 ; linha++){
		std::cout<<std::endl;
		for(int coluna = 0 ; coluna < 4 ; coluna ++){
			std::cout<<" | Valor ["<< linha << coluna << "] =" << Matriz[linha] [coluna]  <<  "| ";	
		}
	}
	return 0 ;
}