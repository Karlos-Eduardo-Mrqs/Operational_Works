
texto = "Voce tem que aprender a fazer programa !";

novo_texto = texto.replace('a fazer programa !','a trabalhar igual uma safada !'); # Subistitui uma parte da frase para outra nova 
print(novo_texto);

print(texto.startswith('V')); # Verificação booleana, se a frase começa com uma letra/palavra( True / False) .
print(texto.endswith('!')); # Verificação booleana, se a frase termina com uma letra/palavra( True / False) .

print("-------------------------------------------------------");

print(texto.lower()); # O texto inteiro fica em letra minúscula
print(texto.upper()) # O texto inteiro fica em letra maíuscula
print(texto.capitalize()) # O texto inteiro fica com a primeira letra em maíusculo 
print(texto.title()) # O texto inteiro fica com todas as primeiras palavras separadas, com a letra em maíuscula 
print(texto.swapcase()) # O texto inteiro fica com todas as palavras em maiúsculo,menos a primeira letra

print("-------------------------------------------------------");

nome = input("Digite seu nome :");
nome2 = input("Digite seu nome2 :");
print(f"Fala aí {nome.strip()} !") # remove os espaços em branco !
print(f"Fala aí {nome.rstrip()} {nome2} ") # remove os espaços em branco na direita 
print(f"Fala aí {nome.lstrip()} !") # remove os espaços em branco na esquerda