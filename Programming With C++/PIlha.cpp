#include <iostream> // Para usar std::cout e std::cin
#include <string>   // Para usar std::string
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

// Definição da estrutura 'personagem'
struct personagem {
    int codigo;           // Código de criação
    std::string nome;     // Nome do personagem
    std::string elemento; // Elemento que ele domina
    std::string nacao;    // Nação/País onde ele nasceu
    int nivelDominio;     // Nível de domínio (0 - 100)
};

// Função para exibir os dados de um personagem
void ExibirPersona(const personagem& Persona) { // Corrigido o tipo do parâmetro
    std::cout << "=== Dados do Personagem ===" << std::endl;
    std::cout << "Nome: " << Persona.nome << std::endl;
    std::cout << "Nacao: " << Persona.nacao << std::endl;
    std::cout << "Elemento Principal: " << Persona.elemento << std::endl; // Corrigido o nome do atributo
    std::cout << "Nivel de Dominio: " << Persona.nivelDominio << std::endl; // Corrigido o nome do atributo
    std::cout << "Codigo de Criacao: " << Persona.codigo << std::endl;
}

int main() {
    // Inicializa a semente para gerar números aleatórios
    std::srand(static_cast<unsigned>(std::time(0)));

    // Declaração do personagem
    personagem Persona;

    // Entrada de dados
    std::cout << "Digite o nome do personagem: ";
    std::getline(std::cin, Persona.nome); // Usando getline para permitir espaços

    std::cout << "Digite a nacao onde ele nasceu: ";
    std::getline(std::cin, Persona.nacao);

    std::cout << "Digite o elemento predominante do personagem: ";
    std::getline(std::cin, Persona.elemento);

    std::cout << "Digite o nivel de dominio do elemento do personagem (0-100): ";
    std::cin >> Persona.nivelDominio;

    // Gera um código aleatório entre 1 e 100
    Persona.codigo = std::rand() % 100 + 1;

    // Exibe os dados do personagem
    ExibirPersona(Persona);

    return 0;
}