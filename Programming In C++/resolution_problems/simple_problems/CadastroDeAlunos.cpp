#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
	vector <string> Alunos;
	string nome , ValorVetor , resposta;
	
	char sexo, resp;
	
	int cont=0 , idade=0 , media=0 , nota=0;
	
	bool QrCadastrar = true;
	
	while (QrCadastrar){
		ValorVetor.clear();
		media=0;
		nota=0;
		
		ValorVetor+="|Aluno[" + to_string(cont+1) + "]";
		
		cout<<"Digite o Nome do Aluno:";
		cin>>nome;
		ValorVetor+="|Nome:" + nome;
		
		cout<<"Digite o sexo:";
		cin>>sexo;
		ValorVetor+="|Sexo:" + string(1,sexo);
		
		cout<<"Digite a idade:";
		cin>>idade;
		ValorVetor+="|Idade:" + to_string(idade);
		
		for(int i = 0 ; i < 2 ; i++ ){
			cout<<"Digite a ["<< i <<"] nota do "<< nome <<":";
			cin>>nota;
			media+=nota;	
		}
		
		media/=2; 
		ValorVetor+="|Media:" + to_string(media) + " |";
		
		Alunos.push_back(ValorVetor);
		cont++;
		system("cls");
			
		cout<<"Tem mais algum aluno para cadastrar (S/N):";
		cin>>resp;
		
		QrCadastrar = (resp == 'N' || resp == 'n') ? false:true ; 
			
	}
	
	system("cls");
	
	cout<<"Os Alunos Cadastrados ate aqui sao:"<<endl;
	for(const auto &Aluno : Alunos){
		cout << Aluno << endl;
	}
	
	return 0;
}