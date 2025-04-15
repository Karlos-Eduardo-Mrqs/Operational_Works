from currency_converter import CurrencyConverter

# Criar um objeto para acessar as taxas de câmbio
c = CurrencyConverter()

# Solicitar a quantidade de dólares ao usuário
quantidade_dolares = float(input("Digite a quantidade de dólares guardados no cofre: "))

# Obter a cotação do dólar em reais
cotacao_dolar = c.convert(1, 'USD', 'BRL')  # Taxa de conversão de USD para BRL

# Calcular o valor em reais
valor_reais = quantidade_dolares * cotacao_dolar

# Exibir o resultado
print(f"Cotação do dólar hoje: R$ {cotacao_dolar:.2f}")
print(f"O turista possui R$ {valor_reais:.2f} no cofre do hotel.")