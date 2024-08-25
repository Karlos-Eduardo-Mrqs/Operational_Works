import os

def Clean():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def Replaces(Letter, Word, Simbol):
    Simbols = list(Simbol)
    for index, Char in enumerate(Word):
        if Char == Letter:
            Simbols[index] = Letter
    return ''.join(Simbols) 

def EndGame(Simbol, Word):
    if "_" not in Simbol:
        print("Congratulations! You guessed the word!")
    else:
        print(f"Game over! The word was: {Word}")

Word = input('Digit the word to begin: ').upper()
Simbol = "_" * len(Word)
Chances = 3

while Chances > 0 and "_" in Simbol:
    Clean()
    print("Hangman Game!")
    print(f"You have {Chances} chances left.")
    print(Simbol)
    Letter = input("Guess a letter: ").upper()
    if Letter in Word:
        Simbol = Replaces(Letter, Word, Simbol)
    else:
        Chances -= 1  

Clean()
EndGame(Simbol, Word)