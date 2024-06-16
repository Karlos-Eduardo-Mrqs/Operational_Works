#include <vector>
#include<iostream>
int main(){
	int ContProd = 0 , CodAlt = 0 , EstoqueAlt = 0 ; 
	char Continue = 'S';
	std::cout<<"Quantos Produtos Temos Armazenados no Estoque?:";
	std::cin>>ContProd;
	std::vector<int> QtsEstoque(ContProd,0);
	while(Continue == 'S' || Continue == 's'){
		system("cls");
		for(int i = 0 ; i < ContProd ; i++){
			std::cout<<"Codigo Produto["<< i+1 <<"] Quantidade De Estoque["<< QtsEstoque[i] <<"]" << std::endl;
		}
		std::cout<<"Digite o codigo do produto para alterar o estoque:";
		std::cin>>CodAlt;
		std::cout<<"Produto Selecionado | Codigo Produto["<< CodAlt <<"] Quantidade De Estoque["<< QtsEstoque[CodAlt - 1] <<"]" << std::endl;
		std::cout<<"Digite a nova quantidade de estoque:";
		std::cin>>EstoqueAlt;
		QtsEstoque[CodAlt - 1] = EstoqueAlt ; 
		std::cout<<"Produto Alterado | Codigo Produto["<< CodAlt <<"] Quantidade De Estoque["<< QtsEstoque[CodAlt - 1] <<"]" << std::endl;
		std::cout<<"Deseja Continuar [Sim - S | Nao - N]?:";	
		std::cin>>Continue;
	}
	system("cls");
	std::cout<< "Estoque Organizado ! " <<std::endl;
	for(int i = 0 ; i < ContProd ; i++){
		std::cout<<"Codigo Produto["<< i+1 <<"] Quantidade De Estoque["<< QtsEstoque[i] <<"]" << std::endl;
	}
	return 0;
}