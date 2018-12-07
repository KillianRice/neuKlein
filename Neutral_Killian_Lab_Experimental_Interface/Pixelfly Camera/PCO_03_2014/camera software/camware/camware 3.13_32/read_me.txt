-------------------------------------------------------------------
 P C O   AG   -     TECHNICAL  INFORMATION  DOCUMENT
-------------------------------------------------------------------


README FOR SOFTWARE/VERSION:  
CamWare 3.13 - Camera Application Software

FOR PCO PRODUCT/VERSION:
PCI-Interface-Board 525xP
PCI-Interface-Board 540xP

SensiCam, Dicam Pro, PixelFly
pco.camera based cameras (pco.dimax, pco.edge, etc.)

DESCRIPTION:
This package includes a setup, which installs the following files
in your selected application directory.

Windows Vista, 7, 8:
all files are copied to "APPDIR"/CamWare in case of an administator installation
all files are copied to "USER_APPDIR"/CamWare in case of a user installation

Where APPDIR is the selected application directory,
e.g. c:\program files\digital camera toolbox\camware.
Where USER_APPDIR is the selected user application directory,
e.g. C:\Users\<user>\AppData\Roaming\Digital Camera Toolbox\CamWare.
It is possible to select between both installation methods.

Registry:
Following registry entries will be created during runtime of the software:
 HKCU\Software\PCO\CamWare 
 HKCU\Software\PCO\Cameratype x
Where x depends on the current number of the connected camera.

The 64bit installation differs in date/time/content.

CONTENTS:

SW_CAMWAREWIN32_313 (Self extracting installer)

Files Included                      Ext.           Size        Date       Time

Application Related Files:
APL_CAMWARE_111_0001                PDF          298559      19.06.2013 13:23
CAMWARE                             CHM          760096      27.07.2010 11:34
CAMWARE                             EXE        10023936      14.03.2014 09:01
FLOWDICAMDOUBLE                     TXT             167      12.04.2001 13:02
FLOWDICAMSINGLE                     TXT             173      18.04.2001 15:28
FLOWPIXELFLY                        TXT             101      09.05.2001 16:55
FLOWSENSICAM                        TXT             101      18.07.2001 09:43
LIESMICH                            TXT            5607      02.10.2012 15:01
READ_ME                             TXT      this file!                 
README                              TXT            5216      08.01.2014 08:43

Application Related DLLs:
CV097                               DLL          573490      15.11.2005 12:06
CXCORE097                           DLL          794678      15.11.2005 12:06
GDIPLUS                             DLL         1645320      04.05.2004 11:53
LIBDSW-1.1.0                        DLL           63488      29.05.2013 15:43
LIBJP2-1.1.0                        DLL          263168      29.05.2013 15:43
LIBJPG-1.2.1                        DLL          148480      29.05.2013 15:43
LIBMCL-6.2.1                        DLL         3107328      29.05.2013 15:43
LIBMPG-3.0.3                        DLL         5190656      29.05.2013 15:43
LIBWMV-3.0.2                        DLL           71680      29.05.2013 15:43
PCO_CDLG                            DLL         1105408      28.02.2014 12:12
PCO_CONV                            DLL          706560      28.02.2014 12:11
PCO_SCMOS_GL                        HAP         2232553      15.11.2011 15:27
SC2_CAM                             DLL          369664      13.03.2014 07:46
SC2_CL_ME3                          DLL          156160      17.05.2011 14:48
SC2_CL_ME4                          DLL          285696      20.12.2013 15:41
SC2_CL_MTX                          DLL          392704      03.11.2011 15:46
SC2_CL_NAT                          DLL          161792      30.10.2012 09:20
SC2_DLG                             DLL          603136      13.03.2014 07:46
SENC_DIC                            DLL          126976      29.04.2011 11:17
SENC_NOF                            DLL          125440      29.04.2011 11:18
SENC_NOL                            DLL          125952      29.04.2011 11:18
SENC_QEL                            DLL          138240      02.05.2011 09:36
SENC_TI                             DLL          131072      10.06.2011 15:39

