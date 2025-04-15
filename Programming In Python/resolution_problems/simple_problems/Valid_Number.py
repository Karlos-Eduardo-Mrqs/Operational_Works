Cont = 0;
Not_Valid = True;
Message = "";
while(Not_Valid):
    print(Message);
    number=input("Digit one number deliver one until ten:");
    number = int(number);
    if(number >= 1 and number <=10):
        Not_Valid = False;
    else:
        Not_Valid = True;
        Cont += 1 ;
        Message = "Invalid !"; 

print(f"The number {number} are valid !");
print(f"And you digit {Cont} numbers invalids !");