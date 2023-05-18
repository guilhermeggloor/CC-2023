 #Suponha que os registradres $s0 - $s6 estão ocupados e o registrador $s7
 #está mapeado para a variável a. Compile a exp C: a = b - c + (d + e)
 # leia b,c,d,e

addi $sp, $sp, -16
sw
add $t0, $s3, $s4
sub $t1, $s1, $s2
addi $s0, $t1, $t0



 addi $v0, $zero, 5
 syscall
 # o valor lido estora em $v0

