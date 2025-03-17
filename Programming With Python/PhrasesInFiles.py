import os

class Frases:
    def __init__(self):# Inicializa a lista de frases.
        self.frases_usuario = []

    def adicionar_frase(self, frase: str) -> None: # Adiciona uma frase à lista de frases.Ignora entradas vazias.
        if frase.strip():  # Ignora entradas em branco
            self.frases_usuario.append(frase)

    def salvar_arquivo(self, nome_arquivo: str) -> None: # Salva as frases em um arquivo, uma por linha.Exibe o tamanho do arquivo após salvar.
        try:
            with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
                for frase in self.frases_usuario:
                    arquivo.write(frase + "\n")
            print(f"As frases foram salvas no arquivo '{nome_arquivo}'.")
        except IOError:
            print(f"Erro: Ocorreu um problema ao salvar o arquivo '{nome_arquivo}'.")

    def imprimir_frases(self, nome_arquivo: str) -> None: # Lê as frases do arquivo, converte para maiúsculas e imprime na tela.Trata possíveis erros, como arquivo não encontrado ou problemas de leitura.
        print("\n--- Frases Modificadas ---")
        try:
            with open(nome_arquivo, "r", encoding="utf-8") as arquivo:
                for linha in arquivo:
                    frase_modificada = linha.strip().upper()  # Converte para maiúsculas
                    print(frase_modificada)
        except FileNotFoundError:
            print(f"Erro: O arquivo '{nome_arquivo}' não foi encontrado.")
        except IOError:
            print(f"Erro: Ocorreu um problema ao ler o arquivo '{nome_arquivo}'.")
        except Exception as e:
            print(f"Erro inesperado: {e}")

    @staticmethod
    def entrada_valida(entrada: str) -> bool: # Verifica se a entrada é válida (não é 'sair').
        return entrada.lower() != "sair"

    @staticmethod
    def tamanho_arquivo(nome_arquivo: str) -> int:# Retorna o tamanho do arquivo em bytes.Se o arquivo não existir, retorna None.
        if not os.path.exists(nome_arquivo):
            print(f"Erro: O arquivo '{nome_arquivo}' não foi encontrado.")
            return None
        return os.path.getsize(nome_arquivo)

def principal():# Função principal para coletar frases do usuário, salvá-las em um arquivo, exibir o tamanho do arquivo e imprimir as frases modificadas.
    print("Digite quantas frases quiser! Digite 'sair' para encerrar e salvar o arquivo.")
    frases = Frases()

    while True:
        entrada = input("> ").strip()  # Remove espaços extras
        if not Frases.entrada_valida(entrada):
            break

        frases.adicionar_frase(entrada)  # Adiciona a frase à lista

    # Salva as frases no arquivo original
    nome_arquivo = "Texto.txt"
    frases.salvar_arquivo(nome_arquivo)

    # Imprime as frases modificadas
    frases.imprimir_frases(nome_arquivo)

    # Mensagem de encerramento
    print("\nPrograma encerrado. O arquivo foi salvo e as frases foram processadas!")

if __name__ == "__main__":
    principal()