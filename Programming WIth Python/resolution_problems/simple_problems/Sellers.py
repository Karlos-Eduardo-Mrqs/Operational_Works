import os # Importando o Sistema Operacional 
Sellers = []; # Lista Para Os Vendedores
HaveMoreSellers = True; # Nos temos vendedores para cadastrar !  
while(HaveMoreSellers): #Enquanto houver mais vendedores para o cadastro 
    print(os.system("cls")); #Função do Sistema Operacional Que Limpará Tela
    Media = 0; # Zera A média a cada loop passado
    SellerName = input("Digit The Name Of Seller:"); #Digite o nome do vendedor 
    for I in range(0,3): #Loop que digite três preços de venda e faz a soma da média
        Product = float(input(f"Digit The {I+1} º Price Sale you have today:")); # Digite o preço de vendo que você fez hoje
        Media += Product; # Media = Media + Produto
    Media/= I+1; #Faz a divisão da média
    Bonus = (Media / 10) * 100; # Bônus de 10% da média
    Sellers.append(f" The Seller {SellerName} Have in Media R${Media:.2f} in Your Sales And Have R${Bonus:.2f}"); # O vendedor Fulano fez em media Tantos R$ em suas vendas e teve X R$ de Bonus
    Condition = input("Have More Sellers For Register Today [Y-yes | N-no ]?:"); # Tem mais algum vendedor para se cadastrar hoje [S - sim ou N-não] ? 
    HaveMoreSellers = bool(Condition.upper() == "Y"); # Se a codição(condition) == 'Y', o loop continua, senão, ele saíra do loop 
print(os.system("cls"));# Limpará a tela
print(Sellers); # Mostrará na tela, todos os vendedores cadastrados, Dúvidas,Tretas ? Só chamar.