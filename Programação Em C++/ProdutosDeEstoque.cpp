#include <iostream>
#include <vector>
//Aviso Comentários Explicativos do Autor:Carlos Eduardo(Caso dúvidas Contate-me,ok?)
int main(){
	int cont,CodigoMd=0;
	char RespMd;
	std::vector<int> QuantidadeProdutos = {	100,50,90,70,80,95}; //Esse vetor irá armazenar a quantidade de estoque dos produtos(Por Isso ELe é Int)
	std::vector<std::string> Produtos = {"Pao_Frances","Carrinhos","Doces","Salgados","Balas_De_Goma","Maletas"}; 
	// Esse vetor acima, irá armazenar o nome de cada produto(ele não é char,por que ele não carrega o nome inteiro,só a primeira Letra).Ex: Digitei o Nome Carlos, o resultado de char:'C' e string:'Carlos';
	
	do{
		system("cls"); // Comando de Limpar a sua tela console(Tela Preta)
		for(int i= 0 ; i < Produtos.size() ; i++ ){
			std::cout<< "Codigo Do Produto [" << i+1 <<"] Nome do Produto ->" << Produtos[i] << "| Quantidade De Estoque ->" << QuantidadeProdutos[i] << std::endl ; //Exibição do vetor,exemplo:(CodProd [1] NomeProd ->Pao_Frances| QtdProdutos ->100)
		}
		std::cout<<"Digite o Codigo Do Produto Para Ser Alterado:";
		std::cin>>CodigoMd;
		CodigoMd -= 1;
		//Acima,você digitará o codigo de mudança para alterar o produto.Quando Digitar o codigo 2;Você vai alterar os Carrinhos,entretanto,terá que subtrair -1 do codigo para conseguir alterar o vetor,por conta dele começar com 0,então se eu colocar o codigo 2 sem subtrai-lo, vou estar alterando os DOCES e não os Carrinhos; 	
		system("cls");
		std::cout<< "Codigo Do Produto [" << CodigoMd+1 <<"] Nome do Produto ->" << Produtos[CodigoMd] << "| Quantidade De Estoque ->" << QuantidadeProdutos[CodigoMd] << std::endl ; 
		std::cout<< "O que sera alterado nesse produto [N - Nome do Produto | E - Quantidade De Estoque]?:";
		std::cin>>RespMd;
		//Acima,será exibido o produto escolhido por você,e vai te perguntar o que será alterado o Nome ou o Estoque.Logo Abaixo,é utilizado a condição Escolha,dependendo da ESCOLHA do usuário,o produto terá alteração em algum lugar(No NOME ou ESTOQUE)
		switch(RespMd){
			case 'N':
				std::cout<< "Digite o Novo Nome Do Produto:";
				std::cin>>Produtos[CodigoMd];
			break;
			
			case 'E':
				std::cout<< "Digite a Quantidade Atual de Estoque:"; 
				std::cin>>QuantidadeProdutos[CodigoMd];
			break;
		}
			std::cout<< "Produto Alterado com Sucesso ! "<< std::endl ; 
			std::cout<< "Codigo Do Produto [" << CodigoMd+1 <<"] Nome do Produto ->" << Produtos[CodigoMd] << "| Quantidade De Estoque ->" << QuantidadeProdutos[CodigoMd] << std::endl ; 
			//Acima,o produto será mostrado,com a alteração que você fez.Abaixo,vai te perguntar se deseja Alterar Mais Algo;Se SIM,Ele retorna na exibição do estoque,Senão ele te exibe o estoque novamento com tudo atualizado.
			std::cout<< "Deseja Alterar Mais Algo [S - Sim | N - nao]?:" <<std::endl;
			std::cin>>RespMd;
			cont =  (RespMd == 'S' || RespMd == 's') ? 1 : 0 ;
	}while(cont != 0);
	system("cls");
	std::cout<< "Estoque Finalizado !" <<std::endl;
	for(int i= 0 ; i < Produtos.size() ; i++ ){
			std::cout<< "Codigo Do Produto [" << i+1 <<"] Nome do Produto ->" << Produtos[i] << "| Quantidade De Estoque ->" << QuantidadeProdutos[i] << std::endl ; 
	}
	
	return 0 ; // E esse foi o codigo, o que achou ?,tem alguma dúvida?, contate ao autor. 
}