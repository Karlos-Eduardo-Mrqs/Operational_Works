import os

Create = True
Edit = True
List = []

def Clear_Console():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def Memory_List(List, Item_List):
    List.append(Item_List);
    List_lenght = len(List);
    for index in range(List_lenght):
        if List[index] == List[index - 1]:
            List.remove(Item_List);
            break;
    return List;

def Repeat(inputC):
    return inputC.upper() == "Y"

def Chaging(Changes,List,Code_Change):
    match Changes:
        case "E":
            Name_Change = input(f"What are the new name for {List[Code_Change]} ?:");
            List[Code_Change] = Name_Change;
        case "D":
            List.remove(List[Code_Change]);
    return List;

while Create:
    Clear_Console();
    Item_List = input("Digit The Name Of Item: ");
    List = Memory_List(List, Item_List);
    Continue = input("You Have Other Item For Addition [Y - Yes | N - No]?: ");
    Create = Repeat(Continue);

while Edit:
    Clear_Console();
    for index in range(len(List)):
        print(f"Change Code [{index}] Iten_Name:{List[index]}");
    Code_Change = int(input('Input With Change Code:'));
    Changes = input(f"{List[Code_Change]}, you are [Edit - E | Delete - D] : ?");
    Chaging(Changes,List,Code_Change);
    Continue = input("You Have Other Item For Modify [Y - Yes | N - No]?: ");
    Edit = Repeat(Continue);

Clear_Console();
print(List);