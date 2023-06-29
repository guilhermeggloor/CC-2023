addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

slt $t0, $s1, $s0
beq $t0, $zero, else

addi $v0, $zero, 1
addi $a0, $zero, 0
syscall

beq $s1, $s0, fim_if

else:
addi $v0, $zero, 1
addi $a0, $zero, 1

addi $v0, $zero, 10
syscall

fim_if:
addi $v0, $zero, 10
syscall
