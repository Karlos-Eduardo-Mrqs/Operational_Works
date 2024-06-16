#include <iostream>

int main(){
	int num=0, mai=0 ,mei=0 , men=9999;
	for(int i =1;i<=3;i++){
		std::cout<<"Digite o ["<<i<<"] numero:";
		std::cin>>num;
		if(num > mai){
			mei=mai;
			mai=num;
		}if(num < men){
			mei=men;
			men=num;
		}if(num > men && num < mai){
			mei=num;
		}
	}
	std::cout<<"Ordem Crescente  |"<<"menor:"<<men<<"|meio:"<<mei <<"|maior:"<<mai<<"|"<<std::endl;
	std::cout<<"Ordem Decrescente|"<<"maior:"<<mai<<"|meio:"<<mei <<"|menor:"<<men<<"|"<<std::endl;
	return 0;
}