-------------------------------------------------------------------
 P C O  C O M P U T E R  O P T I C S  G M B H
     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------


README FOR SOFTWARE/VERSION:  
TWAIN PixelFly V1.10 - TWAIN Driver Software

FOR PCO PRODUCT/VERSION:
PCI-Interface-Board 540xP
PixelFly

DESCRIPTION:
This package includes a setup, which installs the following files
in your WINDOWS system directory and the selected application directory.

WINDOWS 9x/Me/NT4/2000:
 readme.txt   is copied to "SYSDIR"\system\twain_32\Pco
 Pcocnv.dll   is copied to "SYSDIR"\system\twain_32\Pco
 pcoltdlg.dll is copied to "SYSDIR"\system\twain_32\Pco
 Pcotwpf.ds   is copied to "SYSDIR"\system\twain_32\Pco
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
SW_PFTWAINWIN_110 (zipArchive File Name)

Files Included in Archive       Size          Date          Time

..\
_INST32I		EX_	  300178	19.11.1997	16:05
_ISDEL			EXE	    8192	19.11.1997	16:05
_SETUP			DLL	   11264	19.11.1997	16:08
_SYS1			CAB	  186302	16.07.2002	16:44
_USER1			CAB	   44721	16.07.2002	16:44
DATA1			CAB	  462868	16.07.2002	16:44
DATA			TAG	     135	16.07.2002	16:44
LANG			DAT	    4557	30.05.1997	11:31
LAYOUT			BIN	     374	16.07.2002	16:44
OS			DAT	     417	06.05.1997	14:15
README			TXT	    this file!
SETUP16			BMP	   33518	12.07.2002	15:13
SETUP			BMP	   67878	12.07.2002	15:12
SETUP			EXE	   59904	19.11.1997	16:09
SETUP			INI	      62	16.07.2002	16:44
SETUP			INS	   58483	16.07.2002	16:44
SETUP			LID	      49	16.07.2002	16:44

Files Installed                 Size          Date          Time
Application Related Files:
PCOCNV			DLL	   94208	05.07.2002	14:27
PCOLTDLG		DLL	  258048	15.07.2002	10:48
PCOTWPF			DS	  479232	12.07.2002	14:11
README			TXT	    1158	12.07.2002	14:59

Additional Tool Files:
LOUPE			CNT	    1138	02.02.1998	00:00
LOUPE			EXE	  147456	02.02.1998	00:00
LOUPE			HLP	   42562	02.02.1998	00:00

Pseudo Color Lookup Table Files:
LUT_BGRSOFT		LT1	    2248	27.01.2001	10:00
LUT_BLUE		LT4	     768	27.01.2001	10:00
LUT_COMPRESSED		LT1	    2645	27.01.2001	10:00
LUT_EXPANDED		LT1	    3077	27.01.2001	10:00
LUT_EXPONENTIAL		LT1	    2263	27.01.2001	10:00
LUT_GREEN		LT2	    3162	27.01.2001	10:00
LUT_GREEN		LT4	     768	27.01.2001	10:00
LUT_GREEN_INVERS	LT3	     768	27.01.2001	10:00
LUT_INVERTED		LT1	    3176	27.01.2001	10:00
LUT_ISO7_COLOR		LT1	    2878	27.01.2001	10:00
LUT_LINEAR		LT1	    3162	27.01.2001	10:00
LUT_LINEAR		LT4	     768	27.01.2001	10:00
LUT_LOGARITHMIC		LT1	    3173	27.01.2001	10:00
LUT_MIDDLEQUADRANT_BW	LT1	    2603	27.01.2001	10:00
LUT_OVEREXPOSED		LT1	    2832	27.01.2001	10:00
LUT_QUANTIZED8_BW	LT1	    2694	27.01.2001	10:00
LUT_QUANTIZED8SOFT_COLORLT1	    2434	27.01.2001	10:00
LUT_QUANTIZED16_COLOR	LT1	    2510	27.01.2001	10:00
LUT_RAINBOW		LT1	    2418	27.01.2001	10:00
LUT_RED			LT4	     768	27.01.2001	10:00
LUT_RGB			LT1	    2046	27.01.2001	10:00
LUT_RGBSOFT		LT1	    2097	27.01.2001	10:00

Color Lookup Table Files:
3300			LTC	     136	27.01.2001	10:00
3600			LTC	     136	27.01.2001	10:00
4000			LTC	     136	27.01.2001	10:00
4600			LTC	     136	27.01.2001	10:00
5600			LTC	     136	27.01.2001	10:00
7700			LTC	     136	27.01.2001	10:00
12000			LTC	     136	27.01.2001	10:00
15000			LTC	     136	27.01.2001	10:00
BG2200			LTC	     136	27.01.2001	10:00
BG2300			LTC	     136	27.01.2001	10:00
BG2500			LTC	     136	27.01.2001	10:00
BG2800			LTC	     136	27.01.2001	10:00
BG3300			LTC	     136	27.01.2001	10:00
BG4200			LTC	     136	27.01.2001	10:00
BG5600			LTC	     136	27.01.2001	10:00
BG9000			LTC	     136	27.01.2001	10:00

The 'Application Related' files are the driver itself including the neccessary runtime dlls.

The 'Additional Tool' files are a display loupe.

The 'Pseudo Color Lookup Table' files can be used to convert b/w images into pseudo color images.

The 'Color Lookup Table' files can be used to set the color conversion to a certain color temperature.


Installation Instructions:

Copy the SW_PFTWAINWIN_110.zip to a distinct directory ( e.g. 'PCOTEMP').
Unzip the file.

1.  Select above directory ( e.g. 'PCOTEMP').
2.  Start 'setup.exe' to run setup.
3.  The necessary files will be installed automatically.
4.  Reboot your computer.
5.  Now you are ready to run the camera control software.


VERSION HISTORY:
Version 110

KNOWN BUGS:
-none

Version 100
First release

KNOWN BUGS:
- Some malfunction, because of twain initialisation errors.

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










