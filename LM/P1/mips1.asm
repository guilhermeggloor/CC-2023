# leia a
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0
#if (a > 10)
addi $t0, $zero, 10
slt $t1, $t0, $s0
beq $t1, $zero, else
#   imprima a
addi $v0, $zero, 1
add $a0, $zero, $s0
syscall
j fim_else
#else 
else:
#   imprima 10
addi $v0, $zero, 1
addi $a0, $zero, 10
syscall
fim_else:
