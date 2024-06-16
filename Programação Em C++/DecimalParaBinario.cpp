#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ConversaoBinaria(int numero){
	vector <int> Binario;
	
	if(numero==0){
		Binario.push_back(numero);	
		return Binario;
	}
		while(numero!=0){
			Binario.push_back(numero % 2);
			numero/=2;
		}
	reverse(Binario.begin(),Binario.end());	
	return Binario;
}

int main(){
	int num=0;
	cout<<"Digite um numero:";
	cin>>num;
	vector<int> binario = ConversaoBinaria(num);
	cout<<"O numero "<<num<<" em binario e:";
	for(int bits : binario){
		cout<<bits;
	}
	cout<<endl;
	return 0;
}