import re

texto = "(123) 456-7890";
padrao = r'\(\d{3}\) \d{3}-\d{4}'

resultado = re.search(padrao,texto)

if resultado:
    numero = resultado.group();
    print(f"O numero de telefone foi encontrado {numero}  !");
else:
    print(f"O numero de telefone não foi encontrado !");