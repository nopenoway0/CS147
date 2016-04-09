# Implementation of hw5.c
.macro exit
	li	$v0, 10
	syscall
.end_macro

.data
.align 2
array1: .word 15 23 19 94 1995 22
array2: .word 0 0 0 0 0 0

.text
.globl main
main:
	la	$a0, array1
	la	$a1, 6
	jal	print_int_array
	exit
	
# a0 is address of the start of the array. a1 is the length	
print_int_array:
	move	$t0, $a1
	li	$t1, 0
	addi	$sp, $sp, -12
	sw	$v0, 0($sp)
	sw	$fp, 4($sp)
	sw	$a0, 8($sp)
	addi	$fp, $sp, 12
pa_loop:
	slt	$t2, $t1, $a1
	beqz	$t2, pa_loop_end
	sll	$t3, $t1, 2
	add	$t4, $t3, $a0
	lw	$t3, 0($t4)
	move	$a0, $t3
	li	$v0, 1
	syscall
	lw	$a0, 8($sp)
	addi	$t1, $t1, 1
	j	pa_loop
pa_loop_end:
	lw	$v0, 0($sp)
	lw	$fp, 4($sp)
	lw	$a0, 8($sp)
	addi	$sp, $sp, 12
	jr	$ra