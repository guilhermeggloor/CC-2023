addi $v0, $zero, 5
syscall

add $s0, $zero, $v0

slt $t0, $zero, $s0
beq $t0, $zero, fim_if

addi $v0, $zero, 1
addi $a0, $zero, 0
syscall

fim_if:
addi $v0, $zero, 10
syscall

