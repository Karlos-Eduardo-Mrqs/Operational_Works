simbols = ["@","#","&","*","/","?","!","$","%",".",":"]
vowels = ["A","E","I","O","U"];
phrase = input("Digit one phrase:");
phrase = phrase.upper();
counts = [0] * 3; 
for letter in phrase:
    print(letter);
    if (letter in vowels) :
        counts[0] += 1;
        print("Simbols !"); 
    elif (letter in simbols):
        counts[2] += 1;
        print("Simbols !");
    else:
        counts[1] += 1;
        print("Consonants !");
print("Your phrase have {} vowels, {} consonants and {} simbols !".format(counts[0],counts[1],counts[2]));