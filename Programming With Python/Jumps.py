Athelets = [];

Many_Athelets = int(input("How many Athelets Are Participate ?:"));

for Index in range(Many_Athelets) :
    One_Athelet = input(f"{Index + 1}º Name of Athelet:") ;
    Distance = float(input(f"How far did {One_Athelet} jump ?:"));
    Athelets.append(f"{Index}º Athelet Name{One_Athelet} And Distance Jump {Distance} ;");

# Em Breve Mais Adições !