# wl-mcp3008

A simple extension for reading Microchip MCP3008 data in the Wolfram Language on the Raspberry Pi

by Joshua Schrier (2020) <jschrier [at] fordham [dot] edu>

# Install

## Pre-requisites:

* [wiring pi](http://wiringpi.com) comes default in Raspbian (no installation necessary)
* [Mathematica on the Raspberry Pi](https://www.wolfram.com/raspberry-pi/):  the makefile below assumes version 12.0, but it is easy to change this. 
* Be sure to [enable SPI bus](https://learn.sparkfun.com/tutorials/raspberry-pi-spi-and-i2c-tutorial/all#spi-on-pi) 

(Tested on Raspbian 10 (buster)  with Mathematica 12.0.1)

## From precompiled binary 

A precompiled ARM-Linux binary for the Raspberry Pi (Raspian 10 on 3B+) is available in this repository.  You can install it by running the following command in a terminal window: 

`curl https://github.com/jschrier/wl-mcp3008/blob/master/wl-mcp3008 --output ~/.Mathematica/Applications/wl-mcp3008`

(This installs the package for the current user)


## Compiling it yourself

*Note:*  The `mcc` compiler script provided for Mathematica 12 on Raspberry Pi has some defects associated with the -m32 and -m64 compiler flags. The simple solution is to comment those lines in mcc file. Open the file:

`/opt/Wolfram/WolframEngine/12.0/SystemFiles/Links/MathLink/DeveloperKit/Linux-ARM/CompilerAdditions/mcc`

(or whatever your version is) and then comment out these lines:

```
else  # With gcc, target architecture is set by the -m32 and -m64 flags                                                
       if [ ${bitsize} = ${bit32} ] ; then                                                                             
           arch_flags="-m32"                                                                                           
       elif [ ${bitsize} = ${bit64} ] && [ "${archi}" = "x86_64" ] ; then                                              
               arch_flags="-m64"                                                                                       
       fi
```

Then just run: 

```
make
make install
```

(default install path will put it into local user's `.Mathematica/Applications/` directory, like above)


# Usage

Minimum example (in Mathematica)

```
Install["mcp3008"] (*loads the library*)

mcp3008[0] (* read from channel 0 *)

mcp3008[7] (*read from channel 7 *)
```

Returned values are integers; the MCP3008 returns 10 bit integers ranging from 0 to 1023.

