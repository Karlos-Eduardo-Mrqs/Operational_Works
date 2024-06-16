#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

void Binario(int numero) {
    int resto;
    vector<char> Bits;

    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero != 0) {
        resto = numero % 2;
        Bits.push_back('0' + resto);
        numero /= 2;
    }

    reverse(Bits.begin(), Bits.end());
    return Bits;
}

void Octal(int numero) {
    int resto;
    vector<char> Bits;

    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero != 0) {
        resto = numero % 8;
        Bits.push_back('0' + resto);
        numero /= 8;
    }

    reverse(Bits.begin(), Bits.end());
    return Bits;
}

void Hexadecimal(int numero) {
    int resto;
    vector<char> Bits;

    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero > 0) {
        resto = numero % 16;
        if (resto <= 9) {
            Bits.push_back('0' + resto);
        } else {
            Bits.push_back('A' + resto - 10);
        }
        numero /= 16;
    }

    reverse(Bits.begin(), Bits.end());
    return Bits;
}

int main() {
    int num = 0, base = 0;
    int retorno = 0;
	string impress;
    vector<char> NumBinario;

    printf("Digite um numero:");
    scanf("%d", &num);

    do {
        retorno = 0 ; 
		system("cls");
        printf("Voce deseja converter o numero %d para a base: \n", num);
        printf("| Opcao [1] - Binaria \n");
        printf("| Opcao [2] - Octal \n");
        printf("| Opcao [3] - Hexadecimal \n");
        scanf("%d", &base);
        retorno = 0;
		switch (base) {
            case 1:
                impress = "Binaria";
                NumBinario = Binario(num);
                break;

            case 2:
                impress = "Octal";
                NumBinario = Octal(num);
                break;

            case 3:
                impress = "Hexadecimal";
                NumBinario = Hexadecimal(num);
                break;

            default:
                printf("Escolha Invalida!");
                retorno = 1;
                break;
        }

    } while (retorno == 1);

    system("cls");
    bool VetorVazio = NumBinario.empty();

    if (!VetorVazio) {
		printf("O numero %d para a base %s e: ", num, impress.c_str());
        for (char bits : NumBinario) {
            printf("%c", bits);
        }
    } else {
        printf("Algo Deu Errado");
    }

    return 0;
}