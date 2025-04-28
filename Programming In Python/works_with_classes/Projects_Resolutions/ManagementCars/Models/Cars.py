from dataclasses import dataclass
from Models.Person import Pessoa
from Models.Marks import Marca

@dataclass
class Carro:
    placa:str
    cor:str
    proprietario: Pessoa
    marca: Marca
