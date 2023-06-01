#Aluno: Guilherme Garcia Gloor 
# Automato Finito Deterministico

#Entrada dos dados
def entrada():
    alfabeto = input("Entre com o alfabeto: ").split(',')
    estados = input("Entre com os estados: ").split(',')
    estado_inicial = input("Entre com o estado inicial: ")
    estados_aceitacao = input("Entre com os estados de aceitação: ").split(',')

    transicoes = {}
    for estado in estados:
        transicoes[estado] = {}
        for simbolo in alfabeto:
            transicoes[estado][simbolo] = input(f"Delta({estado}, {simbolo}): ")

    palavra = input("Entre com a palavra a ser verificada: ")
    
    return alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, palavra


# função para Automato Finito Deterministico
def automatoFinitoDeterministico(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes, palavra):
    estado_atual = estado_inicial

    for simbolo in palavra:
        if simbolo not in alfabeto:
            return False

        if estado_atual not in transicoes or simbolo not in transicoes[estado_atual]:
            return False

        estado_atual = transicoes[estado_atual][simbolo]

    return estado_atual in estados_aceitacao

# print do resultado para verificar se a palavra é aceita ou não pelo Automato
def printResultado(resultado):
    if resultado:
        print("\n")
        print("palavra aceita pelo automato! ")
        print("\n")
    else:
        print("\n")
        print("palavra rejeitada pelo automato! ")
        print("\n")

def exibirTabelaTransicao(estados, alfabeto, transicoes):
    print("\n----- Tabela de Transição -----")
    # Cabeçalho da tabela
    header = "Estado " + " ".join(f"| {simbolo:^10}" for simbolo in alfabeto)
    print(header)
    print("-" * (len(header) + 1))

    # Corpo da tabela
    for estado in estados:
        row = f"{estado:<7}" + " ".join(f"| {transicoes[estado].get(simbolo, '-'):^10}" for simbolo in alfabeto)
        print(row)
        print("-" * (len(header) + 1))

# Função principal
def main():
    while True:
        print("----Autômato Finito Determinístico----")
        alfabeto, estados, estado_inicial, estados_aceitacao, transicoes, palavra = entrada()
        resultado = automatoFinitoDeterministico(estados, alfabeto, estado_inicial, estados_aceitacao, transicoes, palavra)

        exibirTabelaTransicao(estados, alfabeto, transicoes)
        print("\n")
        printResultado(resultado)
    
        opcao = input("Deseja executar novamente? (s/n): ")
        if opcao.lower() != 's':
            break

# Chamada da função principal
main()

