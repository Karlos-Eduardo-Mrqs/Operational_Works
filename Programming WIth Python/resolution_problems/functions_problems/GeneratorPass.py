import random
import string

def Inclusao(LetraMaiuscula, LetraMinuscula, Simbolos, Numeros, TamanhoDaSenha):
    if TamanhoDaSenha <= 7:
        print("Erro 404 (Tamanho inconsistente para uma senha!)")
        return None  
    
    caracteres = ""
    
    if LetraMaiuscula == 'S':
        caracteres += string.ascii_uppercase
    if LetraMinuscula == 'S':
        caracteres += string.ascii_lowercase
    if Simbolos == 'S':
        caracteres += string.punctuation
    if Numeros == 'S':
        caracteres += string.digits
    
    return caracteres

def GerarSenha(Caracteres, TamanhoDaSenha):
    if Caracteres:  
        return ''.join(random.choice(Caracteres) for _ in range(TamanhoDaSenha))
    else:
        return None  

def main():
    TamanhoDaSenha = int(input("Qual será o tamanho de caracteres da senha que você deseja? "))
    
    LetraMaiuscula = input("Incluir letras maiúsculas [S-sim|N-não]? ").upper()
    LetraMinuscula = input("Incluir letras minúsculas [S-sim|N-não]? ").upper()
    Simbolos = input("Incluir símbolos [S-sim|N-não]? ").upper()
    Numeros = input("Incluir números [S-sim|N-não]? ").upper()
    Caracteres = Inclusao(LetraMaiuscula, LetraMinuscula, Simbolos, Numeros, TamanhoDaSenha)
    
    if Caracteres:
        Senha = GerarSenha(Caracteres, TamanhoDaSenha)
        print("A senha gerada foi:", Senha)
    else:
        print("Não foi possível gerar a senha.")

main()