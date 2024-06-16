#include <cstdio>
#include <string>
int main(){
	int num=0,fat=1;
	std::string msg;
	printf("Informe um numero:");
	scanf("%d",&num);
	if(num < 0){
		printf("Numero Invalido!");
		return 1;
	}else{
		msg+=std::to_string(num);
		msg+="!= ";
		for(int i =num; i>=1 ; i--){
			fat*=i;
			if(i >= 1){
				msg+=std::to_string(i);
				msg+="*";
			}
		}
		msg.replace(msg.length() - 1,1," =");
		msg+=std::to_string(fat);
	}
	printf("%s", msg.c_str()); 
	return 0;
}