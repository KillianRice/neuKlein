-------------------------------------------------------------------
 P C O   AG   -     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------


README FOR SOFTWARE/VERSION:  
CamWare for HSFC-Pro V2.15 - Camera Application Software

FOR PCO PRODUCT/VERSION:
PCI-Interface-Board 520xP
PCI-Interface-Board 525xP
PCI-Interface-Board 540xP
SensiCam, Dicam Pro, PixelFly
pco.camera

DESCRIPTION:
This package includes a setup, which installs the following files
in your WINDOWS system directory and the selected application directory.

WINDOWS 9x/Me/NT4/2000/XP:
 all files are copied to "APPDIR"/CamWare (see list below)

Where APPDIR is the selected application directory
(e.g. c:\program files\digital camera toolbox\camware).

Registry:
Following registry entries will be created during runtime of the software:
 HKCU\Software\PCO\CamWare 
 HKCU\Software\PCO\PixelFly x
Where x depends on the current number of the PixelFly camera (If there is one!).
In case of SensiCam, Dicam Pro, HSFC Pro please take a look at the SensiCam
driver disk readme.

CONTENTS:

README.TXT     (This file)
SW_CAMWHSFCWIN_215 (zipArchive File Name)

Files Included in Archive          Size            Date          Time

..\
LOGODS			B16	 5243392	01.04.2004	17:18
DATA1			CAB	  302706	19.06.2006	17:17
DATA1			HDR	   19384	19.06.2006	17:17
DATA2			CAB	 6163051	19.06.2006	17:17
ENGINE32		CAB	  459544	10.11.2003	20:55
INFO			TXT	    2589	19.09.2005	13:25
LAYOUT			BIN	     564	19.06.2006	17:17
LOGO			B16	  614784	03.09.2002	14:11
LOGODS			B16	 5243392	01.04.2004	17:18
README			TXT	this file!		
SETUP			SKIN	   40933	14.04.2004	15:42
SETUP			BMP	   67878	16.07.2002	16:03
SETUP			EXE	  116880	10.11.2003	20:55
SETUP			IBT	  361737	19.06.2006	17:17
SETUP			INI	     475	19.06.2006	17:17
SETUP			INX	  189473	19.06.2006	17:17

Manufacturer Files:
INFO			TXT	    2589	19.09.2005	13:25
LOGO			B16	  614784	03.09.2002	14:11
LOGODS			B16	 5243392	01.04.2004	17:18


Example Files:
TEST_IMAGE_COLOR	B16	  614528	25.09.1997	22:45
TEST_IMAGE_BW		B16	  405632	26.09.1997	11:46

Application Related Files:
README			TXT	    5095	12.11.2004	15:22
CAMWARE			CHM	  678410	06.04.2006	10:52
CAMWARE			EXE	 6967296	19.06.2006	16:36
FLOWDICAMDOUBLE		TXT	     167	12.04.2001	14:02
FLOWDICAMSINGLE		TXT	     173	18.04.2001	16:28
FLOWPIXELFLY		TXT	     101	09.05.2001	17:55
FLOWSENSICAM		TXT	     101	18.07.2001	10:43
LIESMICH		TXT	    5380	12.11.2004	15:29

Application Related DLLs:
PCOLTDLG		DLL	  434176	06.04.2006	10:37
CV097			DLL	  573490	15.11.2005	13:06
CXCORE097		DLL	  794678	15.11.2005	13:06
GDIPLUS			DLL	 1645320	04.05.2004	12:53
LIBDSW-1.0.3		DLL	   31232	23.01.2006	01:00
LIBMCL-4.5.0		DLL	 1159680	23.01.2006	01:00
LIBMPG-1.0.2		DLL	 1679872	23.01.2006	01:00
PCO_FC			DLL	  274507	15.02.2006	17:02
PCOCNV			DLL	  221184	06.04.2006	10:37

Additional Tools:
LOUPE			HLP	   42562	02.02.1998	02:01
LOUPE			CNT	    1138	02.02.1998	02:01
LOUPE			EXE	  147456	02.02.1998	02:01

