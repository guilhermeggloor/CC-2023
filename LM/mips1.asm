# Guilherme Garcia Gloor
# RGM: 45535

.data
prompt_a0: .asciiz "Digite o valor de a0: "
prompt_r: .asciiz "Digite o valor de r: "
prompt_n: .asciiz "Digite o valor de n: "
prompt_result: .asciiz "Vetor resultante: "
newline: .asciiz "\n"

.text
.globl main

main:
    # Lê o valor de a0
    li $v0, 4
    la $a0, prompt_a0
    syscall
    li $v0, 5
    syscall
    move $t0, $v0   # $t0 <- a0

    # Lê o valor de r
    li $v0, 4
    la $a0, prompt_r
    syscall
    li $v0, 5
    syscall
    move $t1, $v0   # $t1 <- r

    # Lê o valor de n
    li $v0, 4
    la $a0, prompt_n
    syscall
    li $v0, 5
    syscall
    move $t2, $v0   # $t2 <- n

    # Aloca memória para o vetor
    sll $t3, $t2, 2   # $t3 <- n * 4 (tamanho de um inteiro)
    li $v0, 9
    move $a0, $t3
    syscall
    move $t4, $v0   # $t4 <- endereço base do vetor alocado

    # Preenche o vetor com a progressão aritmética
    move $t5, $t0   # $t5 <- a0
    addiu $t6, $t4, 0   # $t6 <- endereço atual do vetor
    li $t7, 0   # $t7 <- contador

loop:
    addiu $t7, $t7, 1   # Incrementa o contador
    sw $t5, ($t6)   # Armazena o valor atual no vetor
    move $t8, $t1   # Copia o valor de $t1 para $t8
    addu $t5, $t5, $t8   # $t5 <- $t5 + $t8 (próximo termo da progressão)
    addiu $t6, $t6, 4   # $t6 <- $t6 + 4 (avança para o próximo espaço no vetor)
    bne $t7, $t2, loop   # Salta para o início do loop se o contador != n

    # Imprime o vetor resultante
    li $v0, 4
    la $a0, prompt_result
    syscall

    move $t7, $t4   # $t7 <- endereço base do vetor
    li $t6, 0   # $t6 <- contador

print_loop:
    lw $a0, ($t7)   # Carrega o valor atual do vetor para impressão
    li $v0, 1
    syscall
    la $a0, newline   # Imprime uma nova linha
    li $v0, 4
    syscall
    addiu $t6, $t6, 1   # Incrementa o contador
    addiu $t7, $t7, 4   # $t7 <- $t7 + 4 (avança para o próximo elemento no vetor)
    blt $t6, $t2, print_loop   # Salta para o início do loop se o contador < n

    # Termina o programa
    li $v0, 10
    syscall
