import os

def clear_screen():
    if os.name == 'nt':
        os.system('cls')  
    else:
        os.system('clear')

def CreateAll(Cont_Quests):
    clear_screen()
    Answers = []
    for I in range(Cont_Quests):
        Answer = input(f"Digite a resposta da questão número {I+1} (A,B,C,D,E): ")
        Answers.append(Answer)
    return Answers

def Simulation(Cont_Quests, Cont_Students, Template):
    AceptyStuds = [0] * Cont_Students
    AceptyLetters = ["A", "B", "C", "D", "E"]
    for Student in range(Cont_Students):
        print(f"Aluno Número: {Student + 1}")
        clear_screen()
        for Question in range(Cont_Quests):
            Question_Template = Template[Question]
            print(f"Questão número {Question + 1}:")
            for I in range(len(AceptyLetters)):
                print(f"Letra: {AceptyLetters[I]})")
            Answer_Study = input("Digite sua resposta para esta questão (A,B,C,D,E): ")
            if Answer_Study in AceptyLetters:
                CorrectQuestion = (Answer_Study == Question_Template)
            if CorrectQuestion:
                AceptyStuds[Student] += 1
            else:
                print("Resposta inválida. Responda com A, B, C, D ou E.")
    AceptyStuds.sort(reverse=True)
    Rank(AceptyStuds)

def Rank(Acepty):
    Size = len(Acepty)
    for I in range(Size):
        print(f"{I + 1}º Aluno: {Acepty[I]} questões corretas")

Cont_Quests = int(input("Quantas questões o seu questionário tem? "))
Cont_Students = int(input("Quantos alunos têm o questionário? "))
Template = CreateAll(Cont_Quests)
Simulation(Cont_Quests, Cont_Students, Template)