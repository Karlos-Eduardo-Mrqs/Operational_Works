import os
i = input("How many numbers you necessity ?:");
i = int(i);

numbers=[];
cont = 0;

while cont < i :
    number = input(f"Digit your {cont}º number:");
    number = int(number);
    numbers.append(number);
    cont+=1;

os.system("cls");

print("Decrescent Order:");
numbers.sort(reverse=True);
for number in numbers :
    print(number);

print("Crescent Order:");
numbers.sort(reverse=False);
for number in numbers :
    print(number);
