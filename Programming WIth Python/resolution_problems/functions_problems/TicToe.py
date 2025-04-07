import tkinter as tk
from tkinter import messagebox
import random

# Função para verificar se há um vencedor
def check_winner(board, player):
    for i in range(3):
        if all([cell == player for cell in board[i]]):  # Verificar linha
            return True
        if all([board[j][i] == player for j in range(3)]):  # Verificar coluna
            return True
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:  # Diagonal principal
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:  # Diagonal secundária
        return True
    return False

# Função para verificar se o tabuleiro está cheio (empate)
def is_board_full(board):
    return all(cell != " " for row in board for cell in row)

# Função para realizar a jogada da máquina (simples estratégia de movimento aleatório)
def ai_move(board):
    empty_cells = [(i, j) for i in range(3) for j in range(3) if board[i][j] == " "]
    if empty_cells:
        return random.choice(empty_cells)
    return None

# Função para iniciar o jogo
class TicTacToe:
    def __init__(self, root, mode, player_choice):
        self.root = root
        self.root.title("Jogo da Velha")

        # Estilo de fundo e cor dos botões
        self.root.configure(bg="#e0f7fa")

        # Definir o modo de jogo (contra o jogador ou contra a máquina) e o símbolo do jogador
        self.mode = mode
        self.players = ["X", "O"]
        self.player_choice = player_choice
        self.turn = 0 if self.player_choice == "X" else 1  # Controla a vez do jogador
        self.board = [[" " for _ in range(3)] for _ in range(3)]

        # Criando os botões do tabuleiro (9 botões)
        self.buttons = [[None for _ in range(3)] for _ in range(3)]
        for i in range(3):
            for j in range(3):
                self.buttons[i][j] = tk.Button(self.root, text=" ", font=("Arial", 40), width=5, height=2,
                                               command=lambda i=i, j=j: self.play_move(i, j), bg="white", relief="raised")
                self.buttons[i][j].grid(row=i, column=j, padx=5, pady=5)

        # Barra de status
        self.status_label = tk.Label(self.root, text=f"Vez do jogador {self.players[self.turn]}", font=("Arial", 14), bg="#e0f7fa")
        self.status_label.grid(row=3, column=0, columnspan=3, pady=20)

        # Botão de reiniciar
        self.restart_button = tk.Button(self.root, text="Reiniciar Jogo", font=("Arial", 14), command=self.reset_game, state=tk.DISABLED)
        self.restart_button.grid(row=4, column=0, columnspan=3)

        # Se for contra a máquina, vamos fazer a jogada da máquina
        if self.mode == "AI" and self.turn == 1:
            self.ai_turn()

    # Função para realizar a jogada
    def play_move(self, i, j):
        if self.board[i][j] == " ":
            self.board[i][j] = self.players[self.turn]
            self.buttons[i][j].config(text=self.players[self.turn])

            # Verificar se o jogador atual ganhou
            if check_winner(self.board, self.players[self.turn]):
                self.status_label.config(text=f"Jogador {self.players[self.turn]} venceu!")
                self.restart_button.config(state=tk.NORMAL)
                self.root.after(2000, self.show_winner)  # Espera 2 segundos para mostrar o vencedor
                return

            # Verificar se deu empate
            if is_board_full(self.board):
                self.status_label.config(text="Empate!")
                self.restart_button.config(state=tk.NORMAL)
                self.root.after(2000, self.show_winner)  # Espera 2 segundos para mostrar empate
                return

            # Trocar de jogador
            self.turn = 1 - self.turn  # Se for 0, passa para 1 e vice-versa
            self.status_label.config(text=f"Vez do jogador {self.players[self.turn]}")

            # Se for contra a máquina, a máquina faz a próxima jogada após um pequeno atraso
            if self.mode == "AI" and self.turn == 1:
                self.root.after(1000, self.ai_turn)  # Atraso de 1 segundo para simular o tempo da máquina

    # Função da jogada da máquina
    def ai_turn(self):
        move = ai_move(self.board)
        if move:
            i, j = move
            self.board[i][j] = self.players[self.turn]
            self.buttons[i][j].config(text=self.players[self.turn])

            # Verificar se a máquina ganhou
            if check_winner(self.board, self.players[self.turn]):
                self.status_label.config(text="A Máquina venceu!")
                self.restart_button.config(state=tk.NORMAL)
                self.root.after(2000, self.show_winner)  # Espera 2 segundos para mostrar o vencedor
                return

            # Verificar se deu empate
            if is_board_full(self.board):
                self.status_label.config(text="Empate!")
                self.restart_button.config(state=tk.NORMAL)
                self.root.after(2000, self.show_winner)  # Espera 2 segundos para mostrar empate
                return

            # Trocar de jogador
            self.turn = 1 - self.turn
            self.status_label.config(text=f"Vez do jogador {self.players[self.turn]}")

    # Função para reiniciar o jogo
    def reset_game(self):
        self.board = [[" " for _ in range(3)] for _ in range(3)]
        for i in range(3):
            for j in range(3):
                self.buttons[i][j].config(text=" ", bg="white")

        self.turn = 0 if self.player_choice == "X" else 1  # Resetar para o jogador escolhido começar
        self.status_label.config(text=f"Vez do jogador {self.players[self.turn]}")
        self.restart_button.config(state=tk.DISABLED)

    # Função para mostrar o vencedor e retornar à tela inicial
    def show_winner(self):
        messagebox.showinfo("Fim de Jogo", f"O vencedor foi o {self.players[self.turn]}")
        self.root.destroy()  # Fecha a janela atual
        choose_mode()  # Retorna à tela inicial

# Função para a tela de escolha do modo de jogo e símbolo
def choose_mode():
    window = tk.Tk()
    window.title("Escolha o Modo de Jogo")
    window.configure(bg="#f0f8ff")

    label = tk.Label(window, text="Jogo Da Velha", font=("Verdana", 30), bg="#f0f8ff")
    label.pack(pady=15)

    label = tk.Label(window, text="Escolha o modo de jogo", font=("Arial", 18), bg="#f0f8ff")
    label.pack(pady=20)

    # Botões para escolher o modo
    player_button = tk.Button(window, text="Jogar com Jogador", font=("Arial", 14), command=lambda: start_game(window, "Player"))
    ai_button = tk.Button(window, text="Jogar contra a Máquina", font=("Arial", 14), command=lambda: start_game(window, "AI"))

    player_button.pack(pady=10)
    ai_button.pack(pady=10)

    window.mainloop()

# Função para a tela de escolha do símbolo
def choose_symbol(mode):
    window = tk.Tk()
    window.title("Escolha seu Símbolo")
    window.configure(bg="#f0f8ff")

    label = tk.Label(window, text="Escolha seu símbolo", font=("Verdana", 30), bg="#f0f8ff")
    label.pack(pady=15)

    # Botões para escolher o símbolo
    x_button = tk.Button(window, text="Escolher X", font=("Arial", 14), command=lambda: start_game_with_symbol(window, mode, "X"))
    o_button = tk.Button(window, text="Escolher O", font=("Arial", 14), command=lambda: start_game_with_symbol(window, mode, "O"))

    x_button.pack(pady=10)
    o_button.pack(pady=10)

    window.mainloop()

# Função para iniciar o jogo após a escolha do símbolo
def start_game_with_symbol(window, mode, symbol):
    window.destroy()
    root = tk.Tk()
    game = TicTacToe(root, mode, symbol)
    root.mainloop()

# Função para iniciar o jogo após a escolha do modo
def start_game(window, mode):
    window.destroy()
    choose_symbol(mode)  # Chama a tela de escolha do símbolo

if __name__ == "__main__":
    choose_mode()
