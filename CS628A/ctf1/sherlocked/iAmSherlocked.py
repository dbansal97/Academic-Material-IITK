'''
Hope Sherlock Holms don't intercept this encrypted flag, 
because there are many things to deduce here!
'''

import random

def main():
	plaintext = open('flag.txt', 'r').read()
	plaintext = list(plaintext)
	plaintext = [ord(i) for i in plaintext]

	key = [random.randint(0,255) for i in range(8)]
	# open('key','w').write(str(key))
	
	text_len = len(plaintext)
	key_len = len(key)
	repetitions = int(text_len/key_len)
	key = key * repetitions
	
	ciphertext = [i^j for i,j in zip(plaintext, key)]

	strr = ""
	for i in ciphertext:
		strr += "%02x" % i
	open('flag.enc','w').write(strr)


if __name__ == '__main__':
	main()