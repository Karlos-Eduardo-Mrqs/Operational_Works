from dataclasses import dataclass
from datetime import date
from Person import Pessoa
from Marks import Marca

@dataclass
class Carro:
    placa:str
    cor:str
    proprietario: Pessoa
    marca: Marca