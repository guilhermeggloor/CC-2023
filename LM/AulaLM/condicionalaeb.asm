addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

add $a0, $zero, $s0
add $s1, $zero, $s1

jal if

#>>> o valor retornado deve estar em $v0
add $t0, $zero, $v0

#>>> impressão
addi $v0, $zero, 1
add $a0, $zero, $t0
syscall

addi $v0, $zero, 10
syscall

if: 
slt $t0, $a0, $a1
beq $t0, $zero, fim_if
add $v0, $zero, $a1
jr $ra
fim_if: 
add $v0, $zero, $a0
jr $ra
