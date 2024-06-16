#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits> // Para usar std::numeric_limits
#include <stdlib.h>

void LimparTela() {
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
        } else {
            num1_Ok = true;
        }
    } while (!num1_Ok);

    do {
        std::cout << "Digite o segundo numero: ";
        if (!(std::cin >> num2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, digite um número válido." << std::endl;
        } else {
            num2_Ok = true;
        }
    } while (!num2_Ok);

    return true;
}

bool VerificandoSimbolo(char& simbolo) {
    bool simbolo_Ok = false;
    std::vector<char> SimbolosValidos = {'+', '-', '*', 'X', '/'};

    do {
        std::cout << "[ + ] SOMA | [ - ] Subtração | [ * | X ] Multiplicação | [ / ] Divisão" << std::endl;
        std::cin >> simbolo;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, digite um operador válido." << std::endl;
        } else {
            for (char VrSimb : SimbolosValidos) {
                if (VrSimb == simbolo) {
                    simbolo_Ok = true;
                    break;
                }
            }
            
			if (!simbolo_Ok) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Operador inválido. Por favor, selecione um operador válido." << std::endl;
            }
        }
    } while (!simbolo_Ok);

    return simbolo_Ok;
}

std::string Calculo(int num1, int num2, char simbolo) {
    int calc;
    std::string resultado;

    switch(simbolo) {
        case '+':
            calc = num1 + num2;
            resultado = std::to_string(num1) + " + " + std::to_string(num2);
            break;
        case '-': 
            calc = num1 - num2;
            resultado = std::to_string(num1) + " - " + std::to_string(num2);
            break;
        case '*': 
        case 'X': 
            calc = num1 * num2;
            resultado = std::to_string(num1) + " * " + std::to_string(num2);
            break;
        case '/': 
            if (num2 != 0) {
                calc = num1 / num2;
                resultado = std::to_string(num1) + " / " + std::to_string(num2);
            } else {
                return "Erro: divisão por zero!";
            }
            break;
        default:
            return "Erro: operador inválido!";
    }

    resultado += " = " + std::to_string(calc);
    return resultado;
}

void MemoriaCalc(std::string Operacao, char situacao, std::vector<std::string>& CalculosOp) {
    if(situacao == 'S' || situacao == 's') {
        CalculosOp.push_back(Operacao);
    } else {
        LimparTela();
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
            
            std::cout << "Deseja armazenar na memoria [Sim - S | Nao - N]";
            std::cin >> quer;
            if(quer == 'S' || quer == 's') {
                MemoriaCalc(Operacao, quer, CalculosOp);
            }

            std::cout << "Deseja continuar [Sim - S | Nao - N]? ";
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

