#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <utility>

std::vector <std::string> Cadastro;

void LimparTela() {
	#ifdef _WIN32
	    system("cls");
	#else
	    system("clear");
	#endif
}

std::string DadosVerificados(std::string Nome, std::string Senha){
	std::string retorno;
	
	bool SenhaEmMaiusc=false , SenhaEmMinusc=false, SenhaComNums=false, SenhaComSimbs=false , TamanhoSenha = false;
	bool SenhaCorreta=true;
	
	bool TamanhoNome=true , LetraAlpha=true ;
	bool NomeCorreto = true;
	
	std::vector<char> SimbolosValidos = {'@', '#', '$', '!', ';', '|', '&', '%', '/', '=', '?'};
	
	for(const auto& letra : Senha){
		TamanhoSenha = Senha.size() >= 8 ;
		SenhaEmMaiusc |= isupper(letra) ;
		SenhaEmMinusc |= islower(letra) ;
		SenhaComNums |= isdigit(letra) ;
		SenhaComSimbs |= std::find(SimbolosValidos.begin(), SimbolosValidos.end(), letra) != SimbolosValidos.end();
	}
	
	SenhaCorreta = (TamanhoSenha && SenhaEmMaiusc && SenhaEmMinusc && SenhaComNums && SenhaComSimbs);
	
	for(const auto& letra : Nome){
		TamanhoNome = Nome.size() >= 5 && Nome.size() <=20 ;
		LetraAlpha &= isalpha(letra);
	}
	
	NomeCorreto = (TamanhoNome && LetraAlpha);
	
	retorno = NomeCorreto && SenhaCorreta ? "Dados Valido" : "Dados Invalido" ;
	return retorno ;
}

std::string Login(std::string Titulo, std::vector<std::string>& Cadastro, bool Certos, std::string& Mensagem) {
    std::string NomeCads = "Admin", SenhaCads = "senha123", Nome, Senha;
    std::string mensNome = "Digite Seu Nome:", mensSenha = "Digite Sua Senha:";
    int contErros = 3;
    bool LogCerto = false, NomeCerto = false, SenhaCerta = false;

    if (Certos && !Cadastro.empty() ) {
        NomeCads = Cadastro[0];
        SenhaCads = Cadastro[1];
    }

    Titulo = Certos ? " Testando Login No Sistema SAVA Da Estacio |" : "| Login Sistema SAVA Da Estacio |";

    while (contErros > 0 && !LogCerto) {
        LimparTela();
        std::cout << Titulo << std::endl;

        std::cout << mensNome;
        std::cin >> Nome;

        std::cout << mensSenha;
        std::cin >> Senha;

        NomeCerto = (Nome == NomeCads) ? true:false;
        SenhaCerta = (Senha == SenhaCads) ? true:false;
        
        if (NomeCerto && SenhaCerta) {
            LogCerto = true;
        } else {
            LogCerto = false;
            mensNome = "Digite Seu Nome Novamente:";
            mensSenha = "Digite Sua Senha Novamente:";
            contErros--;
        }
    }
    Mensagem = (LogCerto) ?  "Login Bem Sucedido!": "Login Falhou Após as três tentativas!";
    
    return Mensagem;
}

std::string Cadastre(std::string Titulo, std::vector<std::string>& Cadastro, bool UserCad,std::string& Mensagem) {
    std::string mensNome = "Digite Seu Nome:", mensSenha = "Digite Sua Senha:";
    std::string Nome, Senha;
    int contErros = 3;
    bool Certos = false;
    Titulo = !UserCad ? "| Cadastro no Sistema SAVA Da Estacio |" : "| Sistema SAVA Da Estacio |";

    while (contErros > 0 && !Certos) {
		LimparTela();
        std::cout << Titulo << std::endl;
        std::cout << Mensagem << std::endl;
		std::cout << mensNome;
        std::cin >> Nome;

        std::cout << mensSenha;
        std::cin >> Senha;

        Mensagem = DadosVerificados(Nome, Senha);
		
        if (Mensagem == "Dados Invalidos") {
            Certos = false;
            mensNome = "Digite Seu Nome Novamente:";
            mensSenha = "Digite Sua Senha Novamente:";
            contErros--;
        }
        else {
            Certos = true;
        }
    }

    if (Certos) {
        Cadastro.push_back(Nome);
        Cadastro.push_back(Senha);
        Mensagem = "Cadastro Bem Sucedido";
    }
    else if (!Certos && contErros == 0) {
        Mensagem = "Cadastro Falhou Apos as tres tentativas de criacao";
    }
    return Mensagem;
}

int main() {
    char SouN;
    bool UserCad = false, TestCad = false;
    std::string Titulo = "| Sistema SAVA Da Estacio |";
    std::string Mensagem = "";

    std::cout << "Voce ja e cadastrado aqui no SAVA [Sim - S ou s | Nao - N ou n]?: ";
    std::cin >> SouN;

    UserCad = (SouN == 'S' || SouN == 's');

    if (UserCad) {
        Mensagem = Login(Titulo, Cadastro, false, Mensagem);
    } else {
        Mensagem = Cadastre(Titulo, Cadastro, UserCad, Mensagem);
    }
    
    LimparTela();
    std::cout << Mensagem << std::endl;

    if (Mensagem == "Cadastro Bem Sucedido") {
		std::cout << "Voce deseja testar o seu cadastro no SAVA [Sim - S ou s | Nao - N ou n]?: ";
        std::cin >> SouN;

        TestCad = (SouN == 'S' || SouN == 's') ? true : false;
        if (!TestCad) {
		    Mensagem = "Teste de login cancelado. Saindo...";
		    std::cout << Mensagem << std::endl;
		} else {
		    Mensagem = Login(Titulo, Cadastro, true, Mensagem);
		    LimparTela();
		    std::cout << Mensagem << std::endl;
		}
    }
    return 0;
}