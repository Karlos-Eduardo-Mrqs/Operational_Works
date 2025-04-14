import os
import sqlite3

class BancoDeDados:
    def __init__(self, nome_banco='Gerenciamento.sqlite'): 
        """Initializes the database connection."""
        self.nome_banco = os.path.join(os.path.dirname(__file__), nome_banco)
        self.conn = None

    def conectar(self): 
        """Connects to the SQLite database."""
        try:
            self.conn = sqlite3.connect(self.nome_banco)
            print("Conexão estabelecida com sucesso!")
        except sqlite3.Error as erro:
            print(f"Erro ao conectar ao banco de dados: {erro}")

    def desconectar(self): 
        """Closes the database connection."""
        if self.conn:
            self.conn.close()
            self.conn = None
            print("Conexão encerrada.")

    def criar_tabela_pessoa(self): 
        """Creates the PESSOA table if it doesn't exist."""
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS PESSOA (
                        cpf TEXT PRIMARY KEY,nome TEXT NOT NULL,nascimento DATE
                    )
                """)
                self.conn.commit()
                print("Tabela PESSOA criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela PESSOA: {erro}")

    def inserir_tabela_pessoa(self, cpf: int, nome: str, nascimento: str) -> None:
        """
        Insere uma nova pessoa na tabela PESSOA.
        
        :param cpf: CPF da pessoa (PRIMARY KEY).
        :param nome: Nome da pessoa.
        :param nascimento: Data de nascimento da pessoa (formato: YYYY-MM-DD).
        """
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("""
                    INSERT INTO PESSOA (cpf, nome, nascimento)
                    VALUES (?, ?, ?)
                """, (cpf, nome, nascimento))
                self.conn.commit()
                print(f"Pessoa com CPF {cpf} inserida com sucesso!")
            except sqlite3.IntegrityError as erro:
                print(f"Erro de integridade: {erro}")
            except sqlite3.Error as erro:
                print(f"Erro ao inserir pessoa: {erro}")

    def listar_tabela_pessoa(self):
        if self.conn:
            try:
                cursor = self.conn.cursor();
                cursor.execute("SELECT * FROM PESSOA;")
                pessoas = cursor.fetchall()
                print("Exibindo tabela pessoas !")
                for pessoa in pessoas:
                    print(pessoa)
            except sqlite3.Error as erro:
                print(f"Algo deu errado {erro}")

    def criar_tabela_marca(self):  # Creates the MARCA table if it doesn't exist. 
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS MARCA (
                        id INTEGER PRIMARY KEY,nome TEXT NOT NULL,sigla TEXT NOT NULL
                    )
                """)
                self.conn.commit()
                print("Tabela MARCA criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela MARCA: {erro}")

    def criar_tabela_veiculo(self):  # Creates the CARRO table if it doesn't exist.
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS CARRO (
                        placa TEXT PRIMARY KEY,cor TEXT NOT NULL,cpf_proprietario INTEGER,id_marca INTEGER,
                        FOREIGN KEY(cpf_proprietario) REFERENCES PESSOA(cpf),FOREIGN KEY(id_marca) REFERENCES MARCA(id)
                    )""")
                self.conn.commit()
                print("Tabela CARRO criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela CARRO: {erro}")

    def criar_tabelas(self):  # Creates all required tables.
        self.criar_tabela_pessoa()
        self.criar_tabela_marca()
        self.criar_tabela_veiculo()

    def __enter__(self): # Enables the use of 'with' statements.
        self.conectar()
        return self

    def __exit__(self): 
        """Ensures the connection is closed after 'with' block."""
        self.desconectar()

if __name__ == '__main__':
    with BancoDeDados() as banco:
        # Criar tabelas (caso ainda não existam)
        banco.criar_tabelas()

        # Inserir alguns dados de exemplo
        banco.inserir_tabela_pessoa(cpf=12345678900, nome="João Silva", nascimento="1990-05-15")
        banco.inserir_tabela_pessoa(cpf=98765432100, nome="Maria Souza", nascimento="1985-08-20")

        # Listar a tabela PESSOA
        banco.listar_tabela_pessoa()