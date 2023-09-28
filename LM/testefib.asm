#leia n
addi $v0, $zero, 5
syscall

#imprima fib(n) 
add $a0, $zero, $v0
jal fib

add $a0, $zero, $v0
addi $v0, $zero, 1
syscall

#exit
addi $v0, $zero, 10
syscall

fib:
addiu $sp, $s0, -12
sw $ra, 0($sp) 
sw $s0, 4($sp) 
sw $s1, 8($sp)

addiu $a0, $s0, 0
beq $0, $s0, done
addiu $t0, $0, 1
beq $t0, $s0, done

addiu $a0, $s0, -1
jal fib
addiu $s1, $v0, 0
addiu $a0, $s0, -2
jal fib
addu $v0, $v0, $s1
j fim

done: 
addu $v0, $0, $s0
j fim 

fim: 
lw $s1, 8($sp) 
lw $s0, 4($sp) 
lw $ra, 0($sp) 
addiu $sp, $sp, 12
jr $ra 
