#include <iostream>
#include <iomanip>
int main(){
	int num=0,i=1;
	double media=0;
	while(num >= 0){
		std::cout<<"Digite o "<<i<<" numero:";
		std::cin>>num;		
		if(num >=0){
			media+=num;	
			i++;
		}
	}
	if(i > 1){
		media/=i;
		std::cout<<"A media dos "<< i <<" numeros e :" << std::fixed << std::setprecision(2) << media <<std::endl;	
	}else{
		std::cout<<"Nenhum numero foi digitado"<<std::endl;	
	}
	return 0;
}