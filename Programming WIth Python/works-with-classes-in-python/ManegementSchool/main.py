from menu import *

class Alunos:
    def __init__(self,nome:str,matricula:str,turma:int,notas:list[float])->None:
        self.nome = nome
        self.matricula = matricula
        self.turma = turma
        self.notas = notas

if __name__ == "__main__":
    main()