nome = input("Digite o nome do aluno:");
media = 0; 
mensagem = "";
for i in range(1,3):
    nota = float(input(f"Digite a {i}º nota :"));
    media += nota;
media /= i;
if media >=6:
    mensagem += f"O aluno {nome} foi aprovado !";
else:
    mensagem += f"O aluno {nome} foi reprovado !";
print(mensagem);