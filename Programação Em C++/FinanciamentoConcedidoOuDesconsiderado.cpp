#include <iostream>

//Comentários para explicação, Criados pelo autor Carlos Eduardo ;
int main(){
	float Financiamento,Salario; //Dados flutuantes. Salario:1.200 e Financiamento:3.500 Por exemplo;
	std::string NomeCliente,SituacaoFin; // Variaveis para obter o nome do cliente e escrever uma mensagem relacionada a Situação do Financiamento do Cliente;
	for(int NumCliente = 1 ; NumCliente <= 5 ; NumCliente++ ){
		SituacaoFin = ""; // Resetando a variável, para não haver complicações na mensagem final(Será explicado nos comentários abaixo da variavel SituacaoFin).
		
		std::cout<<"Quem e o cliente que deseja nos consultar?: \n";
		std::cin>>NomeCliente;
		
		std::cout<<"Qual e o salario do(a)"<< NomeCliente <<": \n";
		std::cin>>Salario;
		
		std::cout<<"Qual valor de financiamento que o(a)" << NomeCliente <<" deseja ?: \n";
		std::cin>>Financiamento;
		
		SituacaoFin += NomeCliente + " Seu" ;  // Resultado aqui: Antonio_Junior Seu (Formando uma frase aos poucos ao decorer do algoritmo) 
		SituacaoFin += Financiamento <= Salario*5 ? " Financiamento Foi Concedido" : " Financiamento Foi Negado" ; 
		// Caso o Financiamento seja menor que o Salario multiplicado por (Linha de baixo)
		//SituacaoFin = Antonio_Junior Seu Financiamento foi Concedido || Caso contrátrio Antonio_Junior Seu Financiamento Foi Negado 
		
		SituacaoFin += ", Obrigado Por Nos Consultar"; // Adicionando o final da mensagem.Ex:Antonio_Junior Seu Financiamento foi Concedido, Obrigado Por Nos Consultar.
		
		std::cout<<SituacaoFin<<std::endl; //Exibição Da Mensagem;Para o proximo cliente essa mensagem será apagada;
	}
	return 0;
}