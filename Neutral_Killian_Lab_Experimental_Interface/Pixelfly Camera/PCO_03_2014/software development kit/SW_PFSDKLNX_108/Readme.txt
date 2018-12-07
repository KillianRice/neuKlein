-------------------------------------------------------------------
 P C O  C O M P U T E R  O P T I C S  G M B H
     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------

README FOR SOFTWARE/VERSION:  
Linux SDK Release 0108

FOR PCO PRODUCT/VERSION:
PixelFly

DESCRIPTION:
This packages includes the Linux driver and library for the
PixelFly camera and a manual with detailed description of each
library command. 
Two simple testprograms are added, to show the library functions.
Please read the manual before using the driver and library.


Attention!!! 
When using kernel 2.4 version 2.4.18 and above is necessary for this driver.  
Kernel versions from 2.4.4 to 2.4.10 do not work with this driver.
Kernel versions from 2.4.11 to 2.4.17 are not tested.
Compile with gcc versions below 3.0 i.e. 2.95.3

When using kernel 2.2 version 2.2.18 and above is recommended.

CONTENTS:

Archive File Name: SW_PFSDKLNX_0108.tar.gz

Files Included                  Size          Date            Time

     Readme.txt    (this file)              
     pfsdk1_15_13.tar.gz        94589        21.08.2002      20:46 
     MA_PFSDKLNXE_0107.pdf     256175        19.08.2002      12:45


Installation Instructions:

Copy the SW_PFSDKLNX_0107.tar.gz to a distinct directory (e.g. PCOSDK). 
Use "tar -xpvzf SW_PFSDKLNX_0107.tar.gz" to get the above files.

To get the driver and library
Use "tar -xpvzf pfsdk1_15_13.tar.gz".

After this you will find the following new directories and files as noted.

Each directory contains a makefile and source files for different parts of
the SDK. The makefiles build a debug and release version of all parts in the
subdirectory "debug" respectivly "rel". The debug version of the driver write
a lot of kernel messages, so it should not be  used for normal work.
Errors during compilation create error files in the "make_err" directory for
each source file.

./pfsdk1_15_14
Driver compilation and driver installation should be done as root.
After uncompressing change to directory .../pfsdk1_15_14 and do 
 make driver
 make install
 reboot

Make install calls script file pccam_load.
The script pccam_load must be called only once after building the driver.
It removes older versions of driver module pccam.o and copies the new built to
lib/modules/'uname -r'/pco.
Then an entry for the driver in modules.conf is created.
It askes for the number of devices and buffers and creates the devnodes in
the /dev directory according to the user input.
Startparameters of the pccam module (pcc_major and pcc_message)can be given as command
line parameters.
The script pccam_unload undos all the actions done from pccam_load.

./pfsdk1_15_14/pccdrv
Driver C-source and header files.

./pfsdk1_15_14/pccdrvh
Header files for the driver

./pfsdk1_15_14/pcclib
Library C-source and header files

./pfsdk1_15_14/pcctest
Testprogram C-source and header files.
pccmain: use of driver functions
pccbuf:  use of buffer functions
pccgrab: grabs series of pictures

VERSION HISTORY:

Version 0105:

Version 0106:

Version 0107:
support for Kernel2.4 added
additional call, to set exposure time in async mode withoaut stopping the camera
(this requires the latest firmware revision for the PCI-Board)

Version 0108:
new installation script
support for more ccd's added
error in buffer functions (Redhat) removed 


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
