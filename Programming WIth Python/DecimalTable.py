def print_formatted(number):
    # Calculate the width for padding based on the binary representation of 'number'
    width = len(bin(number)) - 2  # Subtract 2 to ignore the "0b" prefix
    
    # Loop through all numbers from 1 to 'number'
    for i in range(1, number + 1):
        # Prepare the four representations (decimal, octal, hexadecimal, binary)
        decimal = str(i)
        octal = oct(i)[2:]  # Remove the '0o' prefix
        hexadecimal = hex(i)[2:].upper()  # Remove the '0x' prefix and make it uppercase
        binary = bin(i)[2:]  # Remove the '0b' prefix
        
        # Print all four representations with appropriate width formatting
        print(f"{decimal.rjust(width)} {octal.rjust(width)} {hexadecimal.rjust(width)} {binary.rjust(width)}")

# Sample input
n = int(input())
print_formatted(n)
