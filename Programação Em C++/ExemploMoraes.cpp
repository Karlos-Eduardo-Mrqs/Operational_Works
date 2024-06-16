#include <iostream>
#include <vector>
int main(){
	int Qtdprodutos=0,NovoEstoque=0,CodigoMd=0;   
	std::string NovoNome; // Gabriel char:G || string:Gabriel
	std::cout<<"Digite o tamanho do estoque:";
	std::cin>>Qtdprodutos;
	std::vector<std::string> NomeProduto(Qtdprodutos,"!");
	std::vector<int> QuantidadeProdutos(Qtdprodutos,0);
	char RespMd; 
	bool QrMudar = true;
	while(QrMudar){
		system("cls");
		for(int i = 0 ; i < Qtdprodutos;i++){
			std::cout<< "Codigo Do Produto [" << i+1 <<"] Nome Do Produto ->"<< NomeProduto[i]  << "-> Estoque: " << QuantidadeProdutos[i] << std::endl ;		
		}
		std::cout<< "Digite o codigo do produto para alterar o estoque e seu nome :" <<std::endl;
		std::cin>>CodigoMd;
		std::cout<< "Produto Selecionado !" <<std::endl;
		std::cout<< "Codigo Do Produto [" << CodigoMd <<"] Nome Do Produto ->"<< NomeProduto[CodigoMd - 1]  << "-> Estoque: " << QuantidadeProdutos[CodigoMd - 1] << std::endl ;
		std::cout<<"Digite a nova quantidade de estoque:";
		std::cin>>NovoEstoque;
		QuantidadeProdutos[CodigoMd - 1] = NovoEstoque ; // [25] [0..24]
		std::cout<<"Digite o nome do produto no estoque:";
		std::cin>>NovoNome;
		NomeProduto[CodigoMd - 1] = NovoNome ; 
		system("cls");
		std::cout<< "Produto Alterado Com Sucesso !" << std::endl ;
		std::cout<< "Codigo Do Produto [" << CodigoMd <<"] Nome Do Produto -> "<< NomeProduto[CodigoMd - 1]  << "-> Estoque: " << QuantidadeProdutos[CodigoMd - 1] << std::endl ;
		std::cout<< "Deseja Alterar Mais Algo [S - Sim | N - nao]?:" <<std::endl;
		std::cin>>RespMd;
		QrMudar = (RespMd == 'S' || RespMd == 's') ; 
	}
		system("cls");
		std::cout<< "Estoque Finalizado !" <<std::endl;
		for(int i = 0 ; i < Qtdprodutos;i++){
			std::cout<< "Codigo Do Produto [" << i+1 <<"] Nome Do Produto ->"<< NomeProduto[i]  << "-> Estoque: " << QuantidadeProdutos[i] << std::endl ;
		}
	return 0;
}