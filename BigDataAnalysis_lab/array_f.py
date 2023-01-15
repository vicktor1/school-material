import array
a = array.array('i', [1, 2, 3])
for i in a:
	print(i, end='')  		# output : 1, 2, 3
print()

a = array.array('i', [1, 2, 'string']) # output: TypeError: an integer is regquired (got type str)
a = [1, 2, 'string']
for i in a:
	print(i, end='')
