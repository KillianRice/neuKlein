-------------------------------------------------------------------
 P C O  C O M P U T E R  O P T I C S  G M B H
     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------

README FOR SOFTWARE/VERSION:  
Linux SDK Release 0102

FOR PCO PRODUCT/VERSION:
SensiCam, DicamPro

DESCRIPTION:
This packages includes the Linux driver and library for the SensiCam and
DicamPro cameras and a manual with detailed description of each library command. 
Simple testprograms are added, to show the library functions.
Please read the manual before using the driver and library.

Attention!!! 
When using kernel 2.4 version 2.4.18 and above is necessary for this driver.  
Kernel versions from 2.4.4 to 2.4.10 do not work with this driver.
Kernel versions from 2.4.11 to 2.4.17 are not tested.
Compile with gcc versions below 3.0 i.e. 2.95.3

When using kernel 2.2 version 2.2.18 and above is recommended.

CONTENTS:

Archive File Name: SW_SCDPSDKLNX_0102.tar.gz

Files Included                  Size          Date            Time

     Readme.txt    (this file)              
     sen1_02_02.tar.gz           94589        21.08.2002      20:46 
     MA_SCDPSDKLNXE_0102.pdf     256175       19.08.2002      12:45


Installation Instructions:

Copy the SW_SCDPSDKLNX_0102.tar.gz to a distinct directory (e.g. PCOSDK). 
Use "tar -xpvzf SW_SCDPSDKLNX_0102.tar.gz" to get the above files.

To get the driver and library
Use "tar -xpvzf sensdk1_02_02.tar.gz".

After this you will find the following new directories and files as noted.

Each directory contains a makefile and source files for different parts of
the SDK. The makefiles build a debug and release version of all parts in the
subdirectory "debug" respectivly "rel".
Errors during compilation create error files in the "make_err" directory for
each source file.

Driver compilation and driver installation should be done as root.
After uncompressing change to directory .../sen1_02_02 and do 
 make driver
 make install
 reboot

Make install calls script file sencam_load.
The script sencam_load must be called only once after building the driver.
It removes older versions of driver module pco52x.o and copies the new built to
lib/modules/'uname -r'/pco.
An entry for the driver in modules.conf is created.
File pb52xx.bit is copied to lib/modules/'uname -r'/pco.
The script sencam_load creates file pb525.sh in directory /etc/profile.d,
which exports environment variable PCOPB. (see File pb5250xx.bit ... )
The script askes for the number of devices and buffers and creates the devnodes in
the /dev directory according to the user input.
Startparameters of the pco52x module (sen_major and sen_message)can be given as command
line parameters.
The script sencam_unload undos all the actions done from sencam_load.

File pb5250xx.bit and environment variable PCOPB:
When the library function sen_initboard() is called and a PCI525 board is found,
the fpga's on board are loaded with the bitstream from file pb5250xx.bit.
The current and one upper directories will be searched for finding the newest version
of this file, where xx is the version number.
Too shorten this process or to start programs from any directory environment PCOPB
should be set to the correct filepath i.e. "/usr/pco/sen1_02_02/pb525002.bit".


./sen1_02_02/sendrv
Driver C-source and header files.

./sen1_02_02/sendrvh
Header files for the driver

./sen1_02_02/coc_i386
compiled COC-library for Intel Prozessors

./sen1_02_02/senlib
Library C-source and header files

./sen1_02_02/sentest
Testprogram C-source and header files.
sentest: use of driver functions
sengrab: grabs series of pictures
sengrab2: grabs series of pictures from two cameras

VERSION HISTORY:

ver0102
first release

KNOWN BUGS:
Does not compile with gcc version 3.x



-------------------------------------------------------------------
 PCO COMPUTER OPTICS GMBH
 LUDWIGSPLATZ 4
 93309 KELHEIM / GERMANY
 PHONE +49 (9441) 20050
 FAX   +49 (9441) 200520
 info@pco.de, support@pco.de
 http://www.pco.de
-------------------------------------------------------------------
 DISCLAIMER
 THE ORIGIN OF THIS INFORMATION MAY BE INTERNAL OR EXTERNAL TO PCO.
 PCO MAKES EVERY EFFORT WITHIN ITS MEANS TO VERIFY THIS INFORMATION.
 HOWEVER, THE INFORMATION PROVIDED IN THIS DOCUMENT IS FOR YOUR
 INFORMATION ONLY. PCO MAKES NO EXPLICIT OR IMPLIED CLAIMS TO THE
 VALIDITY OF THIS INFORMATION.
-------------------------------------------------------------------
 Any trademarks referenced in this document are the property of
 their respective owners.
-------------------------------------------------------------------
