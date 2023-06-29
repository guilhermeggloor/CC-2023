addi $v0, $zero, 5
syscall

add $s0, $zero, $v0
add $s1, $zero, 33

slt $t1, $s0, $s1
beq $t1, $zero, fim_if

addi $v0, $zero, 1
addi $a0, $zero, 0
syscall

fim_if: 
addi $v0,$zero,1
addi $a0,$zero,1

addi $v0, $zero, 10
syscall