# while(a >= b) -> while(!(a < b))

WHILE: 

slt $t0, $s0, $s1
bne $t0, $zero, FIM_WHILE
j WHILE

FIM_WHILE
