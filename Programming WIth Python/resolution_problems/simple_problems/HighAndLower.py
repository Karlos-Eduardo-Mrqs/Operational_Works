number1 = input("Digit the first number:");
number2 = input("Digit the second number:");
number3 = input("Digit the third number:");

number1 = int(number1);
number2 = int(number2);
number3 = int(number3);

message = "";

if(number1 >= number2 and number1 >= number3): 
    message += f"1°: {number1} ,";
    if(number2 >= number3):
        message += f"2°: {number2} , 3°: {number3} ";
    else:
        message += f"2°: {number3} , 3°: {number2} ";

elif(number2 >= number1 and number2 >= number3): 
    message += f"1°: {number2} ,";
    if(number1 >= number3):
        message += f"2°: {number1} , 3°: {number3} ";
    else:
        message += f"2°: {number3} , 3°: {number1} ";

elif(number3 >= number1 and number3 >= number2): 
    message += f"1°: {number3} ,";
    if(number2 >= number1):
        message += f"2°: {number2} , 3°: {number1} ";
    else:
        message += f"2°: {number1} , 3°: {number2} ";

else:
    message += f"Number1:{number1} = Number2:{number2} = Number3:{number3}";
print(message);