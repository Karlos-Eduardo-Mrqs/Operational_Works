#include <iostream>  // Inclui std::cout e std::cin
#include <algorithm> // Inclui std::max_element
#include <vector>    // Inclui std::vector
#include <limits>    // Inclui std::numeric_limits

bool numeroValido(int num) {// Função para validar se o número é válido (exemplo: número positivo)
    return num >= 0; 
}

int digitarQuantidadeNumeros() {// Função para permitir que o usuário escolha a quantidade de números
    int quantidade;
    while (true) { // Loop até que uma entrada válida seja fornecida
        std::cout << "Quantos numeros voce deseja digitar? ";
        std::cin >> quantidade;
        if (std::cin.fail()) { // Se a entrada não for um número
            std::cin.clear(); // Limpa o estado de erro de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
            std::cout << "Erro: Entrada invalida. Digite um numero positivo."<<std::endl;
        } else if (!numeroValido(quantidade)) {
            std::cout << "Erro: A quantidade deve ser positiva. Tente novamente."<<std::endl;
        } else {
            break; // Sai do loop se a entrada for válida
        }
    }
    return quantidade; // Retorna a quantidade válida
}

void digitarNumeros(std::vector<int>& numeros, int quantidade) { // Função para permitir que o usuário digite números válidos
    int num;
    std::cout << "Digite " << quantidade << " numeros positivos:"<<std::endl;
    for (int i = 0; i < quantidade;) { // Loop até que a quantidade de números válidos seja inserida
        std::cout << "Digite o " << i + 1 << "º numero: ";
        std::cin >> num;
        if (std::cin.fail()) { // Verifica se a entrada é válida(se não for um número)
            std::cin.clear(); // Limpa o estado de erro de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
            std::cout << "Erro: Entrada invalida. Digite um numero positivo."<<std::endl;
        } else if (numeroValido(num)) {
            numeros.push_back(num); // Adiciona o número ao vetor se for válido
            i++; // Incrementa apenas se o número for válido
        } else {
            std::cout << "Erro: O número deve ser positivo. Tente novamente."<<std::endl;
        }
    }
}

int maiorEntreNumeros(const std::vector<int>& numeros) {// Função para encontrar o maior número em um vetor
    if (numeros.empty()) {
        std::cerr << "Erro: Nenhum numero foi digitado."<<std::endl;
        return -1; // Retorna -1 como valor de erro
    }
    return *std::max_element(numeros.begin(), numeros.end());
}

int main() {
    std::vector<int> numeros; // Vetor para armazenar os números digitados
    int quantidade = digitarQuantidadeNumeros();// Solicita ao usuário a quantidade de números
    digitarNumeros(numeros, quantidade);// Solicita ao usuário que digite os números
    int resultado = maiorEntreNumeros(numeros); // Calcula o maior número usando a função maiorEntreNumeros
    if (resultado != -1) { // Verifica se há números válidos
        std::cout << "Maior: " << resultado << std::endl;
    }
    return 0;
}