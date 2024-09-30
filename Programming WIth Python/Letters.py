simbols = ["@","#","&","*","/","?","!","$","%",".",":"]
vowels = ["A","E","I","O","U"];
phrase = input("Digit one phrase:").upper();
counts = [0] * 3; 
for letter in phrase:
    if (letter in vowels) :
        counts[0] += 1;
    elif (letter.isalpha()):
        counts[1] += 1;
    elif (letter in simbols):
        counts[2] += 1;

print("Your phrase have {} vowels, {} consonants and {} symbols !".format(counts[0],counts[1],counts[2]));