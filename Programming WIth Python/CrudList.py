import random
import os

Contatos = []

def AdicionarContato():
    ContatoInvalido = True  # Inicializa como True para entrar no loop
    while ContatoInvalido:
        print("Criando Contato!")    
        nome = input("Digite o nome do contato: ").strip()
        
        # Validação do nome
        if not nome:
            print("Nome não pode ser vazio. Tente novamente.")
            continue
        
        telefone = input(f"Digite o número do {nome}: ").strip()
        
        if not telefone.isdigit() or len(telefone) < 10:
            print("Número de telefone inválido. Deve conter apenas dígitos e ter pelo menos 10 caracteres. Tente novamente.")
            continue
        
        num_id = random.randint(1, 100000)
        while any(contato['id'] == num_id for contato in Contatos):
            num_id = random.randint(1, 100000)
        
        NovoContato = {"id": num_id, "nome": nome, "telefone": telefone}    
        Contatos.append(NovoContato)
        print("Contato adicionado com sucesso!\n")
        
        ContatoInvalido = False  

def IlustrarContato():
    if not Contatos:
        print("Não temos nenhum contato!")
    else:
        print("     Ilustrando Contatos!")
        print("-----------------------------------------------------------------------------")
        for Contato in Contatos:
            print(f"ID: {Contato['id']}, Nome: {Contato['nome']}, Telefone: {Contato['telefone']}")
            print("-----------------------------------------------------------------------------")

def AlterarContato():
    LimparTela()
    IlustrarContato()

    if not Contatos:
        print("Nenhum contato para alterar.")
        return

    id_valida = False
    while not id_valida:  # Loop até que um ID válido seja inserido
        try:
            id_contato = int(input("Digite o ID do contato que deseja alterar: "))
            for Contato in Contatos:
                if Contato['id'] == id_contato:
                    id_valida = True
                    contato_selecionado = Contato
                    break
            if not id_valida:
                print("ID não encontrado. Tente novamente.")
        except ValueError:
            print("Entrada inválida! Digite um número.")
        
    # Exibir opções de alteração
    print(f"\n1. Nome do Contato: {contato_selecionado['nome']} | 2. Telefone do Contato: {contato_selecionado['telefone']}")
    
    try:
        item = int(input("Digite o item que deseja alterar (1 para Nome, 2 para Telefone): "))
        match item:
            case 1:
                novo_nome = input("Digite o novo nome: ")
                contato_selecionado['nome'] = novo_nome
                print("Nome atualizado com sucesso!")
            case 2: 
                novo_telefone = input("Digite o novo telefone: ")
                contato_selecionado['telefone'] = novo_telefone
                print("Telefone atualizado com sucesso!")
            case _:
                print("Opção inválida. Alteração cancelada.")
    except ValueError:
        print("Entrada inválida! Alteração cancelada.")

def DeletarContato():
    LimparTela()
    if not Contatos:
        print("Nenhum contato disponível para deletar.")
        return

    IlustrarContato()
    try:
        id_contato = int(input("Digite o ID do contato que deseja deletar: "))
        contato_encontrado = None
        for Contato in Contatos:
            if Contato['id'] == id_contato:
                contato_encontrado = Contato
                break
        
        if contato_encontrado:
            confirmar = input(f"Tem certeza que deseja deletar o contato {contato_encontrado['nome']} (s/n)? ")
            if confirmar.lower() == 's':
                Contatos.remove(contato_encontrado)
                print("Contato deletado com sucesso!")
            else:
                print("Exclusão cancelada.")
        else:
            print("ID não encontrado.")
    except ValueError:
        print("Entrada inválida! Digite um número válido.")

def LimparTela():
    os.system('cls' if os.name == 'nt' else 'clear')

def Cabecalho():
    print("-------- M E N U D E O P Ç Õ E S --------")
    print(" 1 . Adicionar Contato ")
    print(" 2 . Ilustrar  Contato ")
    print(" 3 . Alterar   Contato ")
    print(" 4 . Deletar   Contato ")
    print(" 5 . Saindo Do Sistema ")
    print("-------- M E N U D E O P Ç Õ E S --------")

def TelaPrincipal():
    while True:
        Cabecalho() # Mostra as opções disponíveis a serem feitas
        try:
            opcao = int(input("Qual é a função que você deseja realizar ?: "))
            match opcao: # escolha opção 
                case 1: # caso 1 Cria Contato 
                    AdicionarContato()
                case 2: # caso 2 Mostra Os Contatos 
                    IlustrarContato()
                case 3: # caso 3 Altera Os Contatos
                    AlterarContato()
                case 4: 
                    DeletarContato()
                case 5:
                    print("Saindo Do Sistema ...")
                    break
                case _:
                    print("Escolha Uma Opção Válida!")
        except ValueError:
            print("Entrada inválida! Digite um número.")

TelaPrincipal(); # Essa é a função principal