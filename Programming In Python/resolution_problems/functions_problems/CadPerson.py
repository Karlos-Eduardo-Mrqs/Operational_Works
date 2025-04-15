import datetime;
def Age(Data):
    UserData = Data.split("/");
    UserYear = int(UserData[2]);
    UserMonth = int(UserData[1]);
    UserDay = int(UserData[0]);
    
    SystemData = datetime.datetime.now();
    SystemYear = int(SystemData.year);
    SystemMonth = int(SystemData.month);
    SystemDay = int(SystemData.day);
    
    Age = SystemYear - UserYear;
    if (SystemMonth < UserMonth):
        Age -=1
    if (SystemMonth == UserMonth):
        if (SystemDay < UserDay):
            Age -=1
        else:
            pass;
    return Age;

def Comparative(name,gender,UserAge):
    message = "";
    LegalAge = False;
    match gender:
        case "M":
            LegalAge = UserAge > 17;
        case "W":
            LegalAge = UserAge > 20;
    if(LegalAge):
        message += f"{name} you are Legal Age({UserAge} years !)"
    else:
        message += f"{name} you aren't Legal Age({UserAge} years !)"
    return message

name = input("Digit your name user :");
gender = input("Digit your gender [M - Man |W - Woman] :");
data = input("Digit your Birth Day [day/month/year] :");
UserAge = Age(data);
Situation = Comparative(name,gender,UserAge);
print(Situation);