#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

vector<char> DecimalToBinary(int numero) {
    vector<char> Bits;
    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero > 0) {
        int digito = numero % 2;
        Bits.push_back('0' + digito);
        numero /= 2;
    }

    reverse(Bits.begin(), Bits.end());
    return Bits;
}

vector<char> DecimalToOctal(int numero) {
    vector<char> Bits;
    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero > 0) {
        int digito = numero % 8;
        Bits.push_back('0' + digito);
        numero /= 8;
    }

    reverse(Bits.begin(), Bits.end());
    return Bits;
}

vector<char> DecimalToHexadecimal(int numero) {
    vector<char> Bits;
    if (numero == 0) {
        Bits.push_back('0');
        return Bits;
    }

    while (numero > 0) {
        int resto = numero % 16;
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
    string impress;
    vector<char> NumBinario;

    printf("Digite um numero:");
    scanf("%d", &num);

    do {
        system("cls");
        printf("Voce deseja converter o numero %d para a base: \n", num);
        printf("| Opcao [1] - Binaria \n");
        printf("| Opcao [2] - Octal \n");
        printf("| Opcao [3] - Hexadecimal \n");
        scanf("%d", &base);

        switch (base) {
            case 1:
                impress = "Binaria";
                NumBinario = DecimalToBinary(num);
                break;

            case 2:
                impress = "Octal";
                NumBinario = DecimalToOctal(num);
                break;

            case 3:
                impress = "Hexadecimal";
                NumBinario = DecimalToHexadecimal(num);
                break;

            default:
                printf("Escolha Invalida!");
                break;
        }

    } while (base < 1 || base > 3);

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
