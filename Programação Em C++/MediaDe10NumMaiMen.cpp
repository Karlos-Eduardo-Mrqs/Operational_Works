#include <iostream>
int main(){
	int num=0 , cont = 1 , maiorNm=0 , menorNm=99999 , media=0;
	while(cont <= 10){ // While(cont != 11){ Dá na mesma,porém é mais válido usar (cont <= 10)}
		std::cout << "Digite o " << cont << " numero:" ;
		std::cin >> num;		
		media+=num;
		maiorNm= num > maiorNm? num : maiorNm;
		menorNm= num < menorNm? num : menorNm;
		cont++;
	}
	std::cout<<std::endl;
	media/=cont;
	std::cout << "O maior numero:"<< maiorNm << std::endl ;
	std::cout << "O menor numero:"<< menorNm << std::endl ;
	std::cout << "a media dos numeros:"<< media << std::endl ;
	return 0;
}