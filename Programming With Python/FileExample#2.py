arquivo = open("Texto.txt","w");
arquivo.write("Raphael");
arquivo.writelines(["\n Caroline","\n Vanessa ","\n Daniel","\n Morais","\n Yan"]);
arquivo.close();

arquivo2 = open("texto.txt","r"); 
linhas = arquivo2.readlines();
for i , linha in enumerate(linhas,start= 1):
    print(f"Linha :{i}: {linha}");