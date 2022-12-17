# building

After changing the current directory to a proper location:

    git clone https://github.com/jsvirzi/stm32flash.git 
    cd stm32flash
    mkdir build
    cd build
    cmake ..
    make

# important note

The DTR line is connected to BOOTSEL, and RTS line is connected to the RESET line.
RTS has a hardware layer of inversion, and is compensated by software which inverts the polarity of RTS.
DTR is not inverted. Thus RTS and DTR have slightly different treatment

# this next line works for udp
    ./stm32flash -udp 55151 -w /mnt/data/test-h750.hex -verbose -g 0x0 -v -i "dtr&-rts,rts,,,,,,:-dtr&-rts,rts,"
# this next line works for serial - untested
./stm32flash -xudp 55151 -serial /dev/ttyUSB2 -w /mnt/data/test-h750.hex -verbose -g 0x0 -v -i "-dtr&-rts,rts,,,,,,:dtr&-rts,rts,"
