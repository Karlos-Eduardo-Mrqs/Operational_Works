#include <iostream>
#include <vector>
#include <string>

void Limpando() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Listando(const std::vector<std::string>& Lista, std::vector<char>& ConclusaoDesejo) {
    Limpando();
    int QtsDesejos = Lista.size();
    int NumMudanca = 0;
    char SimbConclusao, resp;
    bool QrContinuar = true;

    while (QrContinuar) {
        std::cout << "Lista De Desejos Criada" << std::endl;
        for (int i = 0; i < QtsDesejos; i++) {
            std::cout << "Numero do Desejo [" << i + 1 << "] -> Desejo: " << Lista[i] << " | Situacao Do Desejo [" << ConclusaoDesejo[i] << "]" << std::endl;
        }
        std::cout << "Legenda: [X] Nao Concluido | [O] Concluida | [*] Desenvolvendo" << std::endl;
        std::cout << "Digite o Numero do Desejo para alterar a sua situacao: ";
        std::cin >> NumMudanca;
        NumMudanca -= 1;

        if (NumMudanca >= 0 && NumMudanca < QtsDesejos) {
			std::cout << Lista[NumMudanca] << " ja esta [" << ConclusaoDesejo[NumMudanca] << "]." << std::endl;
            std::cout << "Digite a nova situacao: ";
            std::cin >> SimbConclusao;
            ConclusaoDesejo[NumMudanca] = SimbConclusao;
        } else {
            std::cout << "Numero de desejo invalido!" << std::endl;
        }

        Limpando();
        std::cout << Lista[NumMudanca] << " | " << ConclusaoDesejo[NumMudanca] << std::endl;
        std::cout << "Deseja alterar mais alguma? [Sim - S | Nao - N]: ";
        std::cin >> resp;
        std::cin.ignore(); 
        QrContinuar = (resp == 'S' || resp == 's');
    }
    Limpando();
    std::cout << "Lista De Desejos Finalizada" << std::endl;
    for (int i = 0; i < QtsDesejos; i++) {
        std::cout << "Numero do Desejo [" << i + 1 << "] -> Desejo: " << Lista[i] << " | Situacao Do Desejo [" << ConclusaoDesejo[i] << "]" << std::endl;
    }
    
}

void CriandoLista(std::vector<std::string>& Lista, std::vector<char>& ConclusaoDesejo) {
    char resp;
    bool Continuar = true;
    std::string Desejo;
    while (Continuar) {
        Limpando();
        std::cout << "Lista De Desejos" << std::endl;
        std::cout << "Coloque algo que deseja fazer: ";
        Lista.push_back(Desejo);
        std::getline(std::cin, Desejo);
        ConclusaoDesejo.push_back('X'); 
        std::cout << "Deseja fazer alguma coisa [Sim - S | Nao - N]?: ";
        std::cin >> resp;
        std::cin.ignore(); 
        Continuar = (resp == 'S' || resp == 's');
    }
    Listando(Lista, ConclusaoDesejo);
}

int main() {
    std::vector<std::string> Lista;
    std::vector<char> ConclusaoDesejo;
    CriandoLista(Lista, ConclusaoDesejo);
    return 0;
}