from forex_python.converter import CurrencyRates

# Criar um objeto para acessar as taxas de câmbio
c = CurrencyRates()

# Solicitar a quantidade de dólares ao usuário
quantidade_dolares = float(input("Digite a quantidade de dólares guardados no cofre: "))

# Obter a cotação do dólar em reais automaticamente
cotacao_dolar = c.get_rate('USD', 'BRL')  # Taxa de conversão de USD para BRL

# Calcular o valor em reais
valor_reais = quantidade_dolares * cotacao_dolar

# Exibir o resultado
print(f"Cotação do dólar hoje: R$ {cotacao_dolar:.2f}")
print(f"O turista possui R$ {valor_reais:.2f} no cofre do hotel.")