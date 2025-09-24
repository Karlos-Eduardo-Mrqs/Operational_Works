#include <iostream>
#include <vector>

void LimparTela() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void MemoriaEstoque(const std::vector<std::string>&NomeProd,const std::vector<int>&QtdEstoque){
	int TamEstoque = NomeProd.size();
	for(int i = 0 ; i < TamEstoque ;i++){
		std::cout<< "Codigo de Mudanca:["<< i <<"] -> Nome Do Produto:" << NomeProd[i] << "| Estoque Do Produto:" << QtdEstoque[i] <<std::endl;
	}
}

void AtualizarEstoque(std::vector<std::string>&NomeProd,std::vector<int>&QtdEstoque,bool Atualizar){
	int CodMudanca = 0;
	char Resposta;
	if(Atualizar){
		while(Atualizar){
			LimparTela();
			MemoriaEstoque(NomeProd,QtdEstoque);
			std::cout<<"Digite o Codigo De Mudanca Do Produto Que Voce Deseja Alterar:";
			std::cin>>CodMudanca;
			LimparTela();
			std::cout<<"Nome Do Produto Selecionado: "<< NomeProd[CodMudanca] << "| Estoque do Produto Selecionado: " << QtdEstoque[CodMudanca] <<std::endl;
			std::cout<<"O nome sera alterado [Sim - s | Nao - n]?:";
			std::cin>>Resposta;
			
			if(Resposta == 'S' || Resposta == 's'){
				std::cout<<"Digite o Novo Nome Do Produto:";
				std::cin>>NomeProd[CodMudanca];
			}
			
			std::cout<<"O estoque sera alterado [Sim - s | Nao - n]?:";
			std::cin>>Resposta;
			
			if(Resposta == 'S' || Resposta == 's'){
				std::cout<<"Digite o Novo Estoque Do Produto:";
				std::cin>>QtdEstoque[CodMudanca];
			}
			
			std::cout<< "Codigo de Mudanca: ["<< CodMudanca  << "] -> Nome Do Produto:" << NomeProd[CodMudanca] << "| Estoque Do Produto:" << QtdEstoque[CodMudanca] <<std::endl;
			std::cout<<"Deseja Modificar Mais Algum Produto [Sim- S | Nao - N] ?:";
			std::cin>>Resposta;
			Atualizar = (Resposta == 'S' || Resposta == 's');
		}
	}
}

void CadastroEstoque(std::vector<std::string>&NomeProd,std::vector<int>&QtdEstoque){
	bool QrCadastrar=true, QrAtualizar= true;
	char Resposta;
	std::string Nome;
	int NumEstoque;
	while (QrCadastrar){
		LimparTela();
		std::cout<<"Mercadinho Do Seu Ze"<<std::endl;
		std::cout<<"Digite o Nome do Produto:";
		std::cin>>Nome;
		std::cout<<"Digite a Quantidade de Estoque de "<< Nome <<":";
		std::cin>>NumEstoque;
		NomeProd.push_back(Nome);
		QtdEstoque.push_back(NumEstoque);
		std::cout<<"Deseja Continuar Cadastrando Produtos no Estoque [Sim- S | Nao - N] ?:";
		std::cin>>Resposta;
		QrCadastrar = (Resposta == 'S' || Resposta == 's') ;
		if(!QrCadastrar){
			std::cout<<"Deseja Modificar O Estoque Dos Produtos [Sim- S | Nao - N] ?:";
			std::cin>>Resposta;
			QrAtualizar = (Resposta == 'S' || Resposta == 's') ;
			AtualizarEstoque(NomeProd,QtdEstoque,QrAtualizar);	
		}
	}
}

int main(){
	std::vector<std::string> NomeProd;
	std::vector<int> QtdEstoque;
	CadastroEstoque(NomeProd,QtdEstoque);
	LimparTela();
	MemoriaEstoque(NomeProd,QtdEstoque);
	return 0 ;
}