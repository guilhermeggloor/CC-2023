# Calcular a media de 4 inteiros
# (arrendodamento truncado - vulgo piso) 
# Retornar o maior entre 4 inteiros

addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero,5
syscall
add $s1, $zero, $v0

addi $v0, $zero, 5
syscall
add $s2, $zero, $v0

addi $v0, $zero,5
syscall
add $s3, $zero, $v0

#somandos os 4 numeros
add $t0, $s0, $s1
add $t1, $s2, $s3
add $t2, $t0, $t1

add $t5, $zero, 4
div $t2, $t5
mflo $t2

addi $v0, $zero, 10
syscall