import tkinter as tk

# Criar a janela principal
janela = tk.Tk()
janela.title("Minha Primeira Interface")
janela.geometry("400x300")

# Adicionar um label
label = tk.Label(janela, text="Olá, Tkinter!")
label.pack(pady=10)

# Adicionar uma entrada de texto
entrada = tk.Entry(janela)
entrada.pack(pady=10)

# Função para o botão
def mostrar_texto():
    texto_digitado = entrada.get()  # Pega o texto digitado
    label.config(text=f"Você digitou: {texto_digitado}")

# Adicionar um botão
botao = tk.Button(janela, text="Clique Aqui", command=mostrar_texto)
botao.pack(pady=10)

# Iniciar o loop principal
janela.mainloop()