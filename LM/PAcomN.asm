# leia a0, r, n
addi $v0, $zero, 5
syscall
add $s0, $zero, $v0	#a0

addi $v0, $zero, 5
syscall
add $s1, $zero, $v0	#r

addi $v0, $zero, 5
syscall
add $s2, $zero, $v0	#n

# alocar um array com n palavras. 

sll $t0, $s2, 2  	#multiplicação por 4, usando shift lefht
addi $v0, $zero, 9
add $a0, $zero, $t0
syscall 

add $s3, $zero, $v0	#move para s3 o endereço inicial do array

#preencher array
addi $s4, $zero, 0	#cria a variável i=
addi $s5, $zero, $s0 	#cria variável ai - valor do termo i 
FOR_CALCULO: 
slti $t0, $s4, $s2 
bne $zero, $t0, FIM_CALCULO


#calculo do endreço de V[i]
add $t0, $zero, $s3
sll $t1, $s4, 2
add $t0, $t0, $t1


sw $s5, 0($t0)
addi $s4, $s4, 1
j FOR_CALCULO

FIM_FOR_CALCULO:

addi $s4, $zero, 0	#cria a variável i=
	 
FOR_IMP: 
slti $t0, $s4, $s2 
bne $zero, $t0, EXIT


#calculo do endreço de V[i]
add $t0, $zero, $s3
sll $t1, $s4, 2
add $t0, $t0, $t1

sw $s5, 0($t0)
addi $s4, $s4, 1
j FOR_CALCULO

