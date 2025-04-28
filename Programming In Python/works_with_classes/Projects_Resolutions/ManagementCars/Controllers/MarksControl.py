import sqlite3
from Models.Marks import Marca

class MarksDAO:
    def __init__(self, conn):
        if conn is None:
            raise ValueError("Conexão com o banco de dados não pode ser None.")
        self.conn = conn

    def criar_tabela(self):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS MARCA (
                        id INTEGER PRIMARY KEY AUTOINCREMENT,nome TEXT NOT NULL,sigla TEXT NOT NULL
                    )
                """)
                self.conn.commit()
                print("Tabela MARCA criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela MARCA: {erro}")

    def inserir(self, nome: str, sigla: str) -> None:
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("""INSERT INTO MARCA (nome, sigla) VALUES (?, ?)""", (nome, sigla))
                self.conn.commit()
                print(f"A marca foi inserida corretamente!")
            except sqlite3.IntegrityError as erro:
                print(f"Erro de integridade: {erro}")
            except sqlite3.Error as erro:
                print(f"Erro ao inserir marca: {erro}")

    def listar(self):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM MARCA")
                marcas = cursor.fetchall()
                for marca in marcas:
                    print(marca)
            except sqlite3.Error as erro:
                print(f"Algo deu errado: {erro}")

    def buscar_por_id(self, id: int):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM MARCA WHERE id = ?", (id,))
                row = cursor.fetchone()
                if row:
                    return Marca(*row)
            except sqlite3.Error as erro:
                print(f"Erro ao buscar marca por id: {erro}")
        return None

    def buscar_por_nome(self, nome: str):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM MARCA WHERE nome = ?", (nome,))
                row = cursor.fetchall()
                return [Marca(*r) for r in row] if row else []
            except sqlite3.Error as erro:
                print(f"Erro ao buscar marca por nome: {erro}")
        return []