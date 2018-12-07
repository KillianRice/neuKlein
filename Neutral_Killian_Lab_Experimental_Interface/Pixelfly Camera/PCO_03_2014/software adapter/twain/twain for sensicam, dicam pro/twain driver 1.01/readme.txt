-------------------------------------------------------------------
 P C O  C O M P U T E R  O P T I C S  G M B H
     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------


README FOR SOFTWARE/VERSION:  
TWAIN SensiCam V1.01 - TWAIN Driver Software

FOR PCO PRODUCT/VERSION:
PCI-Interface-Board 52x
SensiCam, DiCAM-PRO

DESCRIPTION:
This package includes a setup, which installs the following files
in your WINDOWS system directory and the selected application directory.


WINDOWS 9x/Me/NT4/2000:
 readme.txt   is copied to "SYSDIR"\system\twain_32\Pco
 tw_pco32.ds   is copied to "SYSDIR"\system\twain_32\Pco
 all Lut files are copied to "SYSDIR"\system\twain_32\Pco 

 all other files are copied to "APPDIR" (see list below)

Registry:
Following registry entries will be created during runtime of the software:
 HKCU\Software\PCO\TWAINPF 
 HKCU\Software\PCO\PixelFly x
Where x depends on the current number of the PixelFly camera (If there is one!).
In case of SensiCam, Dicam Pro, HSFC Pro please take a look at the SensiCam
driver disk readme.

CONTENTS:

README.TXT     (This file)
SW_SCDPHPTWAINWIN_101 (zipArchive File Name)

Files Included in Archive       Size          Date          Time

..\
_INST32I		EX_	  300178	19.11.1997	16:05
_ISDEL			EXE	    8192	19.11.1997	16:05
_SETUP			DLL	   11264	19.11.1997	16:08
_SYS1			CAB	  186302	17.07.2002	10:24
_USER1			CAB	   44710	17.07.2002	10:24
DATA1			CAB	  167869	17.07.2002	10:24
DATA			TAG	     135	17.07.2002	10:24
LANG			DAT	    4557	30.05.1997	11:31
LAYOUT			BIN	     374	17.07.2002	10:24
OS			DAT	     417	06.05.1997	14:15
README			TXT	    this file!
SETUP16			BMP	   33518	15.07.2002	13:03
SETUP			BMP	   67878	15.07.2002	13:02
SETUP			EXE	   59904	19.11.1997	16:09
SETUP			INI	      62	17.07.2002	10:24
SETUP			INS	   58483	15.07.2002	12:53
SETUP			LID	      49	17.07.2002	10:24

Files Installed                 Size          Date          Time
Application Related Files:
README			TXT	    1158	15.07.2002	12:48
TW_PCO32		DS	  143360	15.07.2002	12:45

Additional Tool Files:
LOUPE			CNT	    1138	02.02.1998	01:01
LOUPE			EXE	  147456	02.02.1998	01:01
LOUPE			HLP	   42562	02.02.1998	01:01

Pseudo Color Lookup Table Files:
LUT_BGRSOFT		LT1	    2248	11.05.1998	11:18
LUT_BLUE		LT4	     768	22.05.1998	13:52
LUT_COMPRESSED		LT1	    2645	11.05.1998	10:46
LUT_EXPANDED		LT1	    3077	11.05.1998	10:18
LUT_EXPONENTIAL		LT1	    2263	11.05.1998	10:13
LUT_GREEN		LT2	    3162	22.05.1998	13:46
LUT_GREEN		LT4	     768	07.04.1995	17:24
LUT_GREEN_INVERS	LT3	     768	22.05.1998	12:41
LUT_INVERTED		LT1	    3176	22.05.1998	12:29
LUT_ISO7_COLOR		LT1	    2878	11.05.1998	10:45
LUT_LINEAR		LT1	    3162	22.05.1998	12:29
LUT_LINEAR		LT4	     768	07.04.1995	17:27
LUT_LOGARITHMIC		LT1	    3173	11.05.1998	10:11
LUT_MIDDLEQUADRANT_BW	LT1	    2603	11.05.1998	10:33
LUT_OVEREXPOSED		LT1	    2832	09.06.1998	10:05
LUT_QUANTIZED8_BW	LT1	    2694	11.05.1998	10:31
LUT_QUANTIZED8SOFT_COLORLT1	    2434	11.05.1998	10:56
LUT_QUANTIZED16_COLOR	LT1	    2510	11.05.1998	10:54
LUT_RAINBOW		LT1	    2418	11.05.1998	10:51
LUT_RED			LT4	     768	22.05.1998	12:50
LUT_RGB			LT1	    2046	11.05.1998	10:49
LUT_RGBSOFT		LT1	    2097	11.05.1998	10:46

The 'Application Related' files are the driver itself including the neccessary runtime dlls.

The 'Additional Tool' files are a display loupe.

The 'Pseudo Color Lookup Table' files can be used to convert b/w images into pseudo color images.


Installation Instructions:

Copy the SW_SCDPHPTWAINWIN_101.zip to a distinct directory ( e.g. 'PCOTEMP').
Unzip the file.

1.  Select above directory ( e.g. 'PCOTEMP').
2.  Start 'setup.exe' to run setup.
3.  The necessary files will be installed automatically.
4.  Reboot your computer.
5.  Now you are ready to run the camera control software.


VERSION HISTORY:
Version 101

KNOWN BUGS:
-none

Version 100
First release

KNOWN BUGS:
- Display review (not a bug)

-------------------------------------------------------------------
 PCO COMPUTER OPTICS GMBH
 DONAUPARK 11
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










