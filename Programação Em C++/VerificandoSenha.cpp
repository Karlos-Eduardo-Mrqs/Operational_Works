#include <cctype>	
#include <iostream>
#include <string>

void PopUps(const std::string , bool mai, bool min, bool tam, bool num, bool simbo, bool spac){
	
	std::string mensagem;
	
	mensagem = "Na sua senha faltou:";	
	
	if(!mai){
		mensagem += "letra maiuscula;";
	}if(!min){
		mensagem += "letra minuscula;";
	}if(!tam){
		mensagem += "tamanho adequado;";
	}if(!simbo){
		mensagem += "simbolos;";
	}if(!spac){
		mensagem += "deixou espaco;";
	}if(!num){
		mensagem += "numero;";
	}
	
	std::cout<<mensagem<<std::endl;
}

int main(){
	
	std::string senha;
	bool Maiusc = false;
	bool Minusc = false;
	bool TamanhoOk = false;
	bool TemNum = false;
	bool Espaco = false;
	bool Simbolo = false;
	
	std::cout<<"Digite sua senha [com 8 letras]:";
	std::cin>>senha;
	if(senha.length() >= 8){
		TamanhoOk = true; 
	}
	
	for(char letra : senha){
		if(isupper(letra)){
			Maiusc = true ;
		}if(islower(letra)){
			Minusc = true;	
		}if(isdigit(letra)){
			TemNum = true ;		
		}if(ispunct(letra)){
			Simbolo = true; 
		}if(isspace(letra)){
			Espaco = true;
		}
	}
	
	if(Maiusc && Minusc && TamanhoOk && TemNum && !Espaco && Simbolo){
		std::cout<<"A senha "<<senha<<", esta valida para uso"<<std::endl;	
	}else{
		PopUps(senha,Maiusc,Minusc,TamanhoOk,TemNum,Espaco,Simbolo);
	}	
	
	return 0;
}