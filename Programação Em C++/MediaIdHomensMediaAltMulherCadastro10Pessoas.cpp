#include <iostream>
#include <stdlib.h>
#include <string>

int main(){
	std::string Titulo = "| Cadastro Populacional Regional |" ;
	int QtdRegiao = 0,cont = 0 , contHomen=0 , contMulher=0 ,idade = 0 , sexo = 0 ;
	int mediaGrp = 0 , mediaAdJv=0 , mediaIdHomen = 0  ; 
	float altura = 0 , mediaAltMulher = 0  ;
	
		
	std::cout<<"Quantas pessoas tem na sua regiao ?:";
	std::cin>>QtdRegiao; 
	if(QtdRegiao < 0){
		std::cout<<"Quantidade Invalida !";
		return 1;
	}	
	
	do{
		std::cout<< Titulo <<std::endl;
		
		std::cout<<"Qual e a sua idade ?:";
		std::cin>>idade; 
		mediaGrp+=idade; 
		mediaAdJv= (idade >= 18 && idade < 35) ? +idade : mediaAdJv ; 
		
		std::cout<<"Qual e a sua altura ?:";
		std::cin>>altura; 
		
		std::cout<<"Qual e seu sexo (Masculino -1 | Feminino - 0)?:";
		std::cin>>sexo; 
		
		switch(sexo){
			case 1:
				contHomen++; 
				mediaIdHomen+=idade; 
			break;
			
			case 0:
				contMulher++;
				mediaAltMulher+=altura;
			break;
			
			default:
				std::cout<<"Opcao invalida"<<std::endl;
				continue;
			break;
		}
		cont++;
	}while(cont <= QtdRegiao);
	
	std::cout<< "Resultado da Pesquisa " <<std::endl;
	
		if(contHomen > 0){
			mediaIdHomen/=contHomen;
			std::cout<< "No total temos " << contHomen  << " Homens" <<std::endl;
			std::cout<< "A media de idade:" << mediaIdHomen <<std::endl;
		}else{
			std::cout<< "Nenhum Homen Foi Cadastrado !" <<std::endl;
		}
		
		if(contMulher > 0){
			mediaAltMulher/=contMulher;
			std::cout<< "No total temos " << contMulher  << " Mulheres" <<std::endl;
			std::cout<< "A media de alutura:" << mediaAltMulher <<std::endl;
		}else{
			std::cout<< "Nenhuma Mulher Foi Cadastrada !" <<std::endl;
		}
		
		if(mediaAdJv > 0){
			mediaAdJv = (mediaAdJv * 100)/cont ;
			std::cout<< "A porcentagem de pesssoas com idade entre 18 a 35:" << mediaAdJv <<std::endl;
		}else{
			std::cout<< "Todos os Cadastrados estao abaixo 18 ou acima 35 " <<std::endl;
		}
	
	return 0;
}