import random  # Biblioteca Para Números Randomicos
import os  # Biblioteca Para O SO(Sistema Operacional) Limpar A Tela

Contatos = []  # Lista Contatos

# Função De Criar Contatos
def AdicionarContato():
    ContatoInvalido = True;  # Inicializa como True para entrar no loop
    while ContatoInvalido:  # Enquanto For Inválido
        print("Criando Contato!");    
        nome = input("Digite o nome do contato: ").strip();  # Digita o nome do contato sem espaço em branco
       
        # Validação do nome
        if not nome:
            print("Nome não pode ser vazio. Tente novamente.");
            continue;
       
        telefone = input(f"Digite o número do {nome}: (ddd) ").strip();  # Digita o nome do contato sem espaço em branco
         
        if not telefone.isdigit() or len(telefone) < 10:  # Verifica se o telefone é um digito ou se tem no mínimo dez digitos
            print("Número de telefone inválido. Deve conter apenas dígitos e ter pelo menos 10 caracteres. Tente novamente.");
            continue;
       
        num_id = random.randint(1, 100000);  # Gera um id(identificação) com números entre 1(um) até 100000(Cem mil)  
        while any(contato['id'] == num_id for contato in Contatos):  # Verifica se a id gerada já existe, Se gerar outra igual, ele repete a criação novamente !
            num_id = random.randint(1, 100000);  # Gera um id(identificação) nova com números entre 1(um) até 100000(Cem mil)
       
        NovoContato = {"id": num_id, "nome": nome, "telefone": telefone};  # Armazena um objeto chamado novo contato, com a id, telefone e nome !    
        Contatos.append(NovoContato);  # Adiciona na lista o objeto novo contato
        print("Contato adicionado com sucesso!\n");
       
        ContatoInvalido = False;  # Encerra o looping, quando tudo ocorrer como planejado

# Função De Exibir Contatos
def IlustrarContato():
    if not Contatos:  # Se não possuem contatos na lista !
        print("Não temos nenhum contato!");
    print("Ilustrando Contatos!");
    print("-----------------------------------------------------------------------------");
    for Contato in Contatos:
        print(f"ID: {Contato['id']}, Nome: {Contato['nome']}, Telefone: {Contato['telefone']}");
        print("-----------------------------------------------------------------------------");

# Função De Alterar Contatos
def AlterarContato():
    LimparTela()
    IlustrarContato()

    # Verifica se há contatos disponíveis
    if not Contatos:
        print("Nenhum contato para alterar.")
        return

    while True:  # Loop para permitir múltiplas tentativas de alteração
        try:
            # Pede o ID do contato que será alterado
            id_contato = int(input("Digite o ID do contato que deseja alterar: "))
            # Busca o contato pelo ID fornecido
            contato_selecionado = None
            for contato in Contatos:
                if contato['id'] == id_contato:
                    contato_selecionado = contato
                    break

            # Se o contato não for encontrado
            if contato_selecionado is None:
                print("ID não encontrado. Tente novamente.")
                continue  # Retorna ao início do loop para nova tentativa

            # Exibe opções de alteração
            print(f"\n1. Nome: {contato_selecionado['nome']} | 2. Telefone: {contato_selecionado['telefone']}")
            item = int(input("Digite o item que deseja alterar (1 para Nome, 2 para Telefone): "))

            # Opções de alteração usando match case
            match item:
                case 1:
                    novo_nome = input("Digite o novo nome: ")
                    contato_selecionado['nome'] = novo_nome
                    print("Nome atualizado com sucesso!")

                case 2:
                    novo_telefone = input("Digite o novo telefone: ")
                    # Verificação básica para o número de telefone
                    if novo_telefone.isdigit() and len(novo_telefone) >= 10:
                        contato_selecionado['telefone'] = novo_telefone
                        print("Telefone atualizado com sucesso!")
                    else:
                        print("Telefone inválido. Deve conter apenas dígitos e ter pelo menos 10 caracteres.")

                case _:
                    print("Opção inválida.")

            # Após uma atualização bem-sucedida, pergunta se deseja continuar alterando
            continuar = input("Deseja alterar outro contato? (s/n): ").strip().lower()
            if continuar != 's':
                break  # Sai do loop se não quiser continuar

        except ValueError:
            print("Entrada inválida. Digite um número.")

