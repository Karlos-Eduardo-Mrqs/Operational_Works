# functions.py
from main import * 
from dataclasses import dataclass
import datetime,random

@dataclass
class FuncoesAgenda:
    def __init__(self, arquivo: str) -> None: # Inicializa a classe FuncoesAgenda com o nome do arquivo onde os alunos serão armazenados.:param arquivo: Nome do arquivo para armazenar os alunos.
        self.arquivo = arquivo

    def cadastrar_aluno(self)->None: # Cadastra um novo aluno e salva no arquivo.
        try:
            # Coleta os dados do aluno
            nome = input("Digite o nome do aluno: ")
            turma = int(input("Digite o número da turma: "))
            notas = []
            while True:
                nota = input("Digite uma nota (ou 's' para sair): ")
                if nota.lower() == 's':
                    break
                try:
                    notas.append(float(nota))
                except ValueError:
                    print("Nota inválida! Digite um número ou 's' para sair.")

            # Gera a matrícula usando o ano atual e um número aleatório
            ano_atual = datetime.datetime.now().year
            num_aleatorio = random.randint(1000, 9999)  # Gera um número aleatório de 4 dígitos
            matricula = f"{ano_atual}{num_aleatorio}"

            aluno = Alunos(nome=nome.strip(), matricula=matricula, turma=turma, notas=notas)# Cria o objeto Aluno

            with open(self.arquivo, 'a') as file: # Salva o aluno no arquivo
                file.write(f"{aluno.nome},{aluno.matricula},{aluno.turma},{','.join(map(str, aluno.notas))}\n")
            print("Aluno cadastrado com sucesso!")
        except Exception as e:
            print(f"Erro ao cadastrar aluno: {e}")

    def listar_alunos(self)->None: # Lista todos os alunos armazenados no arquivo.
        try:
            with open(self.arquivo, 'r') as file:
                alunos = file.readlines()
                if not alunos:
                    print("Nenhum aluno cadastrado.")
                    return
                print("Lista de Alunos:")
                for aluno in alunos:
                    partes = aluno.strip().split(",")
                    nome, matricula, turma, *notas = partes
                    print(f"Nome: {nome}, Matrícula: {matricula}, Turma: {turma}, Notas: {notas}")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao listar alunos: {e}")

    def buscar_aluno(self)->None: # Busca um aluno pelo nome.
        try:
            nome_busca = input("Digite o nome do aluno a ser buscado: ")
            with open(self.arquivo, 'r') as file:
                for linha in file:
                    partes = linha.strip().split(",")
                    nome, matricula, turma, *notas = partes
                    if nome.lower() == nome_busca.lower():
                        print(f"Aluno encontrado: Nome: {nome}, Matrícula: {matricula}, Turma: {turma}, Notas: {notas}")
                        return
                print("Aluno não encontrado.")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao buscar aluno: {e}")

    def remover_aluno(self)->None: # Remove um aluno pelo nome.
        try:
            nome_busca = input("Digite o nome do aluno a ser removido: ")
            linhas = []
            encontrado = False
            with open(self.arquivo, 'r') as file:
                for linha in file:
                    partes = linha.strip().split(",")
                    nome, _, _, _ = partes
                    if nome.lower() == nome_busca.lower():
                        encontrado = True
                    else:
                        linhas.append(linha)
            if encontrado:
                with open(self.arquivo, 'w') as file:
                    file.writelines(linhas)
                print("Aluno removido com sucesso!")
            else:
                print("Aluno não encontrado.")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao remover aluno: {e}")

    def alterar_aluno(self)->None: # Altera os dados de um aluno existente.
        try:
            nome_busca = input("Digite o nome do aluno a ser alterado: ")
            linhas = []
            encontrado = False
            with open(self.arquivo, 'r') as file:
                for linha in file:
                    partes = linha.strip().split(",")
                    nome, matricula, turma, *notas = partes
                    if nome.lower() == nome_busca.lower():
                        encontrado = True
                        print("Aluno encontrado. Insira os novos dados:")
                        novo_nome = input("Digite o novo nome: ")
                        nova_turma = int(input("Digite a nova turma: "))
                        novas_notas = []
                        while True:
                            nota = input("Digite uma nova nota (ou 's' para sair): ")
                            if nota.lower() == 's':
                                break
                            try:
                                novas_notas.append(float(nota))
                            except ValueError:
                                print("Nota inválida! Digite um número ou 's' para sair.")
                        linhas.append(f"{novo_nome},{matricula},{nova_turma},{','.join(map(str, novas_notas))}\n")
                    else:
                        linhas.append(linha)
            if encontrado:
                with open(self.arquivo, 'w') as file:
                    file.writelines(linhas)
                print("Aluno alterado com sucesso!")
            else:
                print("Aluno não encontrado.")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao alterar aluno: {e}")

    def sair(self):# Encerra o programa.
        print("Saindo do sistema...")
        exit()