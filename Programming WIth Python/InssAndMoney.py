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