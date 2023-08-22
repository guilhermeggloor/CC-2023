# int x, y //mapeia x em $s0 e y em $s1
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0
#imprima soma(x,y)				#usaremos $a0...$a3 p/ armazenar os argumentos (caso necessário também usamos a pilha para esse fim)
#>>> armazenar os argumentos			#usamos a instrução jal para saltar para a primeira instrução do procedimento
add $a0, $zero, $s0
add $a1, $zero, $s1
#>>> desvia para procedimento soma
jal soma
#>>> o valor retornado deve estar em $v0
add $t0, $zero, $v0
#>>> impressão
addi $v0, $zero, 1
add $a0, $zero, $t0
syscall

#EXIT
addi $v0, $zero, 10
syscall

soma:
#int soma(int a, int b) {
#  return a + b; 
add $v0, $a0, $a1
jr $ra
#} 
