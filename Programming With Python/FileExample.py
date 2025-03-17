class Exemplo:
    def exemplo_abrir_arquivo(self):
        try:
            with open("Texto.txt", "w") as dados:  # Abre o arquivo e garante que será fechado
                dados.write("Escrevendo alguma coisa ...")
            print("Arquivo escrito com sucesso!")
        except Exception as e:
            print(f"Erro ao escrever no arquivo: {e}")

# Cria uma instância da classe e chama o método
exemplo = Exemplo()
exemplo.exemplo_abrir_arquivo()