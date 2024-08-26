Insert = True; 
Users = [];

def Valid_Data(name,age,wage,gender,civil_state):
     if len(name) < 3:
        print("Name must be at least 3 characters long.")
        return False
     if age < 0 or age > 150:
        print("Age must be between 0 and 150.")
        return False
     if wage < 0:
        print("Wage must be greater than or equal to 0.")
        return False
     if gender not in ["M", "W", "O"]:
        print("Gender must be 'M', 'W', or 'O'.")
        return False
     if civil_state not in ["S", "M", "W", "D"]:
        print("Civil state must be 'S', 'M', 'W', or 'D'.")
        return False
     return True

def Repeat(Continue):
    return Continue.upper() == "Y";

while(Insert):
    name = input("Digit your Name:");
    age = int(input("Digit your Age:"));
    wage = float(input("Digit your Wage:"));
    gender = input("Digit your Gender [M - Man | W - Woman]:");
    print("[ S - single | M - married| W - widower| D - divorced ]");
    civil_state = input("Your Civil State is:");
    Valid_User = Valid_Data(name,age,wage,gender,civil_state); 
    if Valid_User:
        print("Valid User !");
        One_User = [name,age,wage,gender,civil_state];
        Users.append(One_User);
        print(f"{Users}");
    else:
        print("Invalid User !");
    Continue = input("You have other user for insert [Y - yes | N - no]?:");
    Insert=Repeat(Continue);

print(Users);