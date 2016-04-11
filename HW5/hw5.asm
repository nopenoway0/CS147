# Implementation of hw5.c
.macro exit
	li	$v0, 10
	syscall
.end_macro

.data
.align 0
array1: .word 15 23 19 94 1995 22
array2: .word 0 0 0 0 0 0
array3: .byte 2 3 4 5 6 7
array4: .byte 3 2 1 4 2 3
space: .byte 32
newline: .byte 10

.text
.globl main
main:
	la	$a0, array1
	la	$a1, 6
	jal	print_int_array
	
	la	$a0, array2
	la	$a1, 6
	jal 	print_int_array
	
	la	$a1, array2
	la	$a0, array1
	la	$a2, 6
	la	$a3, 4
	jal	memmov

	la	$a0, array1
	la	$a1, 6
	jal	print_int_array
	
	la	$a0, array2
	la	$a1, 6
	jal 	print_int_array
	
	la	$a0, array3
	la	$a1, 6
	jal 	print_char_array
	
	la	$a0, array4
	la	$a1, 6
	jal 	print_char_array
	
	exit

# a0 source address, a1 dest address, a2 length, a3 size of elements	
memmov:
	addi	$sp, $sp, -8
	sw	$fp, 0($sp)
	
	beq	$a0, $a1, return
	move	$t0, $a0	# base source address
	move	$t1, $a1	# base dest address
	li	$t2, 0		# Counter
	
	slt	$t3, $t0, $t1
	bnez 	$t3, memmov_loop_2
memmov_loop_1:			# If Dest is greater, start at source and compare to dest baseline to prevent overlap
	slt	$t5, $t2, $a2
	beqz	$t5, return
	beq	$t0, $a1, return	# prevents overlap
	sll	$t4, $t2, 2
	add	$t0, $a0, $t4
	add	$t1, $a1, $t4
	lw	$t5, 0($t0)
	sw	$t5, 0($t1)
	addi	$t2, $t2, 1		# Increment Counter
	j	memmov_loop_1
	
memmov_loop_2:			# If source is greater, start at dest and compare to dest baseline to prevent overlap
	slt	$t5, $t2, $a2
	beqz	$t5, return
	beq	$t1, $a0, return	# prevents overlap
	sll	$t4, $t2, 2
	add	$t0, $a0, $t4
	add	$t1, $a1, $t4
	lw	$t5, 0($t0)
	sw	$t5, 0($t1)
	addi	$t2, $t2, 1		# Increment Counter
	j	memmov_loop_2
	
return:
	lw	$fp, 0($sp)
	addi	$sp, $sp, 8
	jr	$ra

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
	li	$v0, 11
	syscall
	
	lb	$a0, space
	li	$v0, 11
	syscall
	
	lw	$a0, 8($sp)
	addi	$t1, $t1, 1
	j	pa_loop
pa_loop_end:
	lb	$a0, newline
	li	$v0, 11
	syscall
	
	lw	$v0, 0($sp)
	lw	$fp, 4($sp)
	lw	$a0, 8($sp)
	addi	$sp, $sp, 12
	jr	$ra

# a0 is address of the start of the array. a1 is the length	
print_char_array:
	move	$t0, $a1
	li	$t1, 0
	addi	$sp, $sp, -12
	sw	$v0, 0($sp)
	sw	$fp, 4($sp)
	sw	$a0, 8($sp)
	addi	$fp, $sp, 12
pc_loop:
	slt	$t2, $t1, $a1
	beqz	$t2, pc_loop_end
	sll	$t3, $t1, 0
	add	$t4, $t3, $a0
	lb	$t3, 0($t4)
	
	move	$a0, $t3
	li	$v0, 11
	syscall
	
	lb	$a0, space
	li	$v0, 11
	syscall
	
	lw	$a0, 8($sp)
	addi	$t1, $t1, 1
	j	pc_loop
pc_loop_end:
	lb	$a0, newline
	li	$v0, 11
	syscall
	
	lw	$v0, 0($sp)
	lw	$fp, 4($sp)
	lw	$a0, 8($sp)
	addi	$sp, $sp, 12
	jr	$ra