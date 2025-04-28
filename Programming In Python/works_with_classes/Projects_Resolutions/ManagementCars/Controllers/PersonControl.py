import sqlite3
from Models.Person import Pessoa

class PessoaDAO:
    def __init__(self, conn):
        if conn is None:
            raise ValueError("Conexão com o banco de dados não pode ser None.")
        self.conn = conn

    def criar_tabela(self):
        try:
            cursor = self.conn.cursor()
            cursor.execute("PRAGMA foreign_keys = ON;")
            cursor.execute("""
                CREATE TABLE IF NOT EXISTS PESSOA (
                    cpf TEXT PRIMARY KEY,
                    nome TEXT NOT NULL,
                    nascimento DATE
                )
            """)
            self.conn.commit()
            print("Tabela PESSOA criada ou já existe.")
        except sqlite3.Error as erro:
            print(f"Erro ao criar tabela PESSOA: {erro}")

    def inserir(self, pessoa: Pessoa):
        if self.buscar_por_cpf(pessoa.cpf):
            print(f"Pessoa com CPF {pessoa.cpf} já existe!")
            return
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO PESSOA (cpf, nome, nascimento) VALUES (?, ?, ?)", 
                           (pessoa.cpf, pessoa.nome, pessoa.nascimento))
            self.conn.commit()
            print(f"Pessoa com CPF {pessoa.cpf} inserida com sucesso!")
        except sqlite3.IntegrityError as erro:
            print(f"Erro de integridade: {erro}")
        except sqlite3.Error as erro:
            print(f"Erro ao inserir pessoa: {erro}")

    def listar(self, nome: str):
        try:
            cursor = self.conn.cursor()
            query = "SELECT * FROM PESSOA"
            if nome:
                query += " WHERE nome LIKE ?"
                cursor.execute(query, ('%' + nome + '%',))
            else:
                cursor.execute(query)
            return [Pessoa(*row) for row in cursor.fetchall()]
        except sqlite3.Error as erro:
            print(f"Erro ao listar pessoas: {erro}")
            return []

    def atualizar(self, cpf: str, pessoa: Pessoa):
        try:
            cursor = self.conn.cursor()
            cursor.execute("""
                UPDATE PESSOA 
                SET cpf = ?, nome = ?, nascimento = ?
                WHERE cpf = ?
            """, (pessoa.cpf, pessoa.nome, pessoa.nascimento, cpf))
            self.conn.commit()
            if cursor.rowcount > 0:
                print(f"Pessoa com CPF {cpf} atualizada!")
            else:
                print(f"Nenhuma pessoa com CPF {cpf} encontrada para atualizar.")
        except sqlite3.Error as erro:
            print(f"Erro ao atualizar pessoa: {erro}")

    def apagar(self, cpf: str):
        try:
            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM PESSOA WHERE cpf = ?", (cpf,))
            self.conn.commit()
            print(f"Pessoa com CPF {cpf} apagada!")
        except sqlite3.Error as erro:
            print(f"Erro ao apagar pessoa: {erro}")

    def buscar_por_cpf(self, cpf: str):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM PESSOA WHERE cpf = ?", (cpf,))
            row = cursor.fetchone()
            return Pessoa(*row) if row else None
        except sqlite3.Error as erro:
            print(f"Erro ao buscar pessoa: {erro}")
            return None