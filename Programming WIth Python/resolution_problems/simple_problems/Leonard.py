ManyProducts = int(input("How many products you have nescessity ?:"));
Total = [0] * 3;
Cont = [0] * 3;
Products = [0] * ManyProducts;
Size_Products = len(Products);

for I in range(Size_Products) :
    One_Product = "";
    Name = input(f"Digit The Name of {I}º Product : ");
    Pur_Price = float(input(f"Digit The Purchase Price of {Name} :"));
    Sale_Price = float(input(f"Digit The Sale Price of {Name} :"));
    Gain = Pur_Price - Sale_Price;
    Total[0] += Pur_Price;
    Total[1] += Sale_Price;
    Total[2] += Gain;
    Percentage = (Gain * 100) / 100;
    One_Product+= f"Product Name:{Name} | Purchase_Price:{Pur_Price:.2f} | Sale_Price:{Sale_Price:.2f} | Percentage Of Gain:{Percentage:.1f}";
    if (Percentage <= 10):
        Cont[0] += 1;
    elif (Percentage >= 10 and Percentage <= 20):
        Cont[1] += 1;
    else:
        Cont[2] +=1;
    Products.append(One_Product);

print(Products);