Pseudo Color Lookup Table Files:
LUT_RGBSOFT		LT1	    2097	22.12.2000	13:10
3300			LTC	     136	09.10.2000	16:20
3600			LTC	     136	09.10.2000	16:20
4000			LTC	     136	09.10.2000	16:20
4600			LTC	     136	09.10.2000	16:20
5600			LTC	     136	09.10.2000	16:20
7700			LTC	     136	09.10.2000	16:21
12000			LTC	     136	09.10.2000	16:21
15000			LTC	     136	09.10.2000	16:21
BG2200			LTC	     136	09.10.2000	16:23
BG2300			LTC	     136	09.10.2000	16:23
BG2500			LTC	     136	09.10.2000	16:23
BG2800			LTC	     136	09.10.2000	16:23
BG3300			LTC	     136	09.10.2000	16:23
BG4200			LTC	     136	09.10.2000	16:23
BG5600			LTC	     136	09.10.2000	16:22
BG9000			LTC	     136	09.10.2000	16:22
LUT_BGRSOFT		LT1	    2248	11.05.1998	12:18
LUT_BLUE		LT4	     768	22.05.1998	14:52
LUT_COMPRESSED		LT1	    2645	22.12.2000	13:10
LUT_EXPANDED		LT1	    3077	11.05.1998	11:18
LUT_EXPONENTIAL		LT1	    2263	11.05.1998	11:13
LUT_GREEN		LT2	    3162	22.12.2000	13:10
LUT_GREEN		LT4	     768	07.04.1995	18:24
LUT_GREEN_INVERS	LT3	     768	22.05.1998	13:41
LUT_INVERTED		LT1	    3176	22.12.2000	13:10
LUT_ISO7_COLOR		LT1	    2878	22.12.2000	13:10
LUT_LINEAR		LT1	    3162	22.12.2000	13:10
LUT_LINEAR		LT4	     768	07.04.1995	18:27
LUT_LOGARITHMIC		LT1	    3173	22.12.2000	13:10
LUT_MIDDLEQUADRANT_BW	LT1	    2603	11.05.1998	11:33
LUT_OVEREXPOSED		LT1	    2832	22.12.2000	13:10
LUT_QUANTIZED8_BW	LT1	    2694	11.05.1998	11:31
LUT_QUANTIZED8SOFT_COLOR	LT1	    2434	11.05.1998	11:56
LUT_QUANTIZED16_COLOR	LT1	    2510	11.05.1998	11:54
LUT_RAINBOW		LT1	    2418	22.12.2000	13:10
LUT_RED			LT4	     768	22.05.1998	13:50
LUT_RGB			LT1	    2046	11.05.1998	11:49


The 'Manufacturer' files are containing the camera manufacturer informations.

The 'Example' files can be loaded into the application to play around with the converter and
different file types.

The 'Application Related' files are the application itself including the help file and
neccessary runtime dlls.

The 'Additional Tool' files are an image converter and a display loupe.

The 'Pseudo Color Lookup Table' files can be used to convert b/w images into pseudo color images.

The 'Color Lookup Table' files can be used to set the color conversion to a certain color temperature.


Installation Instructions:

Copy the SW_CAMWHSFCWIN_215.zip to a distinct directory ( e.g. 'PCOTEMP').
Unzip the file.

1.  Select above directory ( e.g. 'PCOTEMP').
2.  Start 'setup.exe' to run setup.
3.  The necessary files will be installed automatically.
4.  Now you are ready to run the camera control software.

If you have problems during the installation, please check your firewall and / or disable it.

VERSION HISTORY:
Version 215:
- Changing the binning and/or ROI multiple times crashed CamWare used with SensiCam. Fixed.

Version 214:
- added overlay functionality
- Default file type enhanced to MULTI-TIFF.
- Four color conversion algorythms are available.
- Export and save splitted to reflect application functionality and correct file types.
- Long lasting file operations can be stopped by pressing the ESC-key.
- Record stop event mode and noisefilter mode added.
- Export to avi (max. 2048x2048) and mpeg (DV resolution) added.
- bugfixes


Version 120

KNOWN BUGS:
- Crash in auto exposure mode
- Added: Preview for Doubleshutter mode, Mode for Fastshutter Modulation
- Fixed some unattractive behaviour

Version 110,111,112

KNOWN BUGS:
- After working with a doubleshutter PixelFly plug in a PixelFly without
  doubleshutter. Camware produces an error while initializing the camera.
- Averaging with start = 1 and stop = 2 in recorder triggers only first image.
- Some irregular behaviour with doubleshutter cameras.
- Window title is wrong after import closing window and import.
- Mathtoolbar off does not switch off math functionality inside the camera
  module.
- Import set does not update all images and the datawindow is in background.

Version 100

KNOWN BUGS:
- The menu items PgUp and PgDn are mixed up inside the local menu of the
  browser window.
- If you have the bw and color window open and they are overlayed and you
  change the picture size in the camera dialog and aquire images (single,
  preview or record) the content of the underlying window is not repainted.
- If you change printer settings in 'Print Setup' the settings are not
  transferred to the 'Print...' dialog! You have to apply the settings again.
- After you load a hotpixel file the application may crash.
- If you have installed more than one PCI-Interface-Board 52Xxx and you
  have only one camera (SensiCam...) switched on and you alter the actual
  picture size by changing the ROI or binning the recorder is not updated
  correctly. This results in corrupted images and application crash.
  Remove the unused board.

Not included features (Yet!):
Auto exposure mode. SensiCam in multichannel mode.

If you run into problems during the installation you could delete the 
following directory and its contents (if existent):
C:\program files\installshield installation information\{2C73D902-C93D-4893-912D-58241DDBA8AA}
'C:\program files\' depends on your sytem and might be different.

-------------------------------------------------------------------
 PCO AG
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

