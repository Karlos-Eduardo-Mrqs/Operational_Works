class Exemplo: # Criando uma classe chamada exemplo
    def exemplo_abrir_arquivo(self): # Criando uma funcao para abrir/escrever/baixar o arquivo 
        try:
            with open("Texto.txt", "w") as dados:  # Abre o arquivo e garante que será fechado
                dados.write("Escrevendo alguma coisa ...") # Escreva uma mensagem dentro do arquivo 
            print("Arquivo escrito com sucesso!") 
        except Exception as e: 
            print(f"Erro ao escrever no arquivo: {e}") # Faz uma exceção caso o arquivo não existe

exemplo = Exemplo() # Cria uma instância da classe e chama o método
exemplo.exemplo_abrir_arquivo()