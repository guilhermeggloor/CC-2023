# Aluno: GUilherme Garcia Gloor
# RGM: 45535

def epsilon_fechamento(afn, estados):
    pilha = list(estados)
    fechamento = list(estados)

    while pilha:
        estado = pilha.pop()

        if (estado, '') in afn['transicoes']:
            destinos = afn['transicoes'][(estado, '')]

            for destino in destinos:
                if destino not in fechamento:
                    fechamento.append(destino)
                    pilha.append(destino)

    return fechamento


def converter_afn_para_afd(afn):
    afn_estados = afn['estados']
    afn_alfabeto = afn['alfabeto']
    afn_transicoes = afn['transicoes']
    afn_estado_inicial = afn['estado_inicial']
    afn_estados_finais = afn['estados_finais']

    afd_estados = []
    afd_transicoes = {}
    afd_estado_inicial = epsilon_fechamento(afn, [afn_estado_inicial])
    afd_estados_finais = []

    pilha = [afd_estado_inicial]
    visitados = set()

    while pilha:
        conjunto = pilha.pop()
        visitados.add(tuple(conjunto))
        afd_estados.append(conjunto)

        if any(estado in afn_estados_finais for estado in conjunto):
            afd_estados_finais.append(conjunto)

        for simbolo in afn_alfabeto:
            destinos = []

            for estado in conjunto:
                if (estado, simbolo) in afn_transicoes:
                    destinos.extend(afn_transicoes[(estado, simbolo)])

            epsilon_destinos = epsilon_fechamento(afn, destinos)
            afd_transicoes[(tuple(conjunto), simbolo)] = epsilon_destinos

            if tuple(epsilon_destinos) not in visitados:
                pilha.append(epsilon_destinos)

    afd = {
        'estados': afd_estados,
        'alfabeto': afn_alfabeto,
        'transicoes': afd_transicoes,
        'estado_inicial': afd_estado_inicial,
        'estados_finais': afd_estados_finais
    }

    return afd


# Função para ler as entradas do usuário e criar o dicionário do AFN
def ler_entradas_usuario():
    print("---------Conversão AFN para AFD---------------")
    states = input("Informe os estados: ").split(",")
    alphabet = input("Informe o alfabeto: ").split(",")
    alphabet.append('')  # Adicionando o símbolo vazio ao alfabeto
    transitions = {}

    print("Informe as transições:")
    for state in states:
        for symbol in alphabet:
            next_states = input(f"Delta({state},{symbol}): ").split(",")
            transitions[(state, symbol)] = next_states

    start_state = input("Informe o estado inicial: ")
    accept_states = input("Informe o(s) estado(s) de aceitação: ").split(",")

    return {
        'estados': states,
        'alfabeto': alphabet,
        'transicoes': transitions,
        'estado_inicial': start_state,
        'estados_finais': accept_states
    }


# Leitura das entradas do usuário
afn = ler_entradas_usuario()

# Chamada da função para converter o AFN em AFD
afd = converter_afn_para_afd(afn)

# print dos resultados formatado
print("---------Resultado da Conversão---------")
print("Estados:")
for estado in afd['estados']:
    print(estado)

print("\nAlfabeto:")
print(afd['alfabeto'])

print("\nTransições:")
for transicao, destinos in afd['transicoes'].items():
    print(f"Delta({transicao[0]}, {transicao[1]}): {destinos}")

print("\nEstado Inicial:")
print(afd['estado_inicial'])

print("\nEstados Finais:")
for estado_final in afd['estados_finais']:
    print(estado_final)

print("\nConversão concluída com sucesso!")
