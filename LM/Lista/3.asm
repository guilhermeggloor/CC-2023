addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

add $s1, $zero, 10

inicio_while:
sub $a0, $s0, $s1
add $v0, $zero, 1
syscall

slt $t0, $s0, $s1
bne $zero, $t0, fim_while
j inicio_while

fim_while:
addi $v0, $zero, 10
syscall