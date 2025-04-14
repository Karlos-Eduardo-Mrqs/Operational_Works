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
                        cpf INTEGER PRIMARY KEY,
                        nome TEXT NOT NULL,
                        nascimento DATE
                    )
                """)
                self.conn.commit()
                print("Tabela PESSOA criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela PESSOA: {erro}")

    def criar_tabela_marca(self): 
        """Creates the MARCA table if it doesn't exist."""
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS MARCA (
                        id INTEGER PRIMARY KEY,
                        nome TEXT NOT NULL,
                        sigla TEXT NOT NULL
                    )
                """)
                self.conn.commit()
                print("Tabela MARCA criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela MARCA: {erro}")

    def criar_tabela_veiculo(self): 
        """Creates the CARRO table if it doesn't exist."""
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS CARRO (
                        placa TEXT PRIMARY KEY,
                        cor TEXT NOT NULL,
                        cpf_proprietario INTEGER,
                        id_marca INTEGER,
                        FOREIGN KEY(cpf_proprietario) REFERENCES PESSOA(cpf),
                        FOREIGN KEY(id_marca) REFERENCES MARCA(id)
                    )
                """)
                self.conn.commit()
                print("Tabela CARRO criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela CARRO: {erro}")

    def criar_tabelas(self): 
        """Creates all required tables."""
        self.criar_tabela_pessoa()
        self.criar_tabela_marca()
        self.criar_tabela_veiculo()

    def __enter__(self): 
        """Enables the use of 'with' statements."""
        self.conectar()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb): 
        """Ensures the connection is closed after 'with' block."""
        self.desconectar()

if __name__ == '__main__': 
    # Use the context manager to ensure proper resource management
    with BancoDeDados() as banco:
        banco.criar_tabelas()