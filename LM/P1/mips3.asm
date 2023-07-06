# leia a,b, c
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0

addi $v0, $zero, 5
syscall
add $s2, $zero, $v0

#if (b >= a && b <= c) ->> !(b < a) && !(c < b)
slt $t0, $s1, $s0
slt $t1, $s2, $s1
or $t2, $t0, $t1
bne $t2, $zero, else
#   imprima 1
addi $v0, $zero, 1
addi  $a0, $zero, 1
syscall
j fim_else
#else 
else:
#   imprima b
addi $v0, $zero, 1
addi $a0, $zero, 0
syscall
fim_else:
