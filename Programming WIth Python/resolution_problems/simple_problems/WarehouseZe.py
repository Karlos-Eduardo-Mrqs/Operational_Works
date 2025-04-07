print("Welcome to Warehouse by Seu Zé!")
product = str(input("What's the product you want to buy? "))
price = float(input("And what is the price of this product? "))
promotion = (price * 5) / 100
finalprice = price - promotion
print("Okay!")
print("Today we have a 5% discount, and the final price for your", product ,"is", finalprice)