addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

addi $v0, $zero, 5
syscall

add $s2, $zero, $v0

slt $t0, $s0, $s1
slt $t1, $s2, $s0
and $t0, $t0, $t1
beq $t0, $zero, fim_if

addi $v0, $zero, 1
addi $a0, $zero, 0
syscall

fim_if:
addi $v0, $zero, 10
syscall

