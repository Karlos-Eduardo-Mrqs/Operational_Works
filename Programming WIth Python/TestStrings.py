name = input("What's your name ?:");
print("Hello",name);

Upper = name.upper();
Lower = name.lower();
RemoveSpace = name.strip();
Locat = name.replace("","|");

print("Your name in UpperCase:",Upper);
print("Your name in LowerCase:",Lower);
print("Your name with no spaces:",RemoveSpace);
print("Your name with replaces:",Locat);
print("Your name with\n /n      :" + name);

First = "Hello";
Second = "For";
Third = "World";

Phrase = First + Second + Third;
print(Phrase);

Phrase = f"First + Second + Third + {name}";
print(Phrase);

Phrase = First + Second + Third + name;
print(Phrase);