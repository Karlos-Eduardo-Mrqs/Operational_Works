import datetime;
AnoAtual = datetime.date.today();
AnoDoUsuario = input("Digite o seu dia de nascimento [dia/mes/ano]:");
Dia,Mes,Ano = AnoDoUsuario.split("/");  
Idade =  AnoAtual.year - int(Ano) ;

MesMaior = bool( int(Mes) > AnoAtual.month );
MesIgual = bool( int(Mes) == AnoAtual.month ) ;
DiaMaior = bool( int(Ano) > AnoAtual.day) ;
DiaIgual = bool( int(Ano) == AnoAtual.year);

if MesMaior:
    Idade -=1;
elif MesIgual:
    if DiaMaior:
        Idade -=1;
    elif DiaIgual:
        print("Feliz Aniversário ! ")

print(f"Você atualmente tem {Idade} anos  ! ");