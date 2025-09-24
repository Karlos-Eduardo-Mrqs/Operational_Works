#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
int main(){
	vector<string> AlunosApr;
	string nome,aluno;
	char resp;
	float nota=0 , media=0, MediaInd=6;
	bool CadastraAlun=false;
	int i=0, cont=0;
	
	while(!CadastraAlun){
		system("cls");
		aluno="";
		media = 0;
		nota = 0;	
		cout<<"Digite o nome do aluno:";
		cin>>nome;
		for(i = 0 ; i < 2 ; i++){
			cout<<"Digite a "<< i << " nota:";
			cin>>nota;
			media+=nota; 
		}
		media/=2;
		if(MediaInd >= media){
			aluno+=nome+"media:"+to_string(media);
			AlunosApr.push_back(aluno);
		}	
		cont +=1;
		cout<<"Deseja cadastrar outro aluno [S - sim |N - nao] ?:";
		cin>>resp;
		CadastraAlun = resp == 'S' ? false : true ;
	}
	
	system("cls");
	cout<<"De todos os "<<cont<<" alunos, os aprovados foram:"<<endl;
	int QtdAlunos= AlunosApr.size() ;
	for(int i = 0 ; i< QtdAlunos; i++){
		cout<<AlunosApr[i]<<endl;
	}
	return 0;
}