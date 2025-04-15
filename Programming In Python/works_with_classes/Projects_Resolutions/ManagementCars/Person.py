from dataclasses import dataclass
from datetime import date

@dataclass
class Pessoa:
    nome:str
    cpf:str
    nascimento:date