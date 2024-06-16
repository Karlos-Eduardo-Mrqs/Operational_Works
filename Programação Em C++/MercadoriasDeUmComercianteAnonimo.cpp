#include <iostream>
//Comentários De Explicação, feitos pelo autor Carlos Eduardo

void LimparTela() { // Está função fará uma limpeza na Tela idependente de seu SO(Sistema Operacional)
	#ifdef _WIN32
	    system("cls");
	#else
	    system("clear");
	#endif
}

int main(){
	int contador = 0 , contador10Lucro = 0, contador15Lucro = 0 , contador20Lucro = 0 ; //Contadores do Lucro e Contador de Produto
	double Lucro=0 , PrecoDeCompra=0 , PrecoDeVenda=0; //Valores flutuantes dobrados.
	double TotalDeVenda=0 , TotalDeCompra=0 , TotalDeLucro=0; 
	double DzPorcento=0 , VntPorcento=0 ; // Valores da Compra em 10% e 20%
	std::string NomeDoProduto; 
	char Pare; // No final do looping será explicado
	bool ContinuarRelatorio=true; // No final do looping será explicado

	while(ContinuarRelatorio){
		contador+=1;
		LimparTela();
		std::cout<<"Nome do Produto ["<< contador <<"]:";
		std::cin>>NomeDoProduto;
		std::cout<<"Preco de Compra do Produto ["<< NomeDoProduto <<"]:";
		std::cin>>PrecoDeCompra;
		std::cout<<"Preco de Venda Do Produto ["<< NomeDoProduto <<"]:";
		std::cin>>PrecoDeVenda;
		Lucro = PrecoDeCompra - PrecoDeVenda;
		TotalDeLucro += Lucro; // O Operador(+=) e =  (TotalDeLucro = TotalDeLucro + Lucro). Isso se aplica aos demais +=.
		TotalDeVenda += PrecoDeVenda;
		TotalDeCompra += PrecoDeCompra; 
		DzPorcento = PrecoDeCompra * 0.1; // Ex: 10% do PrecoDeCompra; (120*10)/100 = 1200/100 = 12 | (PrecoDeCompra * Porcentagem) /100 ;
		VntPorcento = PrecoDeCompra * 0.2; // Ex: 20% do PrecoDeCompra; (150*20)/100 = 3000 / 100 = 30;
		contador10Lucro = (Lucro < DzPorcento) ? +1 : contador10Lucro ; // Se o Lucro for menor que DezPorcentoDeCompra, conte + 1 , senao, o valor do contador permanece o mesmo;
		contador20Lucro = (Lucro > VntPorcento) ? +1 : contador20Lucro ; //// Se o Lucro for menor que VintePorcentoDeCompra, conte + 1 , senao, o valor do contador permanece o mesmo;
		contador15Lucro = (Lucro > DzPorcento && Lucro < VntPorcento) ? +1 : contador15Lucro ; //Linha de baixo a explicação ; 
		// Se o Lucro for maior que DezPorcentoDeCompra e menor que VintePorcentoDeCompra , conte + 1 , senao, o valor do contador permanece o mesmo;
		std::cout<<"Voce Deseja Cadastrar Mais Alguma Mercadoria [Sim - S|s ou N - (-1)] ?:";
		std::cin>>Pare;
		ContinuarRelatorio=(Pare == 'S' || Pare == 's') ? true :false; 
		//Ao final do looping, será perguntado ao usuário caso ele continue ou não;Se o usuário digitar 's' ou 'S' como sim, a Tela será limpada e um novo produto será cadastro ;
		//senão,mostrará o relatorio da Loja(TotalDeVendas,Compras,Produtos,Lucro e entre outros dados);
	}
	
	LimparTela(); //No final a Tela é Limpada e o Relatorio é revelado;
	std::cout<< "Relatorio De Hoje Da Loja" <<std::endl;
	std::cout<< "Quantidade de Produtos Vendidos ["<< contador <<"]" <<std::endl;
	std::cout<< "Quantidade de Produtos Vendidos Com O Lucro Menor Que 10% ["<< contador10Lucro <<"]" <<std::endl;	
	std::cout<< "Quantidade de Produtos Vendidos com o lucro entre 10% Ate 20% ["<< contador15Lucro <<"]" <<std::endl;
	std::cout<< "Quantidade de Produtos Vendidos com o lucro maior que 20%["<< contador20Lucro <<"]" <<std::endl;
	std::cout<< "Total de Compra Dos Produtos ["<< TotalDeCompra <<"]" <<std::endl;
	std::cout<< "Total de Venda Dos Produtos ["<< TotalDeVenda <<"]" <<std::endl;
	std::cout<< "Total de Lucro Dos Produtos ["<< TotalDeLucro <<"]" <<std::endl;
	return 0 ;
}