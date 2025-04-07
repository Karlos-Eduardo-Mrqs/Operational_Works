#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <utility>

std::vector <std::string> Cadastro;
std::vector <std::string> Mensagem;
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
	
	bool TamanhoNome=true ,EspacoNome=false, LetraAlpha=true ;
	bool NomeCorreto = true;
	
	std::vector<char> SimbolosValidos = {'@', '#', '$', '!', ';', '|', '&', '%', '/', '=', '?'};
	
	TamanhoSenha = Senha.size() >= 8 ;
	for(const auto& letra : Senha){
		SenhaEmMaiusc |= isupper(letra) ;
		SenhaEmMinusc |= islower(letra) ;
		SenhaComNums |= isdigit(letra) ;
		SenhaComSimbs |= std::find(SimbolosValidos.begin(), SimbolosValidos.end(), letra) != SimbolosValidos.end();
	}
	
	SenhaCorreta = (TamanhoSenha && SenhaEmMaiusc && SenhaEmMinusc && SenhaComNums && SenhaComSimbs);
	
	TamanhoNome = Nome.size() >= 5 && Nome.size() <=20 ;
	for(const auto& letra : Nome){
		EspacoNome |= isspace(letra);
		LetraAlpha &= isalpha(letra);
	}
	
	NomeCorreto = (TamanhoNome && !EspacoNome && LetraAlpha);
	
	retorno = NomeCorreto && SenhaCorreta ? "Dados Valido" : "Dados Invalido" ;
	return retorno ;
}

std::vector <std::string> Login(std::string Titulo, std::vector<std::string> Cadastro, bool Certos){
	std::string NomeCads = "Admin" , SenhaCads = "senha123", Nome , Senha;
	std::string mensNome = "Digite Seu Nome:" , mensSenha = "Digite Sua Senha";
	int contErros = 3;
	bool LogCerto = false, NomeCerto= false , SenhaCerta= false;
	
	Titulo = Certos ? " Testando Login No Sistema SAVA Da Estacio |":"| Login Sistema SAVA Da Estacio |";
	do{
		LimparTela();
		std::cout<<Titulo<<std::endl;
		
		std::cout<<mensNome;
		std::cin>>Nome;
		
		std::cout<<mensSenha;
		std::cin>>Senha;
		
		NomeCads = Certos ? Cadastro[0]: NomeCads;
		SenhaCads = Certos ? Cadastro[1] : SenhaCads; 
		
		NomeCerto = (Nome == NomeCads );
		SenhaCerta = (Senha == SenhaCads );
		
		if(NomeCerto && SenhaCerta){
			LogCerto = true;
		}else{
			LogCerto = false;
			mensNome="Digite Seu Nome Novamente:";
			mensSenha="Digite Sua Senha Novamente:";
			contErros--;
		}
		
	}while(contErros > 0 || LogCerto );
	if(!LogCerto && contErros == 0){
		Mensagem.push_back("Login Falhou Apos as tres tentativas!");
	}else{
		Mensagem.push_back("Login Sucedido !");
	}
	return Mensagem ;
}
std::vector<std::string> Cadastre(std::string Titulo, std::vector<std::string> Cadastro, bool UserCad) {
    std::string mensNome = "Digite Seu Nome:" , mensSenha = "Digite Sua Senha";
    std::string ResultVerify,Nome,Senha;
    int contErros = 3;
    bool Certos = false;
    Titulo = !UserCad ? "| Cadastro Sistema SAVA Da Estacio |" : "| Sistema SAVA Da Estacio |" ;
    do{
        LimparTela();
        std::cout<<Titulo<<std::endl;
        std::cout<<mensNome;
        std::cin>>Nome;
        
        std::cout<<mensSenha;
        std::cin>>Senha;
        
        ResultVerify = DadosVerificados(Nome,Senha);
        
        if(ResultVerify == "Dados Invalidos"){
            Certos = false;
            mensNome="Digite Seu Nome Novamente:";
            mensSenha="Digite Sua Senha Novamente:";
            contErros--;
        }else{
            Certos = true;
        }
        
    }while(contErros > 0 || Certos );
    
    if(Certos){
        Cadastro.push_back(Nome);
        Cadastro.push_back(Senha);
        Mensagem.push_back("Cadastro Bem Sucedido");
    }else if (!Certos && contErros == 0){
        Mensagem.push_back("Cadastro Falhou Apos as tres tentativas de criacao");
    }
    return Mensagem; 
}


int main(){
	char SouN;
	bool UserCad,TestCad;
	std::vector<std::string> PopUp;
	std::string Titulo = "| Sistema SAVA Da Estacio |";
	std::cout<<Titulo<<std::endl;
	std::cout<<"Voce ja e cadastrado aqui no SAVA [Sim - S ou s | Nao - N ou n]?:";
	std::cin>> SouN;
	UserCad = (SouN == 'S' || SouN == 's') ;
	if(UserCad){
		PopUp = Login(Titulo,Cadastro,false);
	}else{
		PopUp = Cadastre(Titulo,Cadastro,UserCad);
	}
	LimparTela();
	for(int i = 0 ;i < PopUp.size() ; i++){
		std::cout<<PopUp[i]<<std::endl;
		if(PopUp[i] == "Cadastro Bem Sucedido"){
			std::cout<<"Voce deseja testar o seu cadastro no SAVA [Sim - S ou s | Nao - N ou n]?:";
			std::cin>> SouN;
			TestCad = (SouN =='S' || SouN =='s') ;
			if(TestCad){
				Login(Titulo,Cadastro,TestCad);
			}
		}
	}
	return 0 ;
}