#leia a0, r, n
addi $v0,$zero,5
syscall
add $s0,$zero,$v0  #a0

addi $v0,$zero,5
syscall
add $s1,$zero,$v0  #r

addi $v0,$zero,5
syscall
add $s2,$zero,$v0  #n

#alocar um array com n palavras
sll $t0,$s2,2      #multiplicação por 4, usando shift lefht
addi $v0,$zero,9
add $a0,$zero,$t0
syscall

add $s3,$zero,$v0   #move para s3 o endereço inicial do array

#preencher array
addi $s4,$zero,0   #cria variavel i=0
add $s5,$zero,$s0  #cria variavel ai - valor do termo i
FOR_CALCULO:
slt $t0,$s4,$s2
beq $t0,$zero,FIM_FOR_CALCULO

#calculo do endereço de V[i]
add $t0,$zero,$s3
sll $t1,$s4,2
add $t0,$t0,$t1

sw $s5,0($t0)

#calcula proximo termo da PA
add $s5,$s5,$s1
#incrementa i
addi $s4,$s4,1
j FOR_CALCULO

FIM_FOR_CALCULO:
#impressão
addi $s4,$zero,0   #cria variavel i=0

FOR_IMP:
slt $t0,$s4,$s2
beq $t0,$zero,EXIT

#calculo do endereço de V[i]
add $t0,$zero,$s3
sll $t1,$s4,2
add $t0,$t0,$t1

addi $v0,$zero,1
lw $a0,0($t0)
syscall

addi $s4,$s4,1
j FOR_IMP
EXIT:

addi $v0,$zero,10
syscall