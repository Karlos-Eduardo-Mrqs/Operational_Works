Height = input("Enter your height: ")
Height = float(Height)

WeightHm = (72.7 * Height) - 58
WeightWn = (62.1 * Height) - 44.7

print("User!")
print(f"Are you a man? Your ideal weight is: {WeightHm:.1f} kg")
print(f"Are you a woman? Your ideal weight is: {WeightWn:.1f} kg")
