#Aluno: Guilherme Garcia Gloor 
# Automato Finito Deterministico

def entrada():
    alfabeto = input("Entre com o alfabeto: ").split(',')
    estados = input("Entre com os estados: ").split(',')
    estado_inicial = input("Entre com o estado inicial: ")
    estado_aceitacao = input("Entre com os estados de aceitação: ").split(',')

    transicoes = {}
    for estado in estados:
        transicoes[estado] = {}
        for simbolo in alfabeto:
            transicoes[estado][simbolo] = input(f"Delta({estado}, {simbolo}): ")

    palavra = input("Entre com a palavra a ser verificada: ")
    
    return alfabeto, estados, estado_inicial, estado_aceitacao, transicoes, palavra


def automatoFinitoDeterministico(estados, alfabeto, estado_inicial, estado_aceitacao, transicoes, palavra):
    estado_atual = estado_inicial

    for simbolo in palavra:
        if simbolo not in alfabeto:
            return False

        if estado_atual not in transicoes or simbolo not in transicoes[estado_atual]:
            return False

        estado_atual = transicoes[estado_atual][simbolo]

    return estado_atual in estado_aceitacao


def printResultado(resultado):
    if resultado:
        print("\n")
        print("palavra aceita pelo automato! ")
    else:
        print("\n")
        print("palavra rejeitada pelo automato! ")


# Função principal
def main():
    alfabeto, estados, estado_inicial, estado_aceitacao, transicoes, palavra = entrada()
    resultado = automatoFinitoDeterministico(estados, alfabeto, estado_inicial, estado_aceitacao, transicoes, palavra)
    printResultado(resultado)


# Chamada da função principal
main()
