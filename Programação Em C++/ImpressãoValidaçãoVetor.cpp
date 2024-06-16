#include <iostream>
#include <vector>

using namespace std;
int main(){
	vector<int> numeros (10);
	for(int i = 0 ; i < 10 ;i++){
		cout<<"Digite o"<< i <<" numero:";
		cin>>numeros[i];
	}
	
	cout<<"Os numeros digitados foram:"<<endl;
	for(int i = 0 ; i < 10 ; i++){
		cout<<numeros[i]<<";";
	}
	return 0;
}