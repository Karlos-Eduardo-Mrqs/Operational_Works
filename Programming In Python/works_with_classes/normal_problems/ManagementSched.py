from dataclasses import dataclass

@dataclass
class Contatos:
    nome: str
    sobrenome: str
    email: str
    telefone: str

class ControleContatos:
    def __init__(self, arquivo: str):
        self.arquivo = arquivo

    def adicionar_contato(self, contato: Contatos):
        try:
            with open(self.arquivo, 'a') as file:
                file.write(f'{contato.nome},{contato.sobrenome},{contato.email},{contato.telefone}\n')
            print("Contato adicionado com sucesso!")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except OSError as oe:
            print(f"Erro ao acessar o arquivo: {oe}")

    def buscar_contato(self, email_busca: str) -> Contatos:
        try:
            with open(self.arquivo, 'r') as file:
                for linha in file:
                    partes = linha.strip().split(",")
                    if len(partes) == 4:  # Garante que a linha esteja bem formatada
                        nome, sobrenome, email, telefone = partes
                        if email == email_busca:
                            return Contatos(nome, sobrenome, email, telefone)
            print("Contato não encontrado!")
            return None
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao buscar contato: {e}")
            return None

    def remover_contato(self, email_busca: str):
        try:
            linhas = []
            encontrado = False
            with open(self.arquivo, 'r') as file:
                for linha in file:
                    partes = linha.strip().split(",")
                    if len(partes) == 4:  # Garante que a linha esteja bem formatada
                        _, _, email, _ = partes
                        if email == email_busca:
                            encontrado = True
                        else:
                            linhas.append(linha)

            if encontrado:
                with open(self.arquivo, 'w') as file:
                    file.writelines(linhas)
                print("Contato removido com sucesso!")
            else:
                print("Contato não encontrado!")
        except FileNotFoundError:
            print("Arquivo não encontrado!")
        except Exception as e:
            print(f"Erro ao remover contato: {e}")

def main():
    # Define o arquivo onde os contatos serão salvos
    agenda = ControleContatos("contatos.txt")

    # Cria alguns contatos
    contato1 = Contatos("Raphael", "Jesus", "JesusRaphael@gmail.com", "(21) 98564-5201")
    contato2 = Contatos("Kaio", "Jorge", "JorgeKaio@gmail.com", "(21) 23108-0245")

    # Adiciona os contatos à agenda
    agenda.adicionar_contato(contato1)
    agenda.adicionar_contato(contato2)

    # Busca um contato pelo email
    contato_encontrado = agenda.buscar_contato("JesusRaphael@gmail.com")
    print(contato_encontrado)

    # Remove um contato pelo email
    agenda.remover_contato("JorgeKaio@gmail.com")

if __name__ == "__main__":
    main()