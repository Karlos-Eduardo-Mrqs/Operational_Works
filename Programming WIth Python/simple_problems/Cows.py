mais_gordo_num = None;
mais_gordo_peso = float('-inf'); 
mais_magro_num = None;
mais_magro_peso = float('inf');    
for i in range(1, 51):
    numero = int(input(f"Digite o número do {i}º boi: "));
    peso = float(input(f"Digite o peso do {i}º boi: "));
    if peso > mais_gordo_peso:
        mais_gordo_peso = peso;
        mais_gordo_num = numero;
    
    if peso < mais_magro_peso:
        mais_magro_peso = peso;
        mais_magro_num = numero;

print(f"\nO boi mais gordo é o número {mais_gordo_num} com peso {mais_gordo_peso:.2f} kg.");
print(f"O boi mais magro é o número {mais_magro_num} com peso {mais_magro_peso:.2f} kg.");