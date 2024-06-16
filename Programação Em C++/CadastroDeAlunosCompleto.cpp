#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>

int main(){
	srand(time(nullptr));
	int QntsAlunos=0 , Idade=0, Turma=0 , Matricula=0;
	std::string ValorVt, Titulo="| Cadastro De Alunos |", Nome , Curso;
	
	std::cout<<"Quantos alunos quer cadastrar:";
	std::cin>>QntsAlunos;
	std::vector<std::string> Alunos(QntsAlunos);
	
	for(int i = 0 ; i < QntsAlunos ; i++){
		system("cls");
		ValorVt = "";
		Matricula = 0;
		std::cout<< Titulo <<std::endl;
		ValorVt+="Aluno ["+ std::to_string(i) +"]";
		std::cout<<"Digite o nome do aluno:";
		std::cin>>Nome;
		ValorVt+="| Nome do Aluno[" + Nome + "] |";
		Matricula = rand() % 100000;
		ValorVt+= "| Matricula["+ std::to_string(Matricula) + "] |";	
		do {
            std::cout << "Digite a turma do aluno: ";
            std::cin >> Turma;
            if (Turma <= 0) {
                std::cout << "Turma inválida. ";
                std::cin.clear(); 
            }
        } while (Turma <= 0);
        
		ValorVt+="| A turma do aluno[" + std::to_string(Turma) + "] |";
		std::cout << "Digite o curso do aluno: ";
        std::cin >> Curso;
        ValorVt+="| Curso Especializado[" + Curso + "] |";
        
		Alunos[i]=ValorVt;
	}
	system("cls");
	for(const std::string& Aluno : Alunos){
		std::cout<<Aluno<<std::endl;
	}
	
	return 0;
}