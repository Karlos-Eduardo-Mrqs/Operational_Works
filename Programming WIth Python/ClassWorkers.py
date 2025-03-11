from dataclasses import dataclass
@dataclass
class Trabalhador: #
    nome:str;
    cargo:str;
    salario:float;
    bonus:float;

    def calcularSalarioTotal(self): #calcula o salário total do funcionário (salário + bônus) e retorna o valor.
        return self.salario + self.bonus;

funcionario1 = Trabalhador(nome="Julio Cesar",cargo="Programador",salario=3500,bonus=500);
funcionario1.calcularSalarioTotal();
print(f"O funcionario {funcionario1.nome} é um ${funcionario1.cargo} com um salario de R${funcionario1.calcularSalarioTotal():.2f}");