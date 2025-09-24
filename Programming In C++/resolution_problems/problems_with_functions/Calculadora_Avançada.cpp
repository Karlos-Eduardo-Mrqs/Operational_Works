#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept> 

void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int Precedencia(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0; // Operador inválido
}

int AvaliarExpressao(const std::string& expressao) {
    std::vector<int> numeros;
    std::vector<char> operadores;

    for (char valor : expressao) {
        if (isdigit(valor)) {
            int num = 0;
            while (isdigit(valor)) {
                num = num * 10 + (valor - '0');
                valor = expressao[++valor];
            }
            numeros.push_back(num);
        } else if (valor == '(') {
            operadores.push_back(valor);
        } else if (valor == ')') {
            while (!operadores.empty() && operadores.back() != '(') {
                char op = operadores.back();
                operadores.pop_back();
                int b = numeros.back();
                numeros.pop_back();
                int a = numeros.back();
                numeros.pop_back();
                switch (op) {
                    case '+':
                        numeros.push_back(a + b);
                        break;
                    case '-':
                        numeros.push_back(a - b);
                        break;
                    case '*':
                        numeros.push_back(a * b);
                        break;
                    case '/':
                        if (b == 0)
                            throw std::invalid_argument("Divisao por zero");
                        numeros.push_back(a / b);
                        break;
                }
            }
            operadores.pop_back(); // Remover o '(' correspondente
        } else {
            while (!operadores.empty() && Precedencia(operadores.back()) >= Precedencia(valor)) {
                char op = operadores.back();
                operadores.pop_back();
                int b = numeros.back();
                numeros.pop_back();
                int a = numeros.back();
                numeros.pop_back();
                switch (op) {
                    case '+':
                        numeros.push_back(a + b);
                        break;
                    case '-':
                        numeros.push_back(a - b);
                        break;
                    case '*':
                        numeros.push_back(a * b);
                        break;
                    case '/':
                        if (b == 0)
                            throw std::invalid_argument("Divisao por zero");
                        numeros.push_back(a / b);
                        break;
                }
            }
            operadores.push_back(valor);
        }
    }

    while (!operadores.empty()) {
        char op = operadores.back();
        operadores.pop_back();
        int b = numeros.back();
        numeros.pop_back();
        int a = numeros.back();
        numeros.pop_back();
        switch (op) {
            case '+':
                numeros.push_back(a + b);
                break;
            case '-':
                numeros.push_back(a - b);
                break;
            case '*':
                numeros.push_back(a * b);
                break;
            case '/':
                if (b == 0)
                    throw std::invalid_argument("Divisao por zero");
                numeros.push_back(a / b);
                break;
        }
    }

    return numeros.back();
}

void MostrarAMemoria(const std::vector<std::string>& Memoria) {
    if (Memoria.empty()) {
        std::cout << "Nenhuma operacao armazenada na memoria." << std::endl;
    } else {
        std::cout << "Operacoes armazenadas na memoria:" << std::endl;
        for (const auto& operacao : Memoria) {
            std::cout << operacao << std::endl;
        }
    }
}

void SalvarNaMemoria(std::vector<std::string>& Memoria, const std::string& Operacao, bool Ok) {
    if (Ok) {
        Memoria.push_back(Operacao);
    } else {
        LimparTela();
        MostrarAMemoria(Memoria);
    }
}

void DigiteOperacao(std::vector<std::string>& Memoria) {
    std::string Operacao;
    char sinal;

    do {
        std::cout << "Digite uma operacao matematica:";
        std::cin >> Operacao;
        try {
            int resultado = AvaliarExpressao(Operacao);
            std::string resultado_str = Operacao + "=" + std::to_string(resultado);
            std::cout << "Resultado: " << resultado << std::endl;
            std::cout << "Deseja Armazenar na memoria essa operacao [Sim - S ou s | Nao - N ou n]?:";
            std::cin >> sinal;
            bool situacao = (sinal == 'S' || sinal == 's');
            SalvarNaMemoria(Memoria, resultado_str, situacao);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
        std::cout << "Digite 'S' ou 's' para continuar, ou 'N' ou 'n' para sair: ";
        std::cin >> sinal;
        
    } while (sinal == 'S' || sinal == 's');
}

int main() {  
    std::vector<std::string> Memoria; 
    DigiteOperacao(Memoria);   
    return 0;
}