# Função De Deletar Contatos
def DeletarContato():
    LimparTela()  # Limpa a sua tela
    if not Contatos:  # Caso a lista esteja vazia
        print("Nenhum contato disponível para deletar.")
        return

    while True:  # Loop para permitir múltiplas tentativas de deleção
        IlustrarContato()  # Ilustra contatos
        try:
            id_contato = int(input("Digite o ID do contato que deseja deletar: "))  # Digita a id do contato a ser deletado
            contato_encontrado = None

            for Contato in Contatos:
                if Contato['id'] == id_contato:  # Quando o contato for encontrado
                    contato_encontrado = Contato
                    break

            if contato_encontrado:  # Contato encontrado?
                confirmar = input(f"Tem certeza que deseja deletar o contato {contato_encontrado['nome']} (s/n)? ")  # Pergunta se deseja deletá-lo
                if confirmar.lower() == 's':  # Se quiser deletá-lo
                    Contatos.remove(contato_encontrado)  # O contato será excluído da lista
                    print("Contato deletado com sucesso!")
                else:  # Senão
                    print("Exclusão cancelada.")
            else:  # Se não encontrar a ID
                print("ID não encontrado.")

            # Pergunta se deseja continuar deletando
            continuar = input("Deseja deletar outro contato? (s/n): ").strip().lower()
            if continuar != 's':
                break  # Sai do loop se não quiser continuar

        except ValueError:  # Caso a entrada seja inválida
            print("Entrada inválida! Digite um número válido.")

# Função De Buscar Contatos
def BuscarContato():
    
    print("Buscar contatos!");
    LimparTela();
    if not Contatos:  # Caso a lista esteja vazia
        print("Nenhum Contato Para Busca.");
        return;
    ContinueBusca = "S";
    while ContinueBusca in ['S', 'SIM']:
        contato_encontrado = None;  # Reset para cada nova busca
        try:
            TipoBusca = input("Deseja procurar o usuário pelo (nome, telefone ou id)?: ").lower();
            Dado = input("Digite o valor que deseja buscar: ").strip();

            # Executa a busca de acordo com o tipo
            match TipoBusca:
                case 'nome':
                    for Contato in Contatos:
                        if Contato['nome'].lower() == Dado.lower():
                            contato_encontrado = Contato;
                            break;
                case 'telefone':
                    for Contato in Contatos:
                        if Contato['telefone'] == Dado:
                            contato_encontrado = Contato;
                            break;
                case 'id':
                    try:
                        Dado = int(Dado);  # Converte para int
                        for Contato in Contatos:
                            if Contato['id'] == Dado:
                                contato_encontrado = Contato;
                                break;
                    except ValueError:
                        print("ID inválido! Digite um número.");
                        continue;
                case _:
                    print("Campo inválido!");
                    continue;

            # Exibe o contato encontrado ou uma mensagem de erro
            if contato_encontrado:
                print(f"ENCONTREI {contato_encontrado['nome']} com ID {contato_encontrado['id']} e telefone {contato_encontrado['telefone']}.");
            else:
                print("Contato não encontrado.");

            # Pergunta se deseja continuar a busca
            ContinueBusca = input("Deseja buscar mais alguém [S - sim | N - não]? ").strip().upper();
        except ValueError:
            print("Digite um valor válido!");

# Função De Sair Do Sistema
def Sair():
    if len(Contatos) > 0:  # Caso já possua um contato ou mais na lista
        print("ATENÇÃO! CASO SAIR, OS CONTATOS SERÃO APAGADOS!")
        TemCerteza = input("Tem certeza em sair do sistema [S - sim | N - nao] ?: ").lower()  # Pergunta se deseja sair           
        if TemCerteza in ['sim', 's']:
            print("Saindo do sistema ...")
            return True  # Indica que o usuário deseja sair
        else:
            print("Saída cancelada!")
            return False  # Indica que o usuário não deseja sair
    else:
        print("Nenhum contato para apagar. Saindo do sistema ...")
        return True  # Saída sem confirmação se não houver contatos

# Função De Limpar A Tela
def LimparTela():
    os.system('cls' if os.name == 'nt' else 'clear')  # Limpa a tela

# Função De Exibir as Funções Do Sistema
def Cabecalho():  
    print("-------- M E N U D E O P Ç Õ E S --------")
    print(" 1 . Adicionar Contato ")
    print(" 2 . Ilustrar  Contato ")
    print(" 3 . Alterar   Contato ")
    print(" 4 . Deletar   Contato ")
    print(" 5 . Buscar    Contato ")
    print(" 6 . Saindo Do Sistema ")
    print("-------- M E N U D E O P Ç Õ E S --------")

# Exibe a Tela Principal Do Usuário
def TelaPrincipal():
    while True:
        Cabecalho()  # Mostra as opções disponíveis a serem feitas
        try:
            opcao = int(input("Qual é a função que você deseja realizar ?: "))
            match opcao:  # escolha opção
                case 1:  # caso 1 Cria Contato
                    AdicionarContato()
                case 2:  # caso 2 Mostra Os Contatos
                    IlustrarContato()
                case 3:  # caso 3 Altera Os Contatos
                    AlterarContato()
                case 4:  # caso 4 Deleta Os Contatos
                    DeletarContato()
                case 5:  # caso 5 Busca Contato
                    BuscarContato()
                case 6:  # caso 6 Sai Do Sistema
                    if Sair():  # Verifica se o usuário deseja realmente sair
                        return  # Sai do loop e termina o programa
                case _:  # opção inválida
                    print("Opção inválida! Tente novamente.")
        except ValueError:  # caso de erro de conversão
            print("Entrada inválida. Digite um número!")

# Inicializa A Tela Principal
TelaPrincipal() # © Carlos Eduardo;