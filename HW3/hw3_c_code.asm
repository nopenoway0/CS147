# /* Function to calculate x raised to the power y */
# int power(int x, unsigned int y)
# {
# if( y == 0) return 1; cond 1
# else if (y%2 == 0) return power(x, y/2)*power(x, y/2); cond 2
# else return x*power(x, y/2)*power(x, y/2); cond 3
# }
# TODO: Add fuctionality when for the tertiary condition

.text
.globl main
main:
addi	$a0, $zero, 2
addiu	$a1, $zero, 9
jal	power

# Prepare to print result
move	$a0, $v0
li	$v0, 1
syscall

# Terminate program
li	$v0, 10
syscall

# $a0 is x
# $a1 is y
power:
# if $a1 or y == 0
# sets result to 1, will change if other conditions are met
li	$v0, 1
beq	$a1, $zero, return_power
beq	$a1, 1, pre_cond	#Incorrect turns into 0, change for special case, rename pre_con to account for when 1 is hit

# Store return address, set frame pointer to top of stack
addi	$sp, $sp, -12
sw	$ra, 0($sp)
sw	$a0, 4($sp)
sw	$a1, 8($sp)
addi	$fp, $sp, 12

# Condition Test Hi remainder low quotient
li	$t0, 2
div	$a1, $t0
mflo	$a1
mfhi	$t0		# Already stored argument to stack so this works
addi	$sp, $sp, 4
beqz	$t0, cond_2	# cond 2 met
jal	cond_3

#-------------------------------------------#
j	restore_and_return		# Return with results stored in $v0

pre_cond:
move	$v0, $a0
j	return_power

return_power:
jr 	$ra

restore_and_return:
lw	$ra, 0($sp)
lw	$a0, 4($sp)
lw	$a1, 8($sp)
addi	$sp, $sp, 12
addi	$fp, $sp, 12
jr	$ra

# not implemented
cond_2:
addi	$sp, $sp, -4
sw	$ra, 0($sp)
add	$fp, $sp, 4
jal	power
mult	$v0, $v0
mflo	$v0
mfhi	$t0
or	$v0, $v0, $t0
lw	$ra, 0($sp)
addi	$ra, $ra, 4	# Will this skip the next instruction?
add	$sp, $sp, 4
add 	$fp, $sp, 4
j	restore_and_return

cond_3:
li	$a1, 1		# Temporary store to check if the values are proper
jr	$ra