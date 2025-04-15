
class Calc:
    def __init__(self, height: float, base: float) -> None:
        self.height = height
        self.base = base
        self.areaCalc = self.Area()
        self.perimeterCalc = self.Perimeter()

    def Area(self) -> float:
        return self.base * self.height

    def Perimeter(self) -> float:
        return 2 * (self.base + self.height)

Room1 = Calc(4.0, 180)
Room2 = Calc(3.0, 150)
Places = [Room1, Room2]
# Iterando sobre a lista e imprimindo os resultados
for place in Places:
    print(f"The room has {place.areaCalc} m² of area and {place.perimeterCalc} m of perimeter.")