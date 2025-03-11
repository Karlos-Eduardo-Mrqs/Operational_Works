# Importação do decorador `dataclass` do módulo `dataclasses`
from dataclasses import dataclass

# Uso do decorador `@dataclass` para simplificar a criação da classe
@dataclass
class Aluno:
    # Declaração dos atributos da classe com seus respectivos tipos
    nome: str  # Nome do aluno (string)
    idade: int  # Idade do aluno (inteiro)
    notas: list  # Lista de notas do aluno (lista de floats)
    media: float = 0.0  # Média das notas, inicializada com valor padrão 0.0

    def MediaAluno(self):
        """Método para calcular a média das notas do aluno. Atualiza o atributo `media` com o valor calculado."""
        # Verifica se a lista de notas não está vazia
        if self.notas:
            # Calcula a média somando todas as notas e dividindo pelo número de notas
            self.media = sum(self.notas) / len(self.notas)
        else:
            # Se a lista de notas estiver vazia, define a média como 0.0
            self.media = 0.0


# Criação de uma instância da classe `Aluno`
# Os valores fornecidos são: nome, idade e notas
aluno1 = Aluno(
    nome="NOME_COMPLETO",  # Nome do aluno
    idade=30,  # Idade do aluno
    notas=[10.0, 8.5, 7.2, 6.0]  # Lista de notas do aluno
)

# Chamada do método `MediaAluno` para calcular a média das notas do aluno
# O método atualiza o atributo `media` da instância `aluno1`
aluno1.MediaAluno()

# Exibição dos dados do aluno usando f-strings para formatar a saída
print(f"Nome: {aluno1.nome}")  # Imprime o nome do aluno
print(f"Idade: {aluno1.idade}")  # Imprime a idade do aluno
print(f"Notas: {aluno1.notas}")  # Imprime a lista de notas do aluno
print(f"Média: {aluno1.media:.2f}")  # Imprime a média do aluno, formatada com duas casas decimais