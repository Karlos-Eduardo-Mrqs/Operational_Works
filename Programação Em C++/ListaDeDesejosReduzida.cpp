#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int QuantDesejos = 0, CodNi = 0, indice = 0;
    std::string Titulo = "| Lista de Desejos |";
    bool TudoPreenchido = false, ListaDeNum = false;
	std::cout << "Quantos desejos deseja listar?: ";
    std::cin >> QuantDesejos;
    std::cin.ignore(); // Limpa o caractere de nova linha do buffer
    std::vector<std::string> Desejo(QuantDesejos, "!!!");
    std::vector<char> ConclusaoDesejo(QuantDesejos, 'X');
    char Resposta = 'S',Escolha;
    
	while (Resposta == 'S' || Resposta == 's') {
        system("cls");
        Titulo = (indice != 0) ? "| Lista de Desejos |" : "| Lista de Desejos Atualizada |";
        std::cout << Titulo << std::endl;
        for (indice = 0; indice < QuantDesejos; indice++) {
            std::cout << "Codigo De Mudanca[" << indice + 1 << "] Nome do Desejo->" << Desejo[indice] << "| Situacao [" << ConclusaoDesejo[indice] << "]" << std::endl;
        }
        std::cout << "Digite um codigo para adicionar o nome e sua situacao: ";
        std::cin >> CodNi;
        std::cin.ignore(); // Limpa o caractere de nova linha do buffer
        ListaDeNum = CodNi > 1 && CodNi <= QuantDesejos ;
		indice = CodNi - 1;
	    system("cls");
	    std::cout << "Desejo Selecionado ! | Codigo De Mudanca[" << CodNi << "] Nome do Desejo->" << Desejo[indice] << "| Situacao [" << ConclusaoDesejo[indice] << "]" << std::endl;
		std::cout << "Digite o Nome do Desejo: ";
	    std::getline(std::cin, Desejo[indice]);
	    std::cout << "Digite a Situacao do Desejo [X - Nao concluido | O - Concluido | * - Desenvolvendo]: ";
	    std::cin >> ConclusaoDesejo[indice];
	    std::cin.ignore(); // Limpa o caractere de nova linha do buffer
	    system("cls");
        TudoPreenchido = std::find(Desejo.begin(), Desejo.end(), "!!!") == Desejo.end();
		std::cout << "Desejo Alterado Com Sucesso ! | Codigo De Mudanca[" << CodNi << "] Nome do Desejo->" << Desejo[indice] << "| Situacao [" << ConclusaoDesejo[indice] << "]" << std::endl;
        std::cout << "Deseja Continuar [ S - Sim | N - Nao ] ?: ";
        std::cin >> Resposta;
	}
	if(TudoPreenchido){
		Resposta = 'S' ; 
		do{
			system("cls");
			Titulo="| Lista De Desejos Finalizada ! |";
			std::cout << Titulo << std::endl;
	        for (indice = 0; indice < QuantDesejos; indice++) {
	            std::cout << "Codigo De Mudanca[" << indice + 1 << "] Nome do Desejo->" << Desejo[indice] << "| Situacao [" << ConclusaoDesejo[indice] << "]" << std::endl;
	        }		
	        std::cout<<"Deseja Excluir ou Alterar Qual Desejo [E - Excluir | A - Alterar] ?:";
	        std::cin>>Escolha;
	        std::cout<<"Digite o codigo para "<< Escolha << " o desejo :";
	        std::cin>>CodNi;
	        switch(Escolha){
	        	case 'E':
	        	case 'e': 
	        		//
	        	break;
	        	
	        	case 'A':
	        	case 'a':
	        		//
	        	break;
	        	
	        	default;
	        	//
	        	break;
			}
		}while(Resposta == 'S' || Resposta == 's' );
	}
    return 0;
}