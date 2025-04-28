import sqlite3
from Models.Cars import Carro

class CarroDAO:
    def __init__(self, conn):
        self.conn = conn

    def criar_tabela(self):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("PRAGMA foreign_keys = ON;")
                cursor.execute("""
                    CREATE TABLE IF NOT EXISTS CARRO (
                        placa TEXT PRIMARY KEY, cor TEXT NOT NULL, cpf_proprietario INTEGER, id_marca INTEGER,
                        FOREIGN KEY(cpf_proprietario) REFERENCES PESSOA(cpf), FOREIGN KEY(id_marca) REFERENCES MARCA(id)
                    )""")
                self.conn.commit()
                print("Tabela CARRO criada ou já existe.")
            except sqlite3.Error as erro:
                print(f"Erro ao criar tabela CARRO: {erro}")

    def inserir(self, placa: str, cor: str, cpf_proprietario: int, id_marca: int) -> None:
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("""INSERT INTO CARRO (placa, cor, cpf_proprietario, id_marca) VALUES (?, ?, ?, ?)""", 
                               (placa, cor, cpf_proprietario, id_marca))
                self.conn.commit()
                print(f"Carro inserido corretamente!")
            except sqlite3.IntegrityError as erro:
                print(f"Erro de integridade: {erro}")
            except sqlite3.Error as erro:
                print(f"Erro ao inserir carro: {erro}")

    def listar(self):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM CARRO")
                carros = cursor.fetchall()
                for carro in carros:
                    print(carro)
            except sqlite3.Error as erro:
                print(f"Algo deu errado: {erro}")

    def atualizar(self, placa: str, cor: str, cpf_proprietario: int, id_marca: int):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("UPDATE CARRO SET placa = ?, cor = ?, cpf_proprietario = ?, id_marca = ? WHERE placa = ?", 
                               (placa, cor, cpf_proprietario, id_marca, placa))
                self.conn.commit()
            except sqlite3.Error as erro:
                print(f"Erro ao atualizar carro: {erro}")

    def apagar(self, placa: str):
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("DELETE FROM CARRO WHERE placa = ?", (placa,))
                self.conn.commit()
            except sqlite3.Error as erro:
                print(f"Erro ao deletar carro: {erro}")

    def buscar(self):
        veiculos = []
        if self.conn:
            try:
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM CARRO")
                for row in cursor.fetchall():
                    placa, cor, cpf_proprietario, id_marca = row
                    proprietario = self.buscar_pessoa_pelo_cpf(cpf_proprietario)
                    marca = self.buscar_marca_pelo_id(id_marca)
                    veiculos.append(Carro(placa, cor, proprietario, marca))
            except sqlite3.Error as erro:
                print(f"Erro ao buscar carros: {erro}")
        return veiculos

    def buscar_pela_placa(self, placa: str):
        if self.conn:
            try: 
                cursor = self.conn.cursor()
                cursor.execute("SELECT * FROM CARRO WHERE placa = ?", (placa,))
                row = cursor.fetchone()
                if row:
                    placa, cor, cpf_proprietario, id_marca = row
                    proprietario = self.buscar_pessoa_pelo_cpf(cpf_proprietario)
                    marca = self.buscar_marca_pelo_id(id_marca)
                    return Carro(placa, cor, proprietario, marca)
            except sqlite3.Error as erro:
                print(f"Erro ao buscar carro: {erro}")
        return None