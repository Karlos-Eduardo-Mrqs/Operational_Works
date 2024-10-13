QuantidadeValida = False;
while(not(QuantidadeValida)):
    Quantidade = int(input('Quantos números você vai digitar ?:'));
    QuantidadeValida = Quantidade > 0;
numeros = [];
for i in range(Quantidade):
    num = int(input(f"Digite o {i + 1}º numero "));
    if num <= 0:
        print("Você digitou o numero invalido !");
        break;
    numeros.append(num);
if numeros:
    maiornm = max(numeros);
    menornm = min(numeros);
    if maiornm == menornm:
        print("O maior e o menor número são iguais !");
    else:
        print(f"De todos os {len(numeros)} números; o maior número é {maiornm} e o menor número é {menornm} !");
print("Fim Programa !");