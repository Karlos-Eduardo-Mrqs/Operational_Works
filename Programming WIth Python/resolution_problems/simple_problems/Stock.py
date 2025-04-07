Quantidade = int(input("Quantos produtos você vai cadastrar?: "));
produtos = [];

for i in range(Quantidade):
    print(f"\nProduto {i + 1}:");
    codigo = int(input("Digite o código do produto: "));
    nome = input("Digite o nome do produto: ");
    preco = float(input("Digite o preço do produto: "));
    quantidade_vendida = int(input("Digite a quantidade vendida: "));
    preco_total = preco * quantidade_vendida;
    produtos.append((codigo, nome, preco, quantidade_vendida, preco_total));

print("\nRelatório de Vendas:");
for produto in produtos:
    codigo, nome, preco, quantidade_vendida, preco_total = produto;
    print(f"Código: {codigo}, Nome: {nome}, Preço: R${preco:.2f}, Quantidade Vendida: {quantidade_vendida}, Preço Total: R${preco_total:.2f}");