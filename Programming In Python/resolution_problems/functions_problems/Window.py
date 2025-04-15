from tkinter import *
def ClickTheButton():
    print("The Button is clicked !");

Window = Tk();
Content = Label(master= Window, text= "Welcome World !" );
Content.pack();
Button = Button(master = Window, text = 'Click', command = ClickTheButton)
Button.pack()
Window.mainloop();