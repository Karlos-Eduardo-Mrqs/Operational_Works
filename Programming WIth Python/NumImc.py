pessoas = [];
TemMaisAlguem = True;
while (TemMaisAlguem) :
    print("Bem Vindo A Calculadora de IMC(Indice De Massa Corporal ) !");
    nome = input("Digite seu nome : ");
    peso = float(input("Digite seu peso em kg : "));
    altura = float(input("Digite sua altura em metros : "));
    Imc = peso / (altura * altura);
    if(Imc < 18.5):
        situacao += 'Baixo Peso';
    if Imc >= 18.5 and Imc < 24.9 :
        situacao += 'Peso Normal';
    if Imc >= 25 and Imc < 29.9 :
        situacao += 'Excesso De Peso';
    if Imc >= 30 and Imc < 34.9:
        situacao += 'Obesidade I';
    if Imc >= 35 and Imc < 39.9:
        situacao += 'Obesidade II';
    if Imc >= 40:
        situacao += 'Obesidade Mórbida';
    pessoas.append(f"{nome} seu Imc está com {situacao}, Valor Imc = {Imc:,.1f}");
    Resposta = input("Tem mais alguem para cadastrar seu imc [S - sim / N - não]").upper();    
    TemMaisAlguem = bool(Resposta == "S");
    situacao = "";
pessoas.sort(key=lambda x: x[0])
print(pessoas);