#include <iostream>
#include <vector>

bool ListaConvidados (std::string NomeConvidado, char Situacao) {
	std::string PessoaConvidou;
	std::vector<std::string> ListaDeConvidados = {"Luis_Luis","Carlos_Eduardo","Eduardo_Lessa","Victor_Leon","Leonardo_Santos","Gabriel_Moraes","Yan_Sacramento","Lucas_Andrade"} ; 
	
	switch(Situacao){
		
		case 'S':
		case 's':
			for(std::string Nome : ListaDeConvidados ){
				if(NomeConvidado == Nome){
					return true; 
				}
			}
		break;		
		
		case 'N':
		case 'n':
			std::cout<<"Quem Te Convidou Para Essa Festa ?:";
			std::cin>>PessoaConvidou;
			for(std::string Nome : ListaDeConvidados){
				if(PessoaConvidou == Nome){
					return true; 
				}
			}
		break;
		
		default:
		break;
	}
	
	return false;
}

int main(){
	std::string Mensagem = "";
	std::string NomePessoa, Titulo="| Festa Dos Sabios |";
	bool EstaNaLista = false;
	char Situacao;
	std::cout<< Titulo <<std::endl;
	std::cout<< "Digite Seu Nome [Ex:Felipe_Santos]:";
	std::cin>>NomePessoa;
	std::cout<< "Voce Foi Convidado Para a Festa [Sim - S|s ou Nao - N|n ]?:";
	std::cin>>Situacao;
	EstaNaLista = ListaConvidados(NomePessoa,Situacao) ;
	system("cls");
	std::cout<< Titulo <<std::endl;
	Mensagem = (EstaNaLista) ? "Seja Bem Vindo " + NomePessoa : "Sai Fora Veadin" ;
	std::cout<< Mensagem <<std::endl;
	return 0;
}