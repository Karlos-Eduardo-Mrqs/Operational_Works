number = int(input("Digit one number:"));
 
Fat = 1;
for i in range(number,0,-1):
    Fat *= i;

print(f"!{number} = {Fat}");    
