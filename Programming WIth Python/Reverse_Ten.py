Numbers = [];
for Index in range(1,11):
    number = int(input(f"Write {Index} º number:"));
    Numbers.append(number);

Numbers.sort(reverse=True);
print(Numbers);