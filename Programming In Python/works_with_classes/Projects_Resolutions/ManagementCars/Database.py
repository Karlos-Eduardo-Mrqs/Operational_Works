import os
import sqlite3
from Controllers import CarsControl, PersonControl, MarksControl
from Models.Person import Pessoa

class BancoDeDados:
    def __init__(self, nome_banco='banco.sqlite'): 
        """Inicializa a conexão com o banco de dados."""
        self.nome_banco = os.path.join(os.path.dirname(__file__), nome_banco)
        self.conn = None

    def conectar(self): 
        """Conecta ao banco de dados SQLite."""
        try:
            self.conn = sqlite3.connect(self.nome_banco)
            print("Conexão estabelecida com sucesso!")
        except sqlite3.Error as erro:
            print(f"Erro ao conectar ao banco de dados: {erro}")
            raise  # Relança a exceção para propagá-la, caso necessário.

    def desconectar(self): 
        """Fecha a conexão com o banco de dados."""
        if self.conn:
            self.conn.close()
            self.conn = None
            print("Conexão encerrada.")

    def criar_tabelas(self):  
        """Cria todas as tabelas chamando os métodos dos Controllers."""
        if self.conn:
            try:
                MarksControl.MarksDAO(self.conn).criar_tabela()
                PersonControl.PessoaDAO(self.conn).criar_tabela()
                CarsControl.CarroDAO(self.conn).criar_tabela()
                print("Tabelas criadas com sucesso!")
            except sqlite3.Error as erro:
                print(f"Erro ao criar as tabelas: {erro}")
                self.conn.rollback()  # Caso haja erro, reverte a transação.

    def __enter__(self): 
        """Permite o uso da instrução 'with' para conectar automaticamente."""
        self.conectar()
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        """Garante que a conexão será fechada após o bloco 'with'."""
        self.desconectar()
        if exc_type:
            print(f"Erro no bloco 'with': {exc_value}")

if __name__ == '__main__':
    banco = BancoDeDados()
    try:
        # Usando 'with' para gerenciar automaticamente a conexão com o banco de dados
        with banco:
            banco.criar_tabelas()
            
            # Teste de inserção e leitura de marcas
            controle_marca = MarksControl.MarksDAO(banco.conn)
            controle_marca.inserir("Build Your Dreams", "BYD")  # Inserindo marca
            marcas = controle_marca.listar()  # Listando todas as marcas
            print("\nMarcas cadastradas:")
            for marca in marcas:
                print(marca)
            
            # Teste de inserção e leitura de carros
            controle_carro = CarsControl.CarroDAO(banco.conn)
            controle_carro.inserir("QWX-7895", "Rosinha", 55566644478)  # Inserindo carro
            carros = controle_carro.listar_tabela_carro()  # Listando todos os carros
            print("\nCarros cadastrados:")
            for carro in carros:
                print(carro)
            
            # Teste de inserção e leitura de pessoas
            controle_pessoa = PersonControl.PessoaDAO(banco.conn)
            pessoa = Pessoa(cpf="123.456.789-00", nome="Carlos Eduardo", nascimento="1995-10-10")
            controle_pessoa.inserir(pessoa)  # Inserindo pessoa
            pessoas = controle_pessoa.listar()  # Listando todas as pessoas
            print("\nPessoas cadastradas:")
            for p in pessoas:
                print(f"{p.nome}, CPF: {p.cpf}, Nascimento: {p.nascimento}")
            
            # Teste de busca por CPF
            cpf_busca = "123.456.789-00"
            pessoa_busca = controle_pessoa.buscar_por_cpf(cpf_busca)
            if pessoa_busca:
                print(f"\nPessoa encontrada: {pessoa_busca.nome}, CPF: {pessoa_busca.cpf}")
            else:
                print(f"\nNenhuma pessoa encontrada com o CPF {cpf_busca}")

    except Exception as e:
        print(f"Erro ao realizar operações no banco de dados: {e}")