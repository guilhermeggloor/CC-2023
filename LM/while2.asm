addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

inicio_while:

sub $a0, $s0, $s1
add $v0, $zero, 1
syscall

addi $s0, $s0, -1
slt $t1, $s0, $s1
bne $zero, $t1, fim_while
j inicio_while

fim_while:
add $v0, $zero, 10
syscall

