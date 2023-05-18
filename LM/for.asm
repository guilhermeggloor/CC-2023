add $s0, $zero, $zero

inicio_for:
slti $t0, $s0, 10
beq $t0, $s0, fim_for
add $v0, $zero, 1
add $a0, $zero, $s0
syscall
addi $s0, $s0, 1
j inicio_for

fim_for:
              
