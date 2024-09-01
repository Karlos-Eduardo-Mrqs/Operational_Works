import datetime
Today = datetime.datetime.now()
Year = int(Today.year);
User_Year = int(input("Say your Birthday Year ?:"));
print(f" You have {Year - User_Year} years !");