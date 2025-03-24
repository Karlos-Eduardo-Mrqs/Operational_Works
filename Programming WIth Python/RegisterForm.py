import re
from dataclasses import dataclass

@dataclass
class Usuarios:
    email: str = None  # Default value is None
    telefone: str = None  # Default value is None

    def telefone_valido(self, telefone_usuario: str) -> bool: #Validates the phone number format using a regular expression.Returns True if valid, False otherwise.        
        padrao = r'\(\d{2}\) \d{5}-\d{4}'  # Example: (99) 99999-9999
        return re.match(padrao, telefone_usuario) is not None

    def receber_telefone(self) -> None: #Prompts the user to input a phone number and validates it.If valid, assigns it to the telefone attribute.
        while True:
            telefone_usuario = input("Digite o seu telefone no formato (99) 99999-9999: ").strip()
            if self.telefone_valido(telefone_usuario):
                self.telefone = telefone_usuario
                print("O seu telefone é válido.")
                break
            else:
                print("O seu telefone é inválido. Tente novamente.")

    def email_valido(self, email_usuario: str) -> bool: #Validates the email format using a regular expression.Returns True if valid, False otherwise.
        padrao = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$'
        return re.match(padrao, email_usuario) is not None

    def receber_email(self) -> None: #Prompts the user to input an email and validates it.If valid, assigns it to the email attribute.
        while True:
            email_usuario = input("Digite o seu email: ").strip()
            if self.email_valido(email_usuario):
                self.email = email_usuario
                print("O seu email é válido.")
                break
            else:
                print("O seu email é inválido. Tente novamente.")

usuario = Usuarios()
usuario.receber_email()
usuario.receber_telefone()

print(f"Email recebido: {usuario.email}")
print(f"Telefone recebido: {usuario.telefone}")