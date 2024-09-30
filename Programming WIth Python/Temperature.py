UnitTemperature = [0] * 3;
Temperature = input("Digite a unidade de temperatura [Celsius|Kelvin|Fahrenheit], e o valor da temperatura: ").upper();
Data = Temperature.split(",");
Data[0] = Data[0].strip() ; 
Data[1] = Data[1].strip() ;
match Data[0]:
    case 'CELSIUS':
        UnitTemperature[0] = float(Data[1])  ;
        UnitTemperature[1] = UnitTemperature[0] + 273.15  ;
        UnitTemperature[2] = UnitTemperature[0] * (9/5) + 32 ;
    case 'KELVIN':
        UnitTemperature[1] = float(Data[1]);  
        UnitTemperature[0] = UnitTemperature[1] - 273.15;  
        UnitTemperature[2] = (UnitTemperature[1] - 273.15) * (9/5) + 32;  
    case 'FAHRENHEIT':
        UnitTemperature[2] = float(Data[1]);
        UnitTemperature[0] = (UnitTemperature[2] - 32) * (5/9); 
        UnitTemperature[1] = UnitTemperature[0] + 273.15;  
    case _:
        print("Unidade de temperatura inválida!");
        exit();

print(f"Temperatura em Celsius: {UnitTemperature[0]:.2f}°C");
print(f"Temperatura em Kelvin: {UnitTemperature[1]:.2f}ºK");
print(f"Temperatura em Fahrenheit: {UnitTemperature[2]:.2f}°F");