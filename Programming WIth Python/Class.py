import random 
class Conta:
    def __init__(self,numero,cpf,nomeTitular,saldo):
        self.numero = numero;
        self.cpf = cpf;
        self.nomeTitular = nomeTitular;
        self.saldo = saldo;

numero = "";
for num in range(5):
    numero += str(random.randint(1,5));
    print(numero);

cpf = input("Digite seu cpf [111.111.111-11]:");
nomeTitular = input("Digite seu nome titular :");
saldo = float(input("Digite seu saldo :"));
Conta1 = Conta(numero,cpf,nomeTitular,saldo);
print(f"Cpf : {Conta1.cpf}");
print(f"nomeTitular : {Conta1.nomeTitular}");
print(f"saldo : {Conta1.saldo}");