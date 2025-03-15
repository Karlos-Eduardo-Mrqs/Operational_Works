import random
from dataclasses import dataclass

@dataclass
class Products:
    id: int
    nome: str
    preco: float
    qtd_estoque: int
    total_vendido: int = 0

    def exibir_dados(self):#Exibe os detalhes do produto de forma formatada.
        print(f"ID: {self.id}, Nome: {self.nome}, Preço: R${self.preco:.2f}, "
              f"Estoque: {self.qtd_estoque}, Vendidos: {self.total_vendido}")

    def verificar_estoque(self): #Verifica se o estoque está abaixo do limite crítico (5 unidades).
        if self.qtd_estoque < 5:
            print(f"ALERTA: O produto '{self.nome}' (ID: {self.id}) está com estoque baixo ({self.qtd_estoque} unidades).")
        else:
            print(f"O produto '{self.nome}' (ID: {self.id}) tem estoque suficiente ({self.qtd_estoque} unidades).")

def createProduct(indice: int) -> Products: #Cria um novo produto com base nas entradas do usuário.Retorna um objeto da classe Products.
    print(f"Criando o produto {indice}")
    product_id = random.randint(100000, 999999)  # Gera um ID aleatório de 6 dígitos
    name_product = input("Qual é o nome?: ")
    price_product = float(input(f"Preço de {name_product}: "))
    qtd_product = int(input(f"Quantidade em estoque para {name_product}: "))
    total_sold = int(input(f"Quantas unidades de {name_product} foram vendidas?: "))
    return Products(
        id=product_id, nome=name_product, preco=price_product, qtd_estoque=qtd_product, total_vendido=total_sold
    )

def exibirProdutos(products_list: list): #Exibe os detalhes de todos os produtos na lista.Também verifica o estoque de cada produto.
    print("\n--- Detalhes dos Produtos ---")
    for product in products_list:
        product.exibir_dados()  # Chama o método de exibição de dados
        product.verificar_estoque()  # Chama o método de verificação de estoque
        print("-" * 40)

def main():#Função principal para criar e exibir produtos.
    qtd_produtos = int(input("Quantos produtos você deseja criar?: "))
    productsList = []  # Lista para armazenar os produtos criados

    for indice in range(qtd_produtos): # Loop para criar os produtos
        product = createProduct(indice)
        productsList.append(product)
    
    exibirProdutos(productsList) # Exibe os produtos criados
if __name__ == "__main__":# Executa o programa
    main()