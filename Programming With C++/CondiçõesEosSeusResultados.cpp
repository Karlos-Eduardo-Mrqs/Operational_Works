#include<iostream>

void CondicoesIf(){
	bool condicao1EVerdade= false,condicao2EVerdade = true; // Modifique aqui para true ou false
	std::cout<<"Condicoes Com IF(SE)"<<std::endl;
	if(condicao1EVerdade){ 
		std::cout<<"Executa o IF Quando Verdadeiro"<<std::endl;
	}else if(condicao2EVerdade){
		std::cout<<"Executa o ELSE IF Quando O IF E(´) Falso e o ELSE IF E(´) Verdadeiro"<<std::endl;
	}else{
		std::cout<<"Executa o ELSE Quando O IF e ELSE IF São Falsos"<<std::endl;
	}
}

void CondicoesSwitch(){
	bool condicao1=true,condicao2=false; // Modifique aqui para true ou false
	std::cout<<"Condicoes Com Swicth(Escolha) Exemplo1"<<std::endl;
	switch(condicao1){
		case true:
			std::cout<<"A Condicao1 E Verdadeira, Entao Escolheu o Case true(Caso Verdadeiro)"<<std::endl;
		break;
		
		case false:
			std::cout<<"A Condicao1 E Falsa, Entao Escolheu o Case false(Caso Falso)"<<std::endl;
		break;	
	}
	std::cout<<"Condicoes Com Swicth(Escolha) Exemplo2"<<std::endl;
	switch(condicao2){
		case true:
			std::cout<<"A Condicao2 E Verdadeira, Entao Escolheu o Case true(Caso Verdadeiro)"<<std::endl;
		break;
		
		default:
			std::cout<<"A Condicao2 Nao E Verdadeira, Entao Escolheu o Default(Caso Contrario)"<<std::endl;
		break;
	}
}

void CondicoesTernario(){
	bool condicao = true; // Modifique aqui para true ou false
	std::string ResultadoCondicao;
	std::cout<<"Condicoes Com Operador Ternario"<<std::endl;
	ResultadoCondicao = (condicao) ? "(1)Exibiu_Isto_Porque_A_Condicao_E_Verdadeira":"(0)Exibiu_Isto_Porque_A_Condicao_E_Falsa" ;
	std::cout<<ResultadoCondicao<<std::endl;
}

int main(){
	CondicoesIf();
	CondicoesSwitch();
	CondicoesTernario();
	return 0;
}