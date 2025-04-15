from math import sin,cos,tan,radians

Angle = int(input("Insert one angle(0º until 360º):"));
Angle_Sin = int(sin(radians(Angle)));
Angle_Cos= int(cos(radians(Angle)));
Angle_Tan = int(tan(radians(Angle)));
print(f"{Angle} º =  {Angle_Sin} Sen | {Angle} º = {Angle_Cos} Con | {Angle} º = {Angle_Tan} Tan ");