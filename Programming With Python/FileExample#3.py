import os 

arquivo = open("Texto.txt","w",encoding='utf-8');

for i in range(1,1000):
        arquivo.write(f"Aqui é a linha {i}. \n");

tamanho = os.path.getsize('Texto.txt');
print("Nome do arquivo:",arquivo.name)
print("tamanho do arquivo:",tamanho)
print("Modo do arquivo:",arquivo.mode)
print("Arquivo esta fechado ?:",arquivo.closed)
arquivo.close();
print("Arquivo esta fechado ?:",arquivo.closed)