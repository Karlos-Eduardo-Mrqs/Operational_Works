i= 0;
media = 0 ;
while (i <= 3):
    i += 1;
    numero = input(f"Digit the {i} note for student :") ;
    numero = int(numero);
    media += numero; 
    if  i == 4 :
        media /= 4;

print(f"A media do aluno : {media}");