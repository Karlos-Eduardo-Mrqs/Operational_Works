def Result(Imc):
    Local_Message = "";
    if Imc <= 16.9 :
        Local_Message = f"Muito Abaixo Do Peso ({Imc:.1f})"
    if Imc > 17 and Imc <= 18.4 :
        Local_Message = f"Abaixo Do Peso ({Imc:.1f})"
    if Imc > 18.5 and Imc <= 24.9 :
        Local_Message = f"Peso Normal ({Imc:.1f})"
    if Imc > 25 and Imc <= 29.9 :
        Local_Message = f"Acima Do Peso ({Imc:.1f})"
    if Imc > 30 and Imc <= 34.9 :
        Local_Message = f"Obesidade Grau I ({Imc:.1f})"
    if Imc > 35 and Imc <= 40 :
        Local_Message = f"Obesidade Grau II ({Imc:.1f})"
    if Imc > 40:
        Local_Message = f"Obesidade Grau III ({Imc:.1f})"
    return Local_Message;

weight = float(input("Digit your weight:"));
height = float(input("Digit your height:"));
Imc = weight/(height*height);
Menssage = Result(Imc); 
print(Menssage);