#include <iostream>
int main(){
	int QtsMercadorias = 0 , Cont10Lcr = 0 , Cont1020Lcr = 0 , Cont20Lcr = 0 ;
	double PrecoCompra =0 , PrecoVenda = 0 , TotalCmpr = 0 , TotalVnd = 0 , PorcentagemLcr = 0 , Lucro = 0 ;
	std::cout<<"Quantas Mercadorias Nos Temos ?:";
	std::cin>>QtsMercadorias;
	for(int i = 1 ; i <= QtsMercadorias ; i++){
		system("cls");
		std::cout<< "Produto N["<< i << "] :" <<std::endl;
		std::cout<< "Digite o preco de compra:";
		std::cin>>PrecoCompra;
		std::cout<< "Digite o preco de venda:";
		std::cin>>PrecoVenda;
		TotalCmpr += PrecoCompra ;
		TotalVnd += PrecoVenda ;
		Lucro = PrecoVenda - PrecoCompra ;
		PorcentagemLcr = (Lucro / PrecoCompra) * 100 ;
		Cont10Lcr = (PorcentagemLcr < 10) ? Cont10Lcr + 1 : Cont10Lcr ;
		Cont1020Lcr = (PorcentagemLcr >= 10 && PorcentagemLcr <= 20) ? Cont1020Lcr + 1 : Cont1020Lcr ;
		Cont20Lcr = (PorcentagemLcr > 20) ? Cont20Lcr + 1 : Cont20Lcr ;
	}
	system("cls");
	std::cout << "Total De Compra de Todos Os Produtos :" << TotalCmpr << std::endl;
	std::cout << "Total De Vendas de Todos Os Produtos :" << TotalVnd << std::endl;
	std::cout << "Mercadorias com lucro menor que 10%: " << Cont10Lcr << std::endl;
    std::cout << "Mercadorias com lucro entre 10% e 20%: " << Cont1020Lcr << std::endl;
    std::cout << "Mercadorias com lucro maior que 20%: " << Cont20Lcr << std::endl;
	return 0;
}