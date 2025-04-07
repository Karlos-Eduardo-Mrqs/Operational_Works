#include <iostream>
int main(){
	int contador = 0 , contador10Lcr = 0 , contador1020Lcr = 0 , contador20Lcr = 0;
	double PorcentagemLcr=0, Lucro=0, PrCompra=0, PrVenda=0, TotCompra=0, TotVenda=0, TotLcr=0;
	bool QrCadastrar = true;
	char Situacao;
	while(QrCadastrar){
		contador++;
		std::cout<<"Produto [" << contador <<"]: \n";
		std::cout<<"Preco De Compra Do Produto:";
		std::cin>> PrCompra;
		std::cout<<"Preco De Venda Do Produto:";
		std::cin>> PrVenda;
		Lucro = PrCompra - PrVenda; 
		TotCompra += PrCompra;
		TotVenda += PrVenda;
		TotLcr += Lucro;
		PorcentagemLcr = (Lucro / PrCompra )/100; 
		contador10Lcr = (PorcentagemLcr < 10) ?  contador10Lcr + 1 : contador10Lcr ;
		contador1020Lcr = (PorcentagemLcr >= 10 && PorcentagemLcr <= 20 ) ?  contador1020Lcr + 1 : contador1020Lcr ;
		contador20Lcr = (PorcentagemLcr > 20) ?  contador20Lcr + 1 : contador20Lcr ;
		std::cout<<"Deseja Continuar Cadastrar [Sim - S | Nao - N] ?:";
		std::cin>> Situacao;
		QrCadastrar = (Situacao == 'S' || Situacao == 's') ;
	}
	system("cls");
	std::cout<<"Total De Produtos Cadastrados:" << contador << std::endl;
	std::cout<<"Total De Compra Dos Produtos:" << TotCompra << std::endl;
	std::cout<<"Total De Venda Dos Produtos:" << TotVenda << std::endl;
	std::cout<<"Total De Lucro Dos Produtos:" << TotLcr << std::endl;
	std::cout<<"Total Dos Produtos Com O Lucro Menor Que 10%:" << contador10Lcr << std::endl;
	std::cout<<"Total Dos Produtos Com O Lucro Entre 10% E 20%:" << contador1020Lcr << std::endl;
	std::cout<<"Total Dos Produtos Com O Lucro Maior Que 20%:" << contador20Lcr << std::endl;
	return 0;
}