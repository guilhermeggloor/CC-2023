#leia a e b
addi $v0,$zero,5
syscall
add $s0,$zero,$v0

addi $v0,$zero,5
syscall
add $s1,$zero,$v0

#alocar array, V, de palavras com b+1 elementos
#--calcular o tamanho do array em bytes (guardar em $a0)
addi $t0,$zero,4
addi $a0,$s1,1
mult $a0,$t0
mflo $a0 
addi $v0,$zero,9
syscall
add $s2,$zero,$v0
#V[0] = 1;
addi $t1,$zero,1
sw $t1,0($s2)
#V[1] = a;
sw $s0,4($s2)

#for(i=2;i<=b;++i)  ->>> i<=b  -> !(b<i)
addi $s3,$zero,2
for1:
slt $t2,$s1,$s3
bne $t2,$zero,fim_for1
#  V[i] = V[i-1]*b;
#--- i*4 ->>> $t2
mult $t0,$s3
mflo $t2
#--- V+(i*4) --->$t2
add $t2,$t2,$s2
#--- V[i-1]*b
lw $t3,-4($t2)
mult $t3,$s1
mflo $t3
sw $t3,0($t2)
addi $s3,$s3,1
j for1
fim_for1:

#for(i=0;i<=b;++i)
addi $s3,$zero,0
for2:
slt $t2,$s1,$s3
bne $t2,$zero,fim_for2
#  imprima V[i];
#--- i*4 ->>> $t2
mult $t0,$s3
mflo $t2
add $t2,$t2,$s2
lw $a0,0($t2)
addi $v0,$zero,1
syscall
addi $s3,$s3,1
j for2
fim_for2:
