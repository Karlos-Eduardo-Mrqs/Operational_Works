import datetime

today = datetime.datetime.now()
day = today.day
month = today.month
year = today.year

def get_birthday():
    user_day = int(input("What is your Birthday Day?: "))
    user_month = int(input("What is your Birthday Month?: "))
    user_year = int(input("What is your Birthday Year?: "))
    birth_date = datetime.datetime(user_year, user_month, user_day);
    return birth_date

user_birthday = get_birthday()
age = year - user_birthday.year

if (month, day) < (user_birthday.month, user_birthday.day):
    age -= 1
if today.month > user_birthday.month or (today.month == user_birthday.month and today.day >= user_birthday.day):
    months = today.month - user_birthday.month
    days = today.day - user_birthday.day
else:
    months = today.month + 12 - user_birthday.month
    days = today.day - user_birthday.day
if days < 0:
    # Corrige o número de dias para o mês anterior
    last_month = today.month - 1 if today.month > 1 else 12
    days_in_last_month = (datetime.datetime(year, last_month + 1, 1) - datetime.datetime(year, last_month, 1)).days
    days += days_in_last_month
    months -= 1
print(f"You are {age} years, {months} months, and {days} days old!")