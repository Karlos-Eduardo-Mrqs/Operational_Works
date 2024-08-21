number = input("Digit one number:");
number = int(number);
situation = "";
if number > 0:
    situation += "The number "+ str(number) +", is positive";
else :
    situation += "The number " + str(number) +", is negative";

print(situation);