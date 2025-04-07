#include <iostream>	
int main() {
    int contador10P=0,contador1020P=0,contador20P=0, quantosPd = 0;
	int TotalCompra=0 , TotalVenda=0 , TotalLucro = 0;
	double PrecoCompra=0, PrecoVenda=0, Lucro=0 , Porcentagem=0;
	std::cout << "Digite quantas mercadorias você quer cadastrar: ";
	std::cin >> quantosPd;
	    for (int i = 1; i <= quantosPd; ++i) {
			std::cout <<"Produto Numero[" << i << "]:" << std::endl;
	        std::cout <<"Digite o preco de compra do produto:";
	        std::cin >> PrecoCompra;
	        std::cout <<"Digite o preco de venda do produto :";
	        std::cin>> PrecoVenda;
	        Lucro = PrecoCompra - PrecoVenda;
	        TotalLucro += Lucro;
	        TotalVenda += PrecoVenda ;
	        TotalCompra += PrecoCompra ;
	        Porcentagem = (Lucro * 100) / 100 ;
	        contador10P = (Porcentagem < 10) ? contador10P+1 : contador10P ;
	        contador1020P = (Porcentagem >= 10 && Porcentagem <= 20) ? contador1020P+1 : contador1020P ;
	        contador20P = (Porcentagem > 20) ? contador20P+1 : contador20P ;
	    	std::cout<<Porcentagem<<"% porcento de lucro do produto" << i << "!" << std::endl;
		}
	system("cls");	
	std::cout<<"O Total de Compra dos produtos foi:" << TotalCompra<<std::endl;
	std::cout<<"O Total de Venda dos produtos foi:" << TotalVenda<<std::endl;
	std::cout<<"O Total de Lucro dos produtos foi:" << TotalLucro<<std::endl;
	std::cout<<contador10P<<"produtos tem seu lucro menor que 10%"<<std::endl;
	std::cout<<contador1020P<<"produtos tem seu lucro entre 10% e 20%"<<std::endl;
	std::cout<<contador20P<<"produtos tem seu lucro maior que 20%"<<std::endl;
	return 0;
}