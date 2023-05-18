addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

inicio_while:
beq $zero, $s0, fim_while
add $v0, $zero, 1
add $a0, $zero, $s0
syscall

add $v0, $zero, 11
addi $a0, $zero, 10
syscall

addi $s0, $s0, -1
j inicio_while

fim_while:
add $v0, $zero, 10
syscall
                                                                                                                                                                                                                  
