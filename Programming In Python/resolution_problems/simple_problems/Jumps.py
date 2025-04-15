Many_Athelets = int(input("How many Athelets Are Participate ?:"));
Athelets = [];
for Index in range(Many_Athelets) :
    One_Athelet = input(f"{Index + 1}º Name of Athelet:") ;
    Distance = float(input(f"How far did {One_Athelet} jump ?:"));
    Athelets.append((One_Athelet,Distance));

Athletes_Sorted = sorted(Athelets, key=lambda x: x[1], reverse=True);
Rank_Cont = 0;
for athlete in Athletes_Sorted:
    Rank_Cont += 1;
    print(f"{Rank_Cont}º Athlete: {athlete[0]}, Jump Distance: {athlete[1]} meters");