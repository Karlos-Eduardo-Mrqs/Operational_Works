QuantidadeValida = False;
while(not(QuantidadeValida)):
    Quantidade = int(input('Quantos números você vai digitar ?:'));
    QuantidadeValida = bool(Quantidade > 0);
numeros = [];
for i in range(Quantidade):
    num = int(input(f"Digite o {i + 1}º numero "));
    if num <= 0:
        print("Você digitou o numero invalido !");
        break;
    numeros.append(num);
if numeros:
    print(f"De todos os {len(numeros)} números; o maior número é {max(numeros)} e o menor número é {min(numeros)} !");

print("Fim Programa !");