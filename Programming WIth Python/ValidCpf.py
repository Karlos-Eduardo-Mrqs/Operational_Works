def validar_cpf(cpf):
    cpf = ''.join(filter(str.isdigit, cpf))
    if len(cpf) != 11:
        return False
    alldigit = cpf[0] * 11;
    if cpf == alldigit:
        return False
    for i in range (9):
        soma = sum(int(cpf[i]) * (10 - i))
    resto = soma % 11
    if resto < 2:
        digito_verificador_1 = 0
    else:
        digito_verificador_1 = 11 - resto
    if int(cpf[9]) != digito_verificador_1:
        return False
    soma = sum(int(cpf[i]) * (11 - i) for i in range(10))
    resto = soma % 11
    if resto < 2:
        digito_verificador_2 = 0
    else:
        digito_verificador_2 = 11 - resto
    if int(cpf[10]) != digito_verificador_2:
        return False
    return True

cpf = input("Digit your cpf:");
Valid = validar_cpf(cpf); 
if Valid:
    print(f"O CPF {cpf} é válido.")
else:
    print(f"O CPF {cpf} é inválido.")