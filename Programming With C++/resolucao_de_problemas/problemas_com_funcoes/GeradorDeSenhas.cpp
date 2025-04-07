#include <cstdio>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

string CriarSenha(int tam, bool Lmin, bool Lmai, bool simb, bool num) {
    string Criterios, Senha;
    string LetraMin, LetraMai, Numeros, Simbolos;

    if (Lmin) {
        LetraMin = "abcdefghijklmnopqrstuvwxyz";
        Criterios += LetraMin;
    }

    if (Lmai) {
        LetraMai = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        Criterios += LetraMai;
    }

    if (num) {
        Numeros = "0123456789";
        Criterios += Numeros;
    }

    if (simb) {
        Simbolos = "!@#$%^&*()-_+=<>?";
        Criterios += Simbolos;
    }   

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, Criterios.size() - 1);

    for (int i = 0; i < tam; i++) {
        int random_index = dis(gen);
        Senha.push_back(Criterios[random_index]);
    }

    return Senha;
}

int main() {
    string Title = "| Gerador de Senha |";
    string SenhaCrt;
    vector<string> SenhasCriadas;
    char resp;
    int Size , Lmin , Lmai , simb , num , QtdSenhas;
    bool TudoCerto = false;

    while (!TudoCerto) {
        system("cls");
        printf("%s", Title.c_str());
        printf("Sua senha tem que ter os seguintes critérios: \n");

        printf("\nTamanho ?: ");
        scanf("%d", &Size);

        printf("\nLetra Minuscula [0 = N /1 = S] ?: ");
        scanf(" %d", &Lmin);
        Lmin = (Lmin == 1) ? true : false;

        printf("\nLetra Maiuscula [0 = N /1 = S] ?: ");
        scanf(" %d", &Lmai);
        Lmai = (Lmai == 1) ? true : false;

        printf("\nSimbolo [0 = N /1 = S] ?: ");
        scanf(" %d", &simb);
        simb = (simb == 1) ? true : false;

        printf("\nNúmero [0 = N /1 = S] ?: ");
        scanf(" %d", &num);
        num = (num == 1) ? true : false;

        printf("\nTudo certo para criar essa senha, tem todos os criterios [S/N] ?: ");
        scanf(" %c", &resp);
        getchar();

        if (resp == 'S' || resp=='s') {
            system("cls");
            SenhaCrt = CriarSenha(Size, Lmin, Lmai, simb, num);
            printf("\nA senha sera %s\n :", SenhaCrt.c_str());
            SenhasCriadas.push_back(SenhaCrt);
            printf("Deseja criar outra senha [S/N] ?: ");
            scanf(" %c", &resp);
            getchar();
            TudoCerto = (resp == 'S') ? false : true;
        } else {
            continue;
        }
    }
    
    QtdSenhas=SenhasCriadas.size();
    system("cls");
    
    printf("\nTodas as %d senhas criadas sao: \n",QtdSenhas);
    for (const auto &senha : SenhasCriadas) {
        printf("%s\n", senha.c_str());
    }   
    return 0;
}