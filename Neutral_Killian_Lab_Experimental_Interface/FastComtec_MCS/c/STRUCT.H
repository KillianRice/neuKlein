#define  WINDOWSNT
#undef  WINDOWS95
#undef  WINDOWS31

#ifdef WINDOWS31

#define GET_WM_COMMAND_ID(w)  w
#define GET_WM_COMMAND_CMD(w,l) HIWORD(l)
#define GET_WM_COMMAND_HWND(l) LOWORD(l)
#define GET_WM_SCRHWND(l) HIWORD(l)
#define GET_WM_SCROLLPOS(w,l) LOWORD(l)
#define FIND_WINDOW(a,b) FindWindow(b,a)
#define HUGE huge
#define USHORT unsigned short
#define SetForegroundWindow(w)
#define APIENTRY FAR PASCAL
#define Sleep(t) waitmsec(t)

#else

#define GET_WM_COMMAND_ID(w)  LOWORD(w)
#define GET_WM_COMMAND_CMD(w,l) HIWORD(w)
#define GET_WM_COMMAND_HWND(l) l
#define GET_WM_SCRHWND(l) l
#define GET_WM_SCROLLPOS(w,l) (short)HIWORD(w)
#define FIND_WINDOW(a,b) FindWindow(a,b)
#define HUGE
#define _fmemcpy memcpy
#define _fstrcpy strcpy

#endif

typedef struct {
        int use;
        int port;
        unsigned long baud;
        int dbits;
        int sbits;
        int parity;
        int echo;
        HWND hwndserver;
        LPSTR cmd;
} COMCTL, far *LPCOMCTL;

typedef struct{
  int started;          // aquisition status: 1 if running, 0 else
  double runtime;		// realtime in seconds
  double totalsum;      // total events
  double roisum;        // events within ROI
  double totalrate;     // acquired total events per second

  double nettosum;      // ROI sum with background subtracted
  double sweeps;		// Livetime in seconds or sweeps for MCS mode
  double deadtime;      // deadtime in percent
  unsigned long maxval; // Maximum value in spectrum
} ACQSTATUS;

typedef struct{
  unsigned long range;  // spectrum length, ADC range 
  long prena;           // bit 0: realtime preset enabled
						// bit 1: livetime preset enabled
                        // bit 2: sweep preset enabled
                        // bit 3: ROI preset enabled
                        // bit 5: ROI2 preset enabled
  long mcsmode;         //  
						// bit 0: MCS 1 channel
						// bit 1: MCS 2 channel
						// mcsmode & 0x3==0: MCA mode
						// bit 2: MCA int. ADC        (MCA)
						// bit 3: sequential mode (MCA+MCS)
						// bit 4: tagged          (MCA+MCS)
						// bit 5: listmode        (MCA+MCS)
						// bit 6: Software Start      (MCS)
						// bit 7: differential mode   (MCS)
						// bit 8: Ch2 ref (diff.mode) (MCS)
						// bit 9: Autocorrelation     (MCS)
						// bit 10: enable sweep abort (MCS)
						// (bit 11: synchron tag) always on)   (MCA+MCS)
						// bit 12: use SCA Input  (MCS)
  unsigned long roimin; // lower ROI limit
  unsigned long roimax; // upper limit: roimin <= channel < roimax
  double eventpreset;   // ROI preset value
  double rtpreset;      // time preset value
  long savedata;        // bit 0: 1 if auto save after stop
						// bit 1: write listfile
						// bit 2: listfile only, no histogram
  long fmt;              // format type: 0 == ASCII, 1 == binary
  long autoinc;          // 1 if auto increment filename
  long diguse;           // Use of Dig I/O, GO Line:
                        // bit 0: status dig 0..3
                        // bit 1: Output digval and increment digval after stop
                        // bit 2: Invert polarity
						// bit 3: Push-Pull output
                        // bit 4..7:  Input pins 4..7 Trigger System 1..4
						// bit 8: GOWATCH
						// bit 9: GO High at Start
						// bit 10: GO Low at Stop
  long digval;          // digval=0..255 value for samplechanger
  long cycles;          // for sequential mode
  long sequences;       // for repeated sequential mode
  long mempart;         // number of active part
  unsigned long dwelltime;  // 32 bit value for FPGA
  long dwellunit;       // choice of units in dialog 0=ns, 1=usec, 2=msec, 3=sec 
						// bit 4: external clock (or manual channel advance)
  long syncout;         // sync out; bit 0..3 SyncOut1, 8..11 SyncOut2 
						// bit 7 Inv SyncOut1, bit 15 Inv SyncOut2
						// 0=CLK, 1=GATE/ABORT/ADV, 2=TRG/SAMPLE, 3=COUNT1, 4=COUNT2, 5=LIVE_INT,
						// 6=LIVE_EXT, 7=1kHz 8=SCA 9=ON, 10=EoBin,
						// 11=BIN_DIV, 12=STEP_CNT, 13=GO, 14=RAMP_DOWN, 15="1" 
  double ltpreset;      // Livetime preset value (MCA)
  long nregions;         // number of regions
  long caluse;           // bit 0 == 1 if calibration used, higher bits: formula
  double swpreset;       // sweep preset value
  long active;           // 1 for module enabled in system 1
  long calpoints;        // number of calibration points
} ACQSETTING;