Pseudo Color Lookup Table Files:
3300                                LTC             136      20.07.2010 15:00
3600                                LTC             136      20.07.2010 15:00
4000                                LTC             136      20.07.2010 15:00
4600                                LTC             136      20.07.2010 15:00
5600                                LTC             136      20.07.2010 15:00
7700                                LTC             136      20.07.2010 15:00
12000                               LTC             136      20.07.2010 15:00
15000                               LTC             136      20.07.2010 15:00
BG2200                              LTC             136      20.07.2010 15:00
BG2300                              LTC             136      20.07.2010 15:00
BG2500                              LTC             136      20.07.2010 15:00
BG2800                              LTC             136      20.07.2010 15:00
BG3300                              LTC             136      20.07.2010 15:00
BG4200                              LTC             136      20.07.2010 15:00
BG5600                              LTC             136      20.07.2010 15:00
BG9000                              LTC             136      20.07.2010 15:00
LUT_BGRSOFT                         LT1            2248      20.07.2010 15:00
LUT_BLUE                            LT4             768      20.07.2010 15:00
LUT_COMPRESSED                      LT1            2645      20.07.2010 15:00
LUT_EXPANDED                        LT1            3077      20.07.2010 15:00
LUT_EXPONENTIAL                     LT1            2263      20.07.2010 15:00
LUT_GREEN                           LT2            3162      20.07.2010 15:00
LUT_GREEN                           LT4             768      20.07.2010 15:00
LUT_GREEN_INVERS                    LT3             768      20.07.2010 15:00
LUT_INVERTED                        LT1            3176      20.07.2010 15:00
LUT_ISO7_COLOR                      LT1            2878      20.07.2010 15:00
LUT_LINEAR                          LT1            3162      20.07.2010 15:00
LUT_LINEAR                          LT4             768      20.07.2010 15:00
LUT_LOGARITHMIC                     LT1            3173      20.07.2010 15:00
LUT_MIDDLEQUADRANT_BW               LT1            2603      20.07.2010 15:00
LUT_OVEREXPOSED                     LT1            2832      20.07.2010 15:00
LUT_QUANTIZED8_BW                   LT1            2694      20.07.2010 15:00
LUT_QUANTIZED8SOFT_COLOR            LT1            2434      20.07.2010 15:00
LUT_QUANTIZED16_COLOR               LT1            2510      20.07.2010 15:00
LUT_RAINBOW                         LT1            2418      20.07.2010 15:00
LUT_RED                             LT4             768      20.07.2010 15:00
LUT_RGB                             LT1            2046      20.07.2010 15:00
LUT_RGBSOFT                         LT1            2097      20.07.2010 15:00

Additional Files:
FIND_NAT                            EXE           76288      25.05.2011 14:02
INFO                                TXT            2960      11.09.2012 15:05
LOGO                                B16          614784      20.07.2010 15:00
LOGODS                              B16         5243392      20.07.2010 15:00


The 'test' and 'logo' files can be loaded into the application to play around with the converter and
different file types.

The 'Application Related' files are the application itself including the help file and
sample flow files.

The 'Pseudo Color Lookup Table' files can be used to convert b/w images into pseudo color images.

The 'Color Lookup Table' files can be used to set the color conversion to a certain color temperature.


Installation Instructions:

Copy the SW_CAMWAREWIN32_313.exe to a distinct directory (e.g. 'PCOTEMP')

1.  Select above directory ( e.g. 'PCOTEMP').
2.  Start 'SW_CAMWAREWIN32_313.exe' to run setup.
3.  The necessary files will be installed automatically.
4.  Now you are ready to run the camera control software.

If you have problems during the installation, please check your firewall and / or disable it.

VERSION HISTORY:
Version 313:
- added pco.edge_4.2 camera setup support
- bugfixes

Version 312:
- Added pco.edge_4.2
- Added SoftROI handling
- Key navigation in recorder
- Key initiated save while acquiring
- bugfixes

Version 311:
- Fixed Direct Record To File Performance lag

Version 310:
- Fixed double stop problem with pco.dimax and HDSDI-streaming active
- new MCL library
- Fixed wrong Min/Max region with rubber window

Version 309:
- Added LZW decompression
- Fixed new PixelFly driver adaptions
- Added AcquireModeEx for pco.edge
- Added auto settings for demo mode
- Bugfixes

Version 307:
- Added T0 to recorder slider
- Added scale to recorder slider
- Added functionality to handle master/slave start/stop in correct order
- New recorder button
- Added 6 digits option for file naming
- Added property  window for camera settings
- Added Zoom by Mousewheel (Press CTRL to zoom)
- Added Shutter Mode switching functionality
- Added update all option
- Bugfixes

Version 306:
- bugfixes

Version 305:
- Added pcoraw file format (based on bigtiff proposal)
- Added fifo A154buffer size parameter for direct record to file
- Added compression support for pco.edge

Version 304:
- Added internal memory recorder for pco.camera compatible cameras without CamRam.
- Added pco.edge support
- Added support for Fermi based Nvidia graphics cards.
- Added pco.dimax meta data support.

Version 303:
- Added preserve option
- Added CDI mode for dimax
- Various bugfixes

Version 302:
- PixelFly and SensiCam color convert patch.

Version 301:
- Various bugfixes

Version 300:
- Conversion rewritten
- New style and convert dialogs
- Added support for GigE and USB
- Added move option for marker
- Added WMV, JPEG, JP2 and MPEG4 (via registry key) support
- Improved suppport for Dimax

Version 222:
- Added 'Help Bitmap' in demo mode to simplify problem detection.
- Prepared for Dimax and GigE interface
- Added Line Tool
- Added ROI functionality for AutoMinMax
- Bugfixes

Version 221:
- Some leaks removed
- Added recorder simultation for pco.1300
- Switched over to another GUI-Library
- Enabled logging during startup
- Completed VS compatibility
- Fixed some file dialog problems
- Changed some GUI stuff for Vista compatibility
- Fixed tiff interference between normal file and recorder file
- Fixed temp file persistence by closing all of them after quit
- Improved timeout handling while in play mode with pco.camera

Version 220:
- Various bugfixes
- Changed Lookuptable dialog
- Added Modulate Mode
- Vista compatibility

Version 219:
- Fixed 9999 problem while saving (Single file format is still fixed to _xxxx).
- MPeg FPS setting corrected to real configurable values.
- Settransferparameter in SC2 does not change the Transfer Parameter any longer
- Fixed error with small image sizes: min size set to 4096 Byte.
- Fixed error in KamSC2.cpp while setting ROI and getting ROI-Offset (Binning not kept in mind)
- PcCamDialog.cpp Doubleshutter two-way setting locked.
- KamSC2.cpp: Cancelstate in CamReady ignored.
- Added enum key from HKLM to support-file.
- Driverlogging starts before SC2 is opened.
- Timeout set to 7s for SC2

KNOWN BUGS:
- If flowfile is active changing settings is blocked. To work around this issue change settings stop
 and restart Camware, then activate record with flowfile.

Version 218:
- Segment confusion with pco.camera removed (auto exp. in context menu disabled while recording).
- Doubleshutter export can split bmp and tif, again.
- 16bit RGB export works for all conv. routines now.
- Fixed 9999 problem (Single file names are still bound to _xxxx format!)
- Mpeg FPS settings corrected.
- bugfixes

Version 217:
- Added Modulate Mode to pco.camera control dialog
- Added Sensicam EM functionality
- bugfixes

KNOWN BUGS:
- Exporting double shutter images produces files with double size, but same content for A and B.

Version 216 not released

Version 215:
- Changing the binning and/or ROI multiple times crashed CamWare used with SensiCam. Fixed.

Version 214:
- GUI changed
- bugfixes
- avi mpeg dialog enabled
- splitted file and view convert
- added mean value to histogram

Version 213:
- Default file type enhanced to MULTI-TIFF.
- Four color conversion algorythms are available.
- Export and save splitted to reflect application functionality and correct file types.
- Long lasting file operations can be stopped by pressing the ESC-key.
- Record stop event mode and noisefilter mode added.
- Export to avi (max. 2048x2048) and mpeg (DV resolution) added.
- bugfixes

Version 212:
- Corrected some errors while using more than one camera.
- various bugfixes

Version 210
- enabled CamLink (R) interface
- enabled up to eight cameras within one session
- various bugfixes

KNOWN LIMITATIONS:
- CamWare is not able to handle more than 9999 files up to now.

Version 204
- corrected some errors, one (doubleshutter) implemented with SensiCam QE in 203
- corrected the fps information for 1200hs

Version 203

- added command line /csc2=x to start with a different pco.camera connected (x=0,1,2...)
- enabled SensiCam QE color to be color
- reviewed SensiCam QE to work with CamWare
- released for PixelFly and SensiCam

Version 202

- added color conversion routines for pco.camera
- enhanced white balancing algorythm
- bugfixing (removed busreset for SC, PF; file handling issues)

KNOWN BUGS:
- Direct Record To File does not work with the pco.camera up to now.

Version 201

- added Exp = 1 / FPS mode for pco.1200hs
- added EM chip functionality

KNOWN BUGS:
- none

Version 200
- splitted up to 12x (PixelFly and SensiCam) and 20x (pco.camera)

KNOWN BUGS:
- none

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
License and disclaimer agreement

IMPORTANT - READ CAREFULLY

This license and disclaimer statement constitutes a legal agreement ("License Agreement")
between you (either as an individual or a single entity) and pco ag (the "Author"), for 
this software product ("Software"), including any software, media, and accompanying on-line
or printed documentation produced by pco ag.

BY DOWNLOADING, INSTALLING, COPYING, OR OTHERWISE USING THE SOFTWARE, YOU AGREE TO BE BOUND
BY ALL OF THE TERMS AND CONDITIONS OF THIS LICENSE AND DISCLAIMER AGREEMENT.

If you do not agree with the terms and conditions of this agreement, you must promptly cease
all use of the software and destroy all copies of this software and all of its component
parts in your possession or under your control.

This software is freeware. You can use this software royalty-free for private and commercial
purposes.

You can freely distribute copies of the installation archive as long as no alterations are
made to the contents and no charge is raised.

You must not modify, reverse engineer, decompile, or disassemble the object code portions of
this software.

This Software is owned by pco ag and is protected by copyright law and international copyright
treaty. Therefore, you must treat this Software like any other copyrighted material.

In case the installation contains source code files you can modify and re-distribute copies of
the source code and the compiled binaries which are based on the contained source code.

This software is provided "as is" and without any warranties expressed or implied, including,
but not limited to, implied warranties of fitness for a particular purpose, and non-infringement.

THE AUTHOR DOES NOT WARRANT THAT THE SOFTWARE PRODUCT IS ERROR-FREE. THE ENTIRE RISK AS TO THE
RESULTS AND PERFORMANCE OF THE SOFTWARE PRODUCT IS ASSUMED BY YOU. IF THE SOFTWARE PRODUCT
CONTAINS DEFECTS, YOU, AND NOT THE AUTHOR, ASSUME THE ENTIRE COST OF ALL NECESSARY SERVICING,
REPAIR OR CORRECTION.
You expressly acknowledge and agree that use of the Software is at your sole risk.

In no event shall the author be liable for any damages whatsoever (including, without limitation,
damages for loss of business profits, business interruption, loss of business information, or
other pecuniary loss) arising out of the use of or inability to use this software or documentation,
even if the author has been advised of the possibility of such damages.
Any feedback given to the author will be treated as non-confidential. The author may use any
feedback free of charge without limitation.

