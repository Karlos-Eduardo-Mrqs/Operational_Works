from dataclasses import dataclass

@dataclass

class Trabalhador:
    nome: str  # Nome do trabalhador
    cargo: str  # Cargo do trabalhador
    salario: float  # Salário base do trabalhador
    bonus: float  # Bônus anual do trabalhador

    def calcularSalarioTotal(self): # Calcula o salário total do funcionário (salário + bônus) e retorna o valor.
        return self.salario + self.bonus
    
funcionario1 = Trabalhador(nome="Julio Cesar", cargo="Programador", salario=3500, bonus=500) # Criação de uma instância da classe Trabalhador
print(f"O funcionário {funcionario1.nome} é um {funcionario1.cargo} com um salário de R${funcionario1.calcularSalarioTotal():.2f}") # Exibição dos dados do funcionário usando f-strings