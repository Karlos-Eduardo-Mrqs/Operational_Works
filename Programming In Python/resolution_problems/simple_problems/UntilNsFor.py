Quantidade = int(input('Quantos números você vai digitar ?:'));
maiornm=float('-inf');
menornm=float('inf');
for i in range(Quantidade):
    num = int(input(f"Digite o {i + 1}º numero "));
    if num > maiornm:
        maiornm = num ;
    if num < menornm:
        menornm = num ;
print(f"De todos os {i} números; o maior número é {maiornm} e o menor número é {menornm} !");