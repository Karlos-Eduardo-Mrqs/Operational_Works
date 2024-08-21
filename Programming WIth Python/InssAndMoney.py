# Faça um Programa que pergunte quanto você ganha por hora e o número de horas trabalhadas no mês. Calcule e mostre o total do seu salário no referido mês, sabendo-se que são descontados 11% para o Imposto de Renda, 8% para o INSS e 5% para o sindicato, faça um programa que nos dê:salário bruto. quanto pagou ao INSS. quanto pagou ao sindicato. o salário líquido. calcule os descontos e o salário líquido, conforme a tabela abaixo:

wage = input("Write your wage per hour:");
hours = input("Write whats hours you work:");
brute_wage = float(wage) * float(hours);

discount_income = (brute_wage * 11) /100;
discount_inss = (brute_wage * 8) /100 ;
discount_sindicate = (brute_wage * 5) / 100; 
All_discounts = (discount_income + discount_inss + discount_sindicate);
Liq_wage = brute_wage - All_discounts;

print("All Results:");
print(f"The brute wage : R$ {brute_wage:.2f}");
print(f"The discount income(11%) : R$ {discount_income:.2f}");
print(f"The discount inss(8%) : R$ {discount_inss:.2f}");
print(f"The discount sindicate(5%) : R$ {discount_sindicate:.2f}");
print(f"The liquid wage: R$ {Liq_wage:.2f}")