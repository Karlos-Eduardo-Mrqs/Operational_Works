from functions import FuncoesAgenda  # Certifique-se de que o nome do arquivo seja "functions.py"

def cabecalho():
    print("------------------MENU DE GERENCIAMENTO DE ALUNOS-----------------\n")
    print("1. Adicionar Aluno\n")
    print("2. Listar Alunos\n")
    print("3. Buscar Aluno\n")
    print("4. Remover Aluno\n")
    print("5. Alterar Aluno\n")
    print("0. Sair\n")
    print("------------------------------------------------------------------\n")

def main():
    agenda = FuncoesAgenda("alunos.txt") # Cria uma instância da classe FuncoesAgenda
    
    funcoes = {0: agenda.sair, 1: agenda.cadastrar_aluno,2: agenda.listar_alunos, 
    3: agenda.buscar_aluno, 4: agenda.remover_aluno,5: agenda.alterar_aluno } # Define o mapeamento de códigos para funções

    while True:
        cabecalho()
        try:
            codigo = int(input("Escolha uma opção: "))
            if codigo in funcoes:
                funcao_selecionada = funcoes[codigo]
                if callable(funcao_selecionada):  # Verifica se o valor é uma função válida
                    funcao_selecionada()  # Chama a função correspondente ao código
                else:
                    print(f"A função associada ao código {codigo} não é válida.")
            else:
                print("Opção inválida!")
        except ValueError:
            print("Entrada inválida! Por favor, digite um número inteiro.")

if __name__ == "__main__":
    main()