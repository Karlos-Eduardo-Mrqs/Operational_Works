class Calc:
    def __init__(self,height:float,base:float)->None:
        self.height = height;
        self.base = base;
        self.areaCalc = self.Area();
        self.perimeterCalc = self.Perimeter();

    def Area(self) -> float:
        return self.base*self.height;
    
    def Perimeter(self) -> float:
        return 2*(self.base + self.height);
 
if __name__ == 'main':
    Room1 = Calculo(4.0,180);
    Room2 = Calculo(3.0,150);
    Places = [Room1, Room2] ;
    for place in Places :
        print(f"The room has {place.Area()} m² of Area and {place.Perimeter()} m of perimeter");