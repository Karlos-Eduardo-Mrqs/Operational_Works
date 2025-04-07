Pair = [];    
Odd = [];
for Index in range(1,20):
    number = int(input(f"Digit {Index} º number:"));
    if number%2 == 0:
        Pair.append(number);
    else:
        Odd.append(number);
print("Pair Numbers:",Pair);
print("Odd Numbers:",Odd)