.data

.text
.globl main

main:
    li $a0, 5        # numero da stampare
    li $v0, 1        # syscall 1 = print integer
    syscall

    li $v0, 10       # syscall 10 = exit
    syscall