Media = 0;
for I in range(1,5):
    Nota = float(input(f"Digite a {I}º Nota: "))
    Media += Nota; 

Media/= I ;
print(f"A Media do aluno : {Media}");