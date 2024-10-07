class Televisao:
    def __init__(self, pcanal, min, max):
        self.canal = pcanal
        self.cmin = min
        self.cmax = max

    def muda_canal_para_baixo(self):
        self.canal -= 1

    def muda_canal_para_cima(self):
        self.canal += 1

tv1 = Televisao(2 , 2,  10 )
print(f"Canal Sintonizado: ",tv1.canal)

print(f"Mudando canal para cima")
for x in  range (1,20):
    tv1.muda_canal_para_cima()
    print(f"Canal Sintonizado: ",tv1.canal)

tv2 = Televisao(10, 2, 10)
print(f"Canal Sintonizado: ",tv2.canal)
print(f"Mudando canal para baixo")
for x in  range (1,20):
    tv2.muda_canal_para_baixo()
    print(f"Canal Sintonizado: ",tv2.canal)