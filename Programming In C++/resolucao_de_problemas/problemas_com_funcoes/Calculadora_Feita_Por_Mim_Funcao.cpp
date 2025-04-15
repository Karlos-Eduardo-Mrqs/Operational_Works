#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits> 
#include <stdlib.h>

//Aviso, Os comentários foram escritos pelo autor(Carlos Eduardo) para autoexplicação, não foi o CHAT que escreveu não. Safadas !
void LimparTela() {
	//Com está função, você podera limpar a tela.Idependente do SO(Sistema Operacional)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool VerificandoNumeros(int& num1, int& num2) {
    bool num1_Ok = false;
    bool num2_Ok = false;

    do {
        std::cout << "Digite o primeiro numero: ";
        if (!(std::cin >> num1)) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer(entrada de dados), caso esteja digitando algo errado
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
        } else {
            num1_Ok = true;
        }
    } while (!num1_Ok);

    do {
        std::cout << "Digite o segundo numero: ";
        if (!(std::cin >> num2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer(entrada de dados), caso esteja digitando algo errado
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
        } else {
            num2_Ok = true;
        }
    } while (!num2_Ok);

    return true;
}

bool VerificandoSimbolo(char& simbolo) {
    bool simbolo_Ok = false;
    std::vector<char> SimbolosValidos = {'+', '-', '*', 'X', '/','^'};
	//Essa função verifica se o usuário digitou o simbolo correto para fazer a operação 
    do {
        std::cout << "[ + ] SOMA | [ - ] Subtração | [ * | X ] Multiplicação | [ / ] Divisão | [ ^ ] Exponenciacao" << std::endl;
        std::cin >> simbolo;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Verifica se houve falha na entrada de dados, caso esteja digitando algo errado
            std::cout << "Entrada inválida. Por favor, digite um operador válido." << std::endl;
        } else {
            for (char VrSimb : SimbolosValidos) {
                if (VrSimb == simbolo) {
                    simbolo_Ok = true;
                    break;
                }
            }
        }
    } while (!simbolo_Ok);

    return simbolo_Ok;
}

std::string Calculo(int num1, int num2, char simbolo) {
    int calc;
    std::string resultado;
    resultado = std::to_string(num1) + simbolo + std::to_string(num2);
	// Essa função vai efetuar o calculo pedido pelo usuário, e transformará a Operação em String.Ex: num1=4,num2=6,simbolo=X; Operação = 4 X 6 = 24;
    switch(simbolo) {
        case '+':
            calc = num1 + num2;
        break;
        
		case '-': 
            calc = num1 - num2;
        break;
        
		case '*': 
        case 'X': 
            calc = num1 * num2;
        break;
        
		case '/': 
            if (num2 != 0) {
                calc = num1 / num2;
            } else {
                return "Erro: divisão por zero!";
            }
        break;
        
		case '^': 
        	calc = 1;
			for(int vezes = 0 ; vezes < num2 ; vezes++){
        		calc*=num1;
			}
        break;
		
		default:
            return "Erro: operador inválido!";
    }
	
    resultado += "=" + std::to_string(calc);
    return resultado;
}

void MemoriaCalc(std::string Operacao, char situacao, std::vector<std::string>& CalculosOp) {
    // Essa função armazena todos os cálculos feitos pelo usuário.Exibindo todos eles, caso o usuário não queira continuar,senão, ele será armazenado em um vetor.
	if(situacao == 'S' || situacao == 's') {
        CalculosOp.push_back(Operacao);
    } else {
        LimparTela();
		std::cout<<"| Todos os Calculos Armazenados : |"<<std::endl;
		for(const auto& operacao : CalculosOp) {
            std::cout << operacao << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> CalculosOp;
    int num1 = 0, num2 = 0;
    std::string Operacao;
    char simb, quer;
    bool quardar = true;
    
    while(quardar) {
        LimparTela();
		if (VerificandoNumeros(num1, num2) && VerificandoSimbolo(simb)) {
            Operacao = Calculo(num1, num2, simb);
            
            std::cout << "Deseja armazenar na memoria [Sim - S ou s | Nao - N ou n]";
            std::cin >> quer;
            if(quer == 'S' || quer == 's') {
                MemoriaCalc(Operacao, quer, CalculosOp);
            }

            std::cout << "Deseja continuar [Sim - S ou s | Nao - N ou n]? ";
            std::cin >> quer;
            quardar = (quer == 'S' || quer == 's') ? true : false;
            if(quer == 'N' || quer == 'N'){
            	MemoriaCalc("",quer,CalculosOp);
			}
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, insira números e um operador válidos." << std::endl;
        }
    }
    
    return 0;
}
