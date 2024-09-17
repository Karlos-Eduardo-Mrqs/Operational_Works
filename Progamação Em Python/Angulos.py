from math import sin,cos,tan,radians

Angulo = int(input("Insert one angle(0º until 360º):"));
Angulo_Sin = int(sin(radians(Angulo)));
Angulo_Cos= int(cos(radians(Angulo)));
Angulo_Tan = int(tan(radians(Angulo)));
print(f"{Angulo} º =  {Angulo_Sin} Sen | {Angulo} º = {Angulo_Cos} Con | {Angulo} º = {Angulo_Tan} Tan ");