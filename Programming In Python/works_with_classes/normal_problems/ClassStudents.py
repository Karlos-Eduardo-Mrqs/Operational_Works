from dataclasses import dataclass # Importação do decorador `dataclass` do módulo `dataclasses`
@dataclass # Uso do decorador `@dataclass` para simplificar a criação da classe

class Aluno:
    # Declaração dos atributos da classe com seus respectivos tipos
    nome: str  
    idade: int  
    notas: list  
    media: float = 0.0 

    def MediaAluno(self): #Método para calcular a média das notas do aluno. Atualiza o atributo `media` com o valor calculado.
        if self.notas:# Verifica se a lista de notas não está vazia.
            self.media = sum(self.notas) / len(self.notas)
        else: # Se a lista de notas estiver vazia, define a média como 0.0
            self.media = 0.0

aluno1 = Aluno(nome="NOME_COMPLETO", idade=30, notas=[10.0, 8.5, 7.2, 6.0]) # Criação de uma instância da classe `Aluno`. Os valores fornecidos são: nome, idade e notas
aluno1.MediaAluno() # Chamada do método `MediaAluno` para calcular a média das notas do aluno. O método atualiza o atributo `media` da instância `aluno1`

print(f"Nome: {aluno1.nome}")  
print(f"Idade: {aluno1.idade}")  
print(f"Notas: {aluno1.notas}")  
print(f"Média: {aluno1.media:.2f}") 