typedef struct{
  long pol0;			// Handshake polarities (INI file)
  long timebase;		// elementary dwelltime unit nsec (EPROM, INI file)
  long dwellmin;		// minimum dwelltime (EPROM, INI file)
  long sernum;			// (EPROM)
  long version;			// (EPROM)
  long type;	        // Bit0=0: SCA present, 
						// Bit1=0: Internal ADC, 
						// Bit2=0: extern ADC, 
						// Bit3=0: Listmode
						// Bit4=0: MCS mode
						// Bit5: reserved, presently=1
} BOARDPROPERTY;

typedef struct{
  long thrstart;		  // DAC 6
  long thr1;			  // DAC 7
  long thr2;			  // DAC 8
  long thrclk;			  // DAC 5
  long qdacuse;			  // enable dac2 output
  long qdac;			  // DAC 1 (=dac2)
  long dac1use;			  // use ramp dac fixed in MCA mode
  long dac1val;			  // fix ramp dac value in MCA mode
  long rampmode;          // 0=fix, 1=triangle, 2=sawtooth 
  long rampstart; 	      // ramp start value, 
  long rampstep;          // step height
  long rampbin;           // step bin width
  long ramplen;           // no. of steps
  long impsel;			// impedance + edge select:
						// bit 0..3 50 Ohm Clk, Start, In1, In2
						// bit 4..6 rising Clk, Start, In1=In2 
  unsigned long roi2min;
  unsigned long roi2max;
  double roi2preset;
} DACSETTING;

typedef struct{
  long uld;				// upper level discriminator = DAC 2
  long lld;				// lower level discriminator = DAC 3
  long thd;			    // threshold = DAC 4
  long gate;			// gate enable
  //long impgate;			// 1=50 Ohm gate impedance 
  long coin;			// 1=coin or rising, 0=anti or falling
  long filter;			// 1=filter on
  long sva;				// external sampled conversion
  long slider;			// 0=OFF, 256, 1024, 8192 sliderrange
  // auxiliary for dialog box:
  long thrstart;		  // DAC 6 threshold for sampling
  long thrclk;			  // DAC 5 threshold for gate
  long impsel;			// impedance + edge select:
						// bit 0..1 50 Ohm Gate, Start
						// bit    5 rising  Start 
} ADCSETTING;

