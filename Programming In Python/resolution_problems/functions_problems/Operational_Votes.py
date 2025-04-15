import os
def Repeat(Continue):
    return Continue.upper() == "Y";

def Correct_Vote(One_Vote,Message):
    if One_Vote >= 0 and One_Vote <= 5 :
        Message = "Correct Vote ";
    else:
        Message = "Vote Again";
    return Message,One_Vote;

def Data(Sum_Votes,Operational_Systems):
    print(Operational_Systems,Sum_Votes)

Operational_Systems = ["Windows","Linux","Unix","Mac_Os","NetWare","Other"];
Length_OS = len(Operational_Systems);
Sum_Votes = [0] * Length_OS;
Message = "";
Voting = True;

while Voting:
    print(Message);
    for Index in range(Length_OS):
        print(f"[{Index}] {Operational_Systems[Index]}");
    One_Vote = int(input("Change One That Operational Systems :"));
    Correct_Vote(One_Vote,Message);    
    Sum_Votes[One_Vote] += 1 ;
    Continue = input("Have more people for voting [Y - yes | N - No]?:");
    Voting = Repeat(Continue);
Data(Sum_Votes,Operational_Systems);