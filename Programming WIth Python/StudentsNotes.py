from dataclasses import dataclass
from typing import List

@dataclass
class Alunos:
    matricula: int
    nome: str
    turma: int
    notas: List[float]  # List of grades

    def media_individual(self) -> float:
        #Calcula a média individual dos estudantes 
        if self.notas:
            return sum(self.notas) / len(self.notas)
        else:
            return 0.0  

    def gerar_relatorio(self): # Cria um log(reporte) para o estudante, salvando ele como um arquivo txt chamado Aluno_<matricula>.txt
        media = self.media_individual()# Calcula a média, de acordo com a quantidade de notas 

        relatorio = (
            f"Relatório do Aluno:\n"
            f"Matrícula: {self.matricula}\n"
            f"Nome: {self.nome}\n"
            f"Turma: {self.turma}\n"
            f"Notas: {', '.join(map(str, self.notas)) if self.notas else 'Nenhuma nota registrada'}\n"
            f"Média: {media:.2f}\n"
        ) # Cria o conteúdo do relátorio

        nome_arquivo = f"Aluno_{self.matricula}.txt"

        try:# Criação do arquivo
            with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
                arquivo.write(relatorio)
            print(f"Relatório gerado com sucesso: {nome_arquivo}")
        except IOError as erro:
            print(f"Erro ao escrever o arquivo: {erro}")

if __name__ == "__main__":
    aluno1 = Alunos(matricula=202402290071,nome="José Silva",turma=1201,notas=[8.5,7.5,7.3,6.5,8.0,9.7])
    aluno1.gerar_relatorio()