typedef struct{
  unsigned long range;  // spectrum length, ADC range 
  long prena;           // bit 0: realtime preset enabled
						// bit 1: livetime preset enabled
                        // bit 2: sweep preset enabled
                        // bit 3: ROI preset enabled
                        // bit 5: ROI2 preset enabled
  long mcsmode;         //  
						// bit 0: MCS 1 channel
						// bit 1: MCS 2 channel
						// mcsmode & 0x3==0: MCA mode
						// bit 2: MCA int. ADC        (MCA)
						// bit 3: sequential mode (MCA+MCS)
						// bit 4: tagged          (MCA+MCS)
						// bit 5: listmode        (MCA+MCS)
						// bit 6: Software Start      (MCS)
						// bit 7: differential mode   (MCS)
						// bit 8: Ch2 ref (diff.mode) (MCS)
						// bit 9: Autocorrelation     (MCS)
						// bit 10: enable sweep abort (MCS)
						// (bit 11: synchron tag) always on)   (MCA+MCS)
						// bit 12: Use SCA Input  (MCS)
  unsigned long roimin; // lower ROI limit
  unsigned long roimax; // upper limit: roimin <= channel < roimax
  double eventpreset;   // ROI preset value
  double rtpreset;      // time preset value
  long savedata;        // bit 0: 1 if auto save after stop
						// bit 1: write listfile
						// bit 2: listfile only, no histogram
  long fmt;              // format type: 0 == ASCII, 1 == binary
  long autoinc;          // 1 if auto increment filename
  long diguse;           // Use of Dig I/O, GO Line:
                        // bit 0: status dig 0..3
                        // bit 1: Output digval and increment digval after stop
                        // bit 2: Invert polarity
						// bit 3: Push-Pull output
                        // bit 4..7:  Input pins 4..7 Trigger System 1..4
						// bit 8: GOWATCH
						// bit 9: GO High at Start
						// bit 10: GO Low at Stop
  long digval;          // digval=0..255 value for samplechanger
  long cycles;          // for sequential mode
  long sequences;       // for repeated sequential mode
  long mempart;         // number of active part
  long dwelltime;       // 32 bit value for FPGA
  long dwellunit;       // bits 0..3: choice of units 0=ns, 1=usec, 2=msec, 3=sec
						// bit 4: external clock (or manual channel advance)
  long syncout;         // sync out; bit 0..3 SyncOut1, 8..11 SyncOut2 
						// bit 7 Inv SyncOut1, bit 15 Inv SyncOut2
						// 0=CLK, 1=GATE/ABORT/ADV, 2=TRG/SAMPLE, 3=COUNT1, 4=COUNT2, 5=LIVE_INT,
						// 6=LIVE_EXT, 7=1kHz 8=SCA 9=ON, 10=EoBin,
						// 11=BIN_DIV, 12=STEP_CNT, 13=GO, 14=RAMP_DOWN, 15="1" 
  double ltpreset;      // Livetime preset value (MCA)
  long nregions;         // number of regions
  long caluse;           // bit 0 == 1 if calibration used, higher bits: formula
  double swpreset;       // sweep preset value
  long active;           // 1 for module enabled in system 1
  long calpoints;        // number of calibration points
  long xdim;
  long ndim;
  long type;
  long reserved[13];
} EXTACQSETTING;

typedef struct{
  unsigned long HUGE *s0;          // pointer to spectrum
  unsigned long *region;       // pointer to regions
  unsigned char *comment0;     // pointer to strings
  double *cnt;                 // pointer to counters
  HANDLE hs0;
  HANDLE hrg;
  HANDLE hcm;
  HANDLE hct;
} ACQDATA;

typedef struct {
  int nDevices;          // Number of spectra = number of modules * 2
  int nDisplays;         // Number of active displays 0...nDevices
  int nSystems;          // Number of systems 0...4
  int bRemote;           // 1 if server controlled by MCDWIN
  unsigned int sys;        // System definition word:
                           // bit0=0, bit1=0: MCD#0 in system 1
                           // bit0=1, bit1=0: MCD#0 in system 2
                           // bit0=0, bit1=1: MCD#0 in system 3
                           // bit0=1, bit1=1: MCD#0 in system 4
                           // bit2=0, bit3=0: MCD#1 in system 1 ...
                           // bit6=1, bit7=1: MCD#3 in system 4 
} ACQDEF;

