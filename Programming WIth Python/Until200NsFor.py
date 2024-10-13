maiornm=float('-inf');
menornm=float('inf');
for i in range (200) :
    num = int(input(f"Digite o {i + 1}º numero "));
    if num > maiornm:
        maiornm = num ;
    if num <= menornm:
        menornm = num ;

print(f"O maior numero: {maiornm} | O menor numero: {menornm}");
