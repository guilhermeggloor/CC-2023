# leia a,b
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

#if (a >= b) -> !(a < b)
slt $t1, $s0, $s1
beq $t1, $zero, else
#   imprima a
addi $v0, $zero, 1
add  $a0, $zero, $s0
syscall
j fim_else
#else 
else:
#   imprima b
addi $v0, $zero, 1
add $a0, $zero, $s1
syscall
fim_else:
