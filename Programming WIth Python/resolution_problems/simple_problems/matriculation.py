Registers = [];
Matriculate = input("Register your Matriculate our Press -1 For Said:");
while (Matriculate != "-1"):
    Media = 0;
    for I in range(0,2):
        Note = float(input("Digit One Note(0 until 10):"));
        Media += Note;
    Media /= I+1;
    NotInMedia = bool(Media < 6);
    if(NotInMedia):
            Registers.append(f"{Matriculate} dont are approved");
    else:
        Registers.append(f"{Matriculate} are approved");
    Matriculate = input("Register your Matriculate our Press -1 For Said:");
print(Registers);