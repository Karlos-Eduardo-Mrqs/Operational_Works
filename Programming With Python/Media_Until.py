media = 0;
Until_Media = int(input("How many numbers do you need?: "));

for Index in range(Until_Media):
    number = float(input(f"Enter number {Index + 1}: "));
    media += number;

media /= Until_Media;  
print(f"Final Average: {media}");