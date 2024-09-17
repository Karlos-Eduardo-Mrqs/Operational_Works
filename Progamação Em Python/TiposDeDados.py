nome = "Carlos" ;
num1 = 40;
num2 = 09.95 ;
num3= complex(4);
realidade = True;
Ia = False;
byte =b"Hello"; 
objetodict = {"name" : "John", "age" : 36}	
objetosett = {"apple", "banana", "cherry"}
congelarsett = frozenset({"apple", "banana", "cherry"});
byteArray = bytearray(5)
memoria = memoryview(bytes(5))
lista = ["apple", "banana", "cherry"]; 	
tuplla = ("apple", "banana", "cherry")
atequanto = range(6)
Nada = None;

print("Name i's", type(nome));
print("Number1 i's", type(num1));
print("Number2 i's", type(num2));
print("Number3 i's", type(num3));
print("Reality i's", type(realidade));
print("Ia i's", type(Ia));
print("Byte i's", type(byte));
print("Dict i's", type(objetodict));
print("Set i's", type(objetosett));
print("Frozen i's", type(congelarsett));
print("Bytes Array i's", type(byteArray));
print("MemoryView i's", type(memoria));
print("List i's", type(lista));
print("Tuple i's", type(tuplla));
print("Range i's", type(atequanto));
print("None i's", type(Nada));