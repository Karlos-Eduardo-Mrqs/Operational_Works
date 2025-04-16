texto = "Nossa aula Manipulando String"
print(texto[0:18:2]); # 0,2,4,6,8,10,12,14,16,18 Nssal aiu
print(texto[:15]); # range(0,15) Nossa aula Mani  
print(len(texto)) # tamanho do texto, nesse caso 30
print("--------------------------------------------------")
print(texto.count('a')) # Nossa. [0] = N , [1] = o , [2] = s , [3] = s , [4] = a . 5 caracteres !
print("--------------------------------------------------")
print(texto.count('a',5,30)) # Nossa aula Manipulando String . Depois do 5 até o número 30, ele vai contar todas as letras "a" da frase. Sendo as casas [6.9,12,18] 
print("--------------------------------------------------")
print(texto.find(' ')); # Ele retorna a casa onde se encontra a letra ou onde começa a palavra desejada; sendo ele o primeiro a ser encontrado. Senão encontrar, ele retorna -1

'''
for indice_letra in range (0,len(texto)): 
    print(texto[indice_letra], "casa :",indice_letra);  
'''
