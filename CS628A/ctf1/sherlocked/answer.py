'''
Hope Sherlock Holms don't intercept this encrypted flag, 
because there are many things to deduce here!
'''

import random

def main():
	# my Code starts here
	encText = open('flag.enc', 'r').read()
	print(encText)
	encText = list(encText)
	
	ciphertext = []
	for index in range(len(encText)):
		if index%2==0:
			x = int(encText[index]+encText[index+1], 16)
			print(encText[index]+encText[index+1], x)
			ciphertext.append(x)
	
	print("==============")
	
	z = []
	for i in range(7):
		z.append(ciphertext[i])
	z.append(ciphertext[len(ciphertext)-1])

	cs628a = 'cs628a{}'
	cs628a = list(cs628a)
	cs628a = [ord(i) for i in cs628a]

	print(z)
	print(cs628a)
	keys = [i^j for i,j in zip(z, cs628a)]
	print(keys)

	repetitions = 5
	keys = keys * repetitions
	
	plaintext = [i^j for i,j in zip(keys, ciphertext)]

	for i in plaintext:
		print(chr(i), end="")

	print()
	

if __name__ == '__main__':
	main()