try:
    number = [1, 2, 3, 4, 5]
    lenNumbers = len(number) ;
    NumOk = print(number[10]);
except IndexError:
    print("You have {} numbers only !".format(len(number)));