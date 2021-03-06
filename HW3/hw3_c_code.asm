# /* Function to calculate x raised to the power y */
# int power(int x, unsigned int y)
# {
# if( y == 0) return 1; cond 1
# else if (y%2 == 0) return power(x, y/2)*power(x, y/2); cond 2
# else return x*power(x, y/2)*power(x, y/2); cond 3
# }
# TODO: Add fuctionality when for the tertiary condition

# Macro : mult_load($arg0, $arg1, $arg2, $tmp)
# Usage : mult_load(<store values>, <mult value 1>, <mult value 2>, <temp register to store hi>)
.macro 	mult_load($arg0, $arg1, $arg2, $tmp)
mult	$arg1, $arg2
mflo	$arg0
mfhi	$tmp
or	$arg0, $arg0, $tmp
.end_macro

# Macro : read_integer(<$reg1>)
# Usage : read_integer(<register to store integer>)
.macro	read_integer($reg1)
move	$t0, $v0
li	$v0, 5
syscall
move	$reg1, $v0
move	$v0, $t0
.end_macro

# Macro : print_string($str)
# Usage : print_string(<string to print>)
.macro	print_string($str)
move	$t0, $a0
la	$a0, $str
li	$v0, 4
syscall
move	$a0, $t0
.end_macro

.data
str1: 	.asciiz 	"Enter Base: "
str2:	.asciiz		"Enter Exponent: "

.text
.globl main
main: 
print_string(str1)
read_integer($a0)
print_string(str2)
read_integer($a1)
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
addi	$ra, $ra, 4
add	$sp, $sp, 4
add 	$fp, $sp, 4
j	restore_and_return

cond_3:
addi	$sp, $sp, -12
sw	$ra, 0($sp)
sw	$a1, 4($sp)
addi	$fp, $sp, 12
jal 	power
sw	$v0, 8($sp)
jal	power
lw	$t0, 8($sp)
mult_load	$v0, $v0, $t0, $t1
mult_load	$v0, $v0, $a0, $1
lw	$ra, 0($sp)
lw	$a1, 4($sp)
addi	$sp, $sp, 12
addi	$fp, $sp, 12
jr	$ra
