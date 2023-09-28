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


