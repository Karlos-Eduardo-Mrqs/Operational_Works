from pathlib import Path
import json
from typing import List, Dict

class GerenciadorAlunos:
    def __init__(self, base_dir: Path):
        self.csv_path = base_dir / "alunos.csv"  # Arquivo CSV
        self.json_path = base_dir / "alunos.json"  # Arquivo JSON
        self.txt_path = base_dir / "alunos.txt"  # Arquivo TXT
        self.alunos: Dict[str, float] = self._carregar()  # Carrega os dados existentes

    def _carregar(self) -> Dict[str, float]:
        if self.csv_path.exists():
            try:
                with open(self.csv_path, 'r') as f:
                    return {
                        nome: float(nota)
                        for nome, nota in (linha.strip().split(',') for linha in f)
                    }
            except FileNotFoundError:
                print("Arquivo CSV não encontrado")
            except ValueError as ve:
                print(f"Erro ao converter a nota: {ve}")
            except OSError as oe:
                print(f"Erro ao acessar o arquivo: {oe}")
        return {}

    def salvar(self) -> None:
        try:
            with open(self.csv_path, 'w') as f_csv, \
                open(self.txt_path, 'w') as f_txt, \
                open(self.json_path, 'w') as f_json:

                for nome, nota in self.alunos.items():
                    linha = f'{nome},{nota:.1f}\n'# Escreve no arquivo CSV
                    f_csv.write(linha)
                    f_txt.write(f'{nome} tem nota {nota:.1f}\n')# Escreve no arquivo TXT

                # Salva no formato JSON
                json.dump(self.alunos, f_json, indent=4)

        except Exception as e:
            print(f"Erro ao salvar os arquivos: {e}")

    def cadastrar(self, aluno: 'Aluno') -> bool:
        self.alunos[aluno.nome] = aluno.nota
        self.salvar()
        return True

    def remover(self, nome: str) -> bool:
        if nome in self.alunos:
            del self.alunos[nome]
            self.salvar()
            return True
        return False

    def alterar_nota(self, nome: str, nova_nota: float) -> bool:
        if nome in self.alunos:
            self.alunos[nome] = nova_nota
            self.salvar()
            return True
        return False

    def listar(self) -> List[str]:
        return [f'{nome}, {nota:.1f}' for nome, nota in self.alunos.items()]

    def buscar(self, nome: str) -> str:
        if nome in self.alunos:
            return f'{nome}, {self.alunos[nome]:.1f}'
        return "Aluno não encontrado"

class Aluno:  # Representa um aluno com nome e nota
    def __init__(self, nome: str, nota: float):
        self.nome = nome.strip().title()  # Remove espaços extras e capitaliza o nome
        self.nota = float(nota)  # Converte a nota para float

    def to_dict(self) -> Dict[str, float]:
        return {self.nome: self.nota}

    def __str__(self) -> str:
        return f"{self.nome}, {self.nota:.1f}"

if __name__ == "__main__":
    # Cria o diretório base
    base_dir = Path("dados")
    base_dir.mkdir(exist_ok=True)
    gerenciador = GerenciadorAlunos(base_dir) # Instancia o gerenciador de alunos
    
    print("Cadastrando:", gerenciador.cadastrar(Aluno("Raphael", 8.5)))
    print("Lendo:", gerenciador.buscar("Raphael"))
    print("Lista:", gerenciador.listar())
    print("Removendo:", gerenciador.remover("Raphael"))
    print("Lista após a remoção:", gerenciador.listar())
    print("Novo Cadastro:", gerenciador.cadastrar(Aluno("Gabriel", 5.5)))
    print("Alterando nota:", gerenciador.alterar_nota("Gabriel", 10))
    print("Lista final:", gerenciador.listar())