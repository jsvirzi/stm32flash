# this next line works for udp
./stm32flash -udp 55151 -xserial /dev/ttyUSB2 -w /mnt/data/test-h750.hex -verbose -g 0x0 -v -i "-dtr&-rts,rts,,,,,,:dtr&-rts,rts,"
# this next line works for serial - untested
./stm32flash -xudp 55151 -serial /dev/ttyUSB2 -w /mnt/data/test-h750.hex -verbose -g 0x0 -v -i "-dtr&-rts,rts,,,,,,:dtr&-rts,rts,"
