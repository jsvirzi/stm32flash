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
RTS has a hardware layer of inversion, and is not compensated by software.
Asserting RTS clears the CPU reset line; RTS deassertion sets the CPU reset line.

# this next line works for udp
    ./stm32flash -udp 55151 -w firmware.hex -verbose -g 0x0 -v 
# this next line works for serial - untested
    ./stm32flash -serial /dev/ttyUSB2 -w firmware.hex -verbose -g 0x0 -v 

