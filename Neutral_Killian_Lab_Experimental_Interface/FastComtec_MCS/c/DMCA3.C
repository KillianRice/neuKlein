/***************************************************************************
  MODULE:   DMCA3.C
  PURPOSE:  DLL to communicate with mca3 Server
****************************************************************************/

#include "windows.h"
#include <string.h>
#include <stdio.h>
#include "dmca3.h"

#ifndef WINDOWS31
#pragma data_seg("dmca3sh")
#endif

ACQSTATUS DLLStatus[MAXDSP] = {0};
EXTACQSETTING DLLSetting[MAXDSP] = {0};
#ifdef WINDOWS31
ACQDATA DLLData[MAXDSP] = {0};
HANDLE  hInst=0;
#endif
ACQDEF DLLDef = {0};
REPLAYSETTING DLLRepl = {0};

BOOL    bRemote=0;
BOOL    bStatus[MAXDSP]={0};
BOOL    bSetting[MAXDSP]={0};
BOOL    bDef=FALSE;
BOOL    bRepl=FALSE;
HWND    hwndServer=0;
HWND    hwndClient=0;
UINT    MM_NEARCONTROL=0;
UINT    MM_GETVAL=0;
HWND    hwndMCDWIN=0;
DACSETTING DLLDacset[MAXDEV] = {0};
BOOL    bDacset[MAXDEV] = {0};

#ifndef WINDOWS31
#pragma data_seg()
#endif

#ifdef WINDOWS31
/****************************************************************************
    FUNCTION:  WEP(int)

    PURPOSE:  Performs cleanup tasks when the DLL is unloaded.  WEP() is
              called automatically by Windows when the DLL is unloaded (no
              remaining tasks still have the DLL loaded).  It is strongly
              recommended that a DLL have a WEP() function, even if it does
              nothing but returns success (1), as in this example.

*******************************************************************************/
int FAR PASCAL WEP (int bSystemExit)
{
    return(1);
}



/****************************************************************************
   FUNCTION: LibMain(HANDLE, WORD, WORD, LPSTR)

   PURPOSE:  Is called by LibEntry.  LibEntry is called by Windows when
             the DLL is loaded.  The LibEntry routine is provided in
             the LIBENTRY.OBJ in the SDK Link Libraries disk.  (The
             source LIBENTRY.ASM is also provided.)

             LibEntry initializes the DLL's heap, if a HEAPSIZE value is
             specified in the DLL's DEF file.  Then LibEntry calls
	     LibMain.

	     LibMain should return a value of 1 if the initialization is
	     successful.
*******************************************************************************/
int FAR PASCAL LibMain(hModule, wDataSeg, cbHeapSize, lpszCmdLine)
HANDLE	hModule;
WORD    wDataSeg;
WORD    cbHeapSize;
LPSTR   lpszCmdLine;
{

   hInst=hModule;
   MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
   if(cbHeapSize)
     UnlockData(0);
/*
   DLLDef.nDevices = 1;
   DLLDef.nDisplays = 1;
   DLLDef.nSystems = 1;
   DLLDef.sys = 0;
   bDef = TRUE;
   bStatus = FALSE;
   bSetting = FALSE;
*/
    return 1;
}

#else

BOOL APIENTRY DllMain(HANDLE hInst, DWORD ul_reason_being_called, LPVOID lpReserved)
{
    return 1;
        UNREFERENCED_PARAMETER(hInst);
        UNREFERENCED_PARAMETER(ul_reason_being_called);
        UNREFERENCED_PARAMETER(lpReserved);
}

#endif

VOID FAR PASCAL StoreDefData(ACQDEF FAR *Def)
{
  int i;
  if(Def == NULL) {
    bDef = FALSE;
    for (i=0; i<MAXDSP; i++) {
      bSetting[i] = FALSE;
      bStatus[i] = FALSE;
    }
  }
  else{
    _fmemcpy((LPSTR FAR *)&DLLDef,(LPSTR FAR *)Def,sizeof(ACQDEF));
    bDef = TRUE;
  }
}

int FAR PASCAL GetDefData(ACQDEF FAR *Def)
{
  if (bDef) {
    DLLDef.bRemote = bRemote;
    _fmemcpy((LPSTR FAR *)Def,(LPSTR FAR *)&DLLDef,sizeof(ACQDEF));
  }
  return bDef;
}

VOID FAR PASCAL StoreSettingData(ACQSETTING FAR *Setting, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if(Setting == NULL) {
    bSetting[nDisplay] = FALSE;
    bStatus[nDisplay] = FALSE;
  }
  else{
    _fmemcpy((LPSTR FAR *)&DLLSetting[nDisplay],
           (LPSTR FAR *)Setting,sizeof(ACQSETTING));
    bSetting[nDisplay] = TRUE;
    if(Setting->range == 0L) {
      bSetting[nDisplay] = FALSE;
      bStatus[nDisplay] = FALSE;
    }
  }
}

VOID FAR PASCAL StoreExtSettingData(EXTACQSETTING FAR *Setting, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if(Setting == NULL) {
    bSetting[nDisplay] = FALSE;
    bStatus[nDisplay] = FALSE;
  }
  else{
    _fmemcpy((LPSTR FAR *)&DLLSetting[nDisplay],
           (LPSTR FAR *)Setting,sizeof(EXTACQSETTING));
    bSetting[nDisplay] = TRUE;
    if(Setting->range == 0L) {
      bSetting[nDisplay] = FALSE;
      bStatus[nDisplay] = FALSE;
    }
  }
}

int APIENTRY GetSettingData(ACQSETTING FAR *Setting, int nDisplay)
{
//DebugBreak();
	if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
  if (bSetting[nDisplay]) {
    _fmemcpy((LPSTR FAR *)Setting,
           (LPSTR FAR *)&DLLSetting[nDisplay],sizeof(ACQSETTING));
  }
  return bSetting[nDisplay];
}

int APIENTRY GetExtSettingData(EXTACQSETTING FAR *Setting, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
  if (bSetting[nDisplay]) {
    _fmemcpy((LPSTR FAR *)Setting,
           (LPSTR FAR *)&DLLSetting[nDisplay],sizeof(EXTACQSETTING));
  }
  return bSetting[nDisplay];
}

VOID APIENTRY StoreData(ACQDATA FAR *Data, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if(Data == NULL) {
    bSetting[nDisplay] = FALSE;
    bStatus[nDisplay] = FALSE;
  }
#ifdef WINDOWS31
  else
    _fmemcpy((LPSTR FAR *)&DLLData[nDisplay],(LPSTR FAR *)Data,sizeof(ACQDATA));
#endif
}

int APIENTRY GetData(ACQDATA FAR *Data, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
#ifdef WINDOWS31
  if (bSetting[nDisplay]) {
    _fmemcpy((LPSTR FAR *)Data,(LPSTR FAR *)&DLLData[nDisplay],sizeof(ACQDATA));
  }
#endif
  return bSetting[nDisplay];
}

long APIENTRY GetSpec(long i, int nDisplay)
{
#ifdef WINDOWS31
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
  if (bSetting[nDisplay] && i < DLLSetting[nDisplay].range)
    return (DLLData[nDisplay].s0[i]);
  else return 0L;
#else
  char sz[40];
  HANDLE hs0;
  unsigned long *s0;
  unsigned long val;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
  if (!bSetting[nDisplay]) return 0;
  if ((unsigned long)i > DLLSetting[nDisplay].range) return 0;
  sprintf(sz,"MCA3_S0_%d",nDisplay);
  if (!(hs0 = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 0;
  if (!(s0 = (unsigned long *)MapViewOfFile(hs0,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hs0);
    return 0;
  }
  val = s0[i];
  UnmapViewOfFile(s0);
  CloseHandle(hs0);
  return val;
#endif
}

VOID APIENTRY GetBlock(long FAR *hist, int start, int end, int step,
  int nDisplay)
{
#ifdef WINDOWS31
  int i,j=0;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (end > DLLSetting[nDisplay].range) end = DLLSetting[nDisplay].range;
  for (i=start; i<end; i+=step, j++)
    *(hist + j) = DLLData[nDisplay].s0[i];
#else
  int i,j=0;
  char sz[40];
  HANDLE hs0;
  unsigned long *s0;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!bSetting[nDisplay]) return;
  if ((unsigned long)end > DLLSetting[nDisplay].range) end = (int)DLLSetting[nDisplay].range;
  sprintf(sz,"MCA3_S0_%d",nDisplay);
  if (!(hs0 = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return;
  if (!(s0 = (unsigned long *)MapViewOfFile(hs0,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hs0);
    return;
  }
  for (i=start; i<end; i+=step, j++)
    *(hist + j) = s0[i];
  UnmapViewOfFile(s0);
  CloseHandle(hs0);
  return;
#endif
}

int APIENTRY LVGetDat(unsigned long HUGE *datp, int nDisplay)
{
#ifdef WINDOWS31
  long i;
  if (bSetting[nDisplay]) {
    for (i=0; i<DLLSetting[nDisplay].range; i++)
      datp[i] = DLLData[nDisplay].s0[i];
    return 0;
  }
  else return 4;
#else
  unsigned long i;
  char sz[40];
  HANDLE hs0;
  unsigned long *s0;
  if ((nDisplay < 0) || (nDisplay >= MAXDSP)) return 3;
  if (!bSetting[nDisplay]) return 5;
  sprintf(sz,"MCA3_S0_%d",nDisplay);
  if (!(hs0 = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 6;
  if (!(s0 = (unsigned long *)MapViewOfFile(hs0,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hs0);
    return 7;
  }
  for (i=0; i<DLLSetting[nDisplay].range; i++)
      datp[i] = s0[i];
  UnmapViewOfFile(s0);
  CloseHandle(hs0);
  return 0;
#endif
}

int APIENTRY LVGetRoi(unsigned long FAR *roip, int nDisplay)
{
#ifdef WINDOWS31
  int i,n;
  n = 2 * DLLSetting[nDisplay].nregions;
  if (bSetting[nDisplay]) {
    for (i=0; i<n; i++)
      roip[i] = DLLData[nDisplay].region[i];
    return 0;
  }
  else return 4;
#else
  int i,n;
  char sz[40];
  HANDLE hrg;
  unsigned long *region;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 4;
  if (!bSetting[nDisplay]) return 4;
  sprintf(sz,"MCA3_RG_%d",nDisplay);
  if (!(hrg = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 4;
  if (!(region = (unsigned long *)MapViewOfFile(hrg,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hrg);
    return 4;
  }
  n = 2 * DLLSetting[nDisplay].nregions;
  for (i=0; i<n; i++)
    roip[i] = region[i];
  UnmapViewOfFile(region);
  CloseHandle(hrg);
  return 0;
#endif
}

int FAR PASCAL LVGetCnt(double FAR *cntp, int nDisplay)
{
#ifdef WINDOWS31
  int i;
  if (bSetting[nDisplay]) {
    for (i=0; i<MAXCNT; i++)
      cntp[i] = DLLData[nDisplay].cnt[i];
    return 0;
  }
  else return 4;
#else
  int i;
  char sz[40];
  HANDLE hct;
  double *cnt;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 4;
  if (!bSetting[nDisplay]) return 4;
  sprintf(sz,"MCA3_CT_%d",nDisplay);
  if (!(hct = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 4;
  if (!(cnt = (double *)MapViewOfFile(hct,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hct);
    return 4;
  }
  for (i=0; i<MAXCNT; i++)
    cntp[i] = cnt[i];
  UnmapViewOfFile(cnt);
  CloseHandle(hct);
  return 0;
#endif
}

int APIENTRY LVGetRate(int nDisplay, int *bin, double *rate1, double *rate2)
{
  char sz[40];
  HANDLE hct;
  double *cnt;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 4;
  if (!bSetting[nDisplay]) return 4;
  sprintf(sz,"MCA3_CT_%d",nDisplay);
  if (!(hct = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 4;
  if (!(cnt = (double *)MapViewOfFile(hct,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hct);
    return 4;
  }
  *bin = (int)cnt[17];
  *rate1 = cnt[15];
  *rate2 = cnt[16];
  UnmapViewOfFile(cnt);
  CloseHandle(hct);
  return 0;
}

int APIENTRY LVGetStr(char FAR *strp, int nDisplay)
{
#ifdef WINDOWS31
  int i;
  if (bSetting[nDisplay]) {
    for (i=0; i<1024; i++)
      strp[i] = DLLData[nDisplay].comment0[i];
    return 0;
  }
  else return 4;
#else
  int i;
  char sz[40];
  HANDLE hcm;
  char *comment0;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 4;
  if (!bSetting[nDisplay]) return 4;
  sprintf(sz,"MCA3_CM_%d",nDisplay);
  if (!(hcm = OpenFileMapping(FILE_MAP_READ, FALSE, sz)))
	return 4;
  if (!(comment0 = (char *)MapViewOfFile(hcm,
          FILE_MAP_READ, 0, 0, 0))) {
    CloseHandle(hcm);
    return 4;
  }
  for (i=0; i<1024; i++)
    strp[i] = comment0[i];
  UnmapViewOfFile(comment0);
  CloseHandle(hcm);
  return 0;
#endif
}

VOID APIENTRY StoreStatusData(ACQSTATUS FAR *Status, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if(Status == NULL)
    bStatus[nDisplay] = FALSE;
  else{
    _fmemcpy((LPSTR FAR *)&DLLStatus[nDisplay],
           (LPSTR FAR *)Status,sizeof(ACQSTATUS));
    bStatus[nDisplay] = TRUE;
  }
}

int APIENTRY GetStatusData(ACQSTATUS FAR *Status, int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return 0;
  if (bStatus[nDisplay]) {
    _fmemcpy((LPSTR FAR *)Status,
           (LPSTR FAR *)&DLLStatus[nDisplay],sizeof(ACQSTATUS));
  }
  return bStatus[nDisplay];
}

VOID APIENTRY Start(int nSystem)
{
  if (nSystem < 0 || nSystem > 3) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  switch (nSystem) {
    case 0:
     PostMessage(hwndServer, WM_COMMAND, ID_START, 0L);
     break;
    case 1:
     PostMessage(hwndServer, WM_COMMAND, ID_START2, 0L);
     break;
    case 2:
     PostMessage(hwndServer, WM_COMMAND, ID_START3, 0L);
     break;
    case 3:
     PostMessage(hwndServer, WM_COMMAND, ID_START4, 0L);
     break;
  }
}

VOID APIENTRY Halt(int nSystem)
{
  if (nSystem < 0 || nSystem > 3) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  switch (nSystem) {
    case 0:
     PostMessage(hwndServer, WM_COMMAND, ID_BREAK, 0L);
     break;
    case 1:
     PostMessage(hwndServer, WM_COMMAND, ID_BREAK2, 0L);
     break;
    case 2:
     PostMessage(hwndServer, WM_COMMAND, ID_BREAK3, 0L);
     break;
    case 3:
     PostMessage(hwndServer, WM_COMMAND, ID_BREAK4, 0L);
     break;
  }
}

VOID APIENTRY Continue(int nSystem)
{
  if (nSystem < 0 || nSystem > 3) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  switch (nSystem) {
    case 0:
     PostMessage(hwndServer, WM_COMMAND, ID_CONTINUE, 0L);
     break;
    case 1:
     PostMessage(hwndServer, WM_COMMAND, ID_CONTINUE2, 0L);
     break;
    case 2:
     PostMessage(hwndServer, WM_COMMAND, ID_CONTINUE3, 0L);
     break;
    case 3:
     PostMessage(hwndServer, WM_COMMAND, ID_CONTINUE4, 0L);
     break;
  }
}

VOID APIENTRY SaveSetting()
{
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  PostMessage(hwndServer, WM_COMMAND, ID_SAVE, 0L);
}

VOID APIENTRY NewSetting(int nDev)
{
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  //if (nDev>=0 && nDev<MAXDSP) bStatus[nDev] = FALSE;
  PostMessage(hwndServer, WM_COMMAND, ID_NEWSETTING, 0L);
}

VOID APIENTRY NewData()
{
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  PostMessage(hwndServer, WM_COMMAND, ID_NEWDATA, 0L);
}

int APIENTRY GetStatus(int nDev)
{
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  if (bStatus[nDev]) {
      SendMessage(hwndServer, WM_COMMAND, ID_GETSTATUS, 0L);
  }
  return bStatus[nDev];
}

UINT APIENTRY ServExec(HWND ClientWnd)
{
//DebugBreak();
  bRemote = 1;
  hwndClient = ClientWnd;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  if (hwndServer) {
    ShowWindow(hwndServer, SW_MINIMIZE);
//	AllowSetForegroundWindow(ASFW_ANY);
    return 32;
  }
  else
    return WinExec("MCA3.exe", SW_SHOW);
}

UINT APIENTRY ClientExec(HWND ServerWnd)
{
  if (ServerWnd) hwndServer = ServerWnd;
  return WinExec("MCDWIN /device=MCA3", SW_SHOW);
}

VOID APIENTRY UnregisterClient()
{
  hwndClient = 0;
  bRemote = 0;
}

VOID APIENTRY DestroyClient()
{
  bRemote = 0;
  if (hwndClient) SendMessage(hwndClient, WM_CLOSE, 0, 0L);
  hwndClient = 0;
}

VOID APIENTRY Erase(int nSystem)
{
  if (nSystem < 0 || nSystem > 3) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  switch (nSystem) {
    case 0:
     PostMessage(hwndServer, WM_COMMAND, ID_ERASE, 0L);
     break;
    case 1:
     PostMessage(hwndServer, WM_COMMAND, ID_ERASE2, 0L);
     break;
    case 2:
     PostMessage(hwndServer, WM_COMMAND, ID_ERASE3, 0L);
     break;
    case 3:
     PostMessage(hwndServer, WM_COMMAND, ID_ERASE4, 0L);
     break;
  }
}

VOID APIENTRY SaveData(int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  if (nDisplay==0) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE, 0L);
  else if(nDisplay==1) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE2, 0L);
  else if(nDisplay==2) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE3, 0L);
  else if(nDisplay==3) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE4, 0L);
  else if(nDisplay==4) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE5, 0L);
  else if(nDisplay==5) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE6, 0L);
  else if(nDisplay==6) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE7, 0L);
  else if(nDisplay==7) PostMessage(hwndServer, WM_COMMAND, ID_SAVEFILE8, 0L);
}

VOID APIENTRY LoadData(int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  bStatus[nDisplay] = FALSE;
  switch (nDisplay) {
    case 0:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE, 0L);
      break;
    case 1:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE2, 0L);
      break;
    case 2:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE3, 0L);
      break;
    case 3:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE4, 0L);
      break;
    case 4:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE5, 0L);
      break;
    case 5:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE6, 0L);
      break;
    case 6:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE7, 0L);
      break;
    case 7:
      PostMessage(hwndServer, WM_COMMAND, ID_LOADFILE8, 0L);
      break;
  }
}

VOID APIENTRY AddData(int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  bStatus[nDisplay] = FALSE;
  switch (nDisplay) {
    case 0:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE, 0L);
      break;
    case 1:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE2, 0L);
      break;
    case 2:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE3, 0L);
      break;
    case 3:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE4, 0L);
      break;
    case 4:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE5, 0L);
      break;
    case 5:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE6, 0L);
      break;
    case 6:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE7, 0L);
      break;
    case 7:
      PostMessage(hwndServer, WM_COMMAND, ID_SUMFILE8, 0L);
      break;
  }
}

VOID APIENTRY SubData(int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  bStatus[nDisplay] = FALSE;
  switch (nDisplay) {
    case 0:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT, 0L);
      break;
    case 1:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT2, 0L);
      break;
    case 2:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT3, 0L);
      break;
    case 3:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT4, 0L);
      break;
    case 4:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT5, 0L);
      break;
    case 5:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT6, 0L);
      break;
    case 6:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT7, 0L);
      break;
    case 7:
      PostMessage(hwndServer, WM_COMMAND, ID_SUBTRACT8, 0L);
      break;
  }
}

VOID APIENTRY Smooth(int nDisplay)
{
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  bStatus[nDisplay] = FALSE;
  switch (nDisplay) {
    case 0:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH, 0L);
      break;
    case 1:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH2, 0L);
      break;
    case 2:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH3, 0L);
      break;
    case 3:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH4, 0L);
      break;
    case 4:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH5, 0L);
      break;
    case 5:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH6, 0L);
      break;
    case 6:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH7, 0L);
      break;
    case 7:
      PostMessage(hwndServer, WM_COMMAND, ID_SMOOTH8, 0L);
      break;
  }
}

VOID FAR PASCAL HardwareDlg(int item)
{
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server", NULL);
  switch (item) {
    case 0:
      PostMessage(hwndServer, WM_COMMAND, ID_HARDWDLG, 0L);
      break;
    case 1:
      PostMessage(hwndServer, WM_COMMAND, ID_DATADLG, 0L);
      break;
    case 2:
      PostMessage(hwndServer, WM_COMMAND, ID_COMBDLG, 0L);
      break;
	case 4:
      PostMessage(hwndServer, WM_COMMAND, ID_REPLDLG, 0L);
      break;
  }
}

VOID APIENTRY RunCmd(int nDisplay, LPSTR Cmd)
{
#ifdef WINDOWS31
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  if (Cmd != NULL) {
    _fstrcpy(&DLLData[0].comment0[800], Cmd);
  }
#else
  char sz[40];
  HANDLE hcm;
  char *comment0;
  if (nDisplay < 0 || nDisplay >= MAXDSP) return;
  if (!bSetting[nDisplay]) return;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  sprintf(sz,"MCA3_CM_%d",nDisplay);
  if (!(hcm = OpenFileMapping(FILE_MAP_WRITE, FALSE, sz)))
	return;
  if (!(comment0 = (char *)MapViewOfFile(hcm,
          FILE_MAP_WRITE, 0, 0, 0))) {
    CloseHandle(hcm);
    return;
  }
  strcpy(&comment0[800], Cmd);
#endif
  switch (nDisplay) {
    case 0:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD, (LONG)(LPSTR)Cmd);
      break;
    case 1:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD2, (LONG)(LPSTR)Cmd);
      break;
    case 2:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD3, (LONG)(LPSTR)Cmd);
      break;
    case 3:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD4, (LONG)(LPSTR)Cmd);
      break;
    case 4:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD5, (LONG)(LPSTR)Cmd);
      break;
    case 5:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD6, (LONG)(LPSTR)Cmd);
      break;
    case 6:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD7, (LONG)(LPSTR)Cmd);
      break;
    case 7:
      SendMessage(hwndServer, MM_NEARCONTROL, ID_RUNCMD8, (LONG)(LPSTR)Cmd);
      break;
  }
#ifndef WINDOWS31
  strcpy(Cmd, &comment0[1024]);
  UnmapViewOfFile(comment0);
  CloseHandle(hcm);
#endif
}

int APIENTRY DigIn(int nDev)
{
  int val=0;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA-3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  val = SendMessage(hwndServer, MM_NEARCONTROL, ID_DIGIN, (LONG)nDev);
  return val;
}

int APIENTRY DigOut(int nDev, int value)
{
  int val=0;
  long lval;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA-3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  lval = MAKELONG((WORD)nDev, (WORD)value);
  val = SendMessage(hwndServer, MM_NEARCONTROL, ID_DIGOUT, (LONG)lval);
  return val;
}

int APIENTRY DigInOut(int nDev, int value, int enable)
{
  int val=0;
  long lval;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA-3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  value &= 0xFF;
  value |= ((enable & 0xFF) << 8);
  lval = MAKELONG((WORD)nDev, (WORD)value);
  val = SendMessage(hwndServer, MM_NEARCONTROL, ID_DIGINOUT, (LONG)lval);
  return val;
}

int APIENTRY CardSet(int nDev)
{
  int val=0;
  long lval;
  if (!hwndServer) hwndServer = FIND_WINDOW("MCA-3 Server",NULL);
  if (!MM_NEARCONTROL) MM_NEARCONTROL = RegisterWindowMessage((LPSTR)"MCWNEARCONTROL");
  lval = MAKELONG((WORD)nDev, (WORD)0);
  val = SendMessage(hwndServer, MM_NEARCONTROL, ID_CARDSET, (LONG)lval);
  return val;
}

long APIENTRY GetSVal(int DspID, long xval)
{
  long val=0;
  if (xval == -2) {
	  hwndMCDWIN = FIND_WINDOW("mcwframe-MCA3",NULL);
	  return (long)hwndMCDWIN;  
	  // should be called first to be sure that MCDWIN is started
  }
  if (!hwndMCDWIN) hwndMCDWIN = FIND_WINDOW("mcwframe-MCA3",NULL);
  if (!MM_GETVAL) MM_GETVAL = RegisterWindowMessage((LPSTR)"MCA3Getval");
  val = SendMessage(hwndMCDWIN, MM_GETVAL, (WPARAM)DspID, (LPARAM)xval);
    // for xval == -1 returns Display size
  return val;
}

VOID APIENTRY StoreDacSetting(DACSETTING *dacset, int nDevice)
{                                      // Stores DACSettings into the DLL
  if (nDevice < 0 || nDevice >= MAXDEV) return;
  if(dacset == NULL) {
    bDacset[nDevice] = FALSE;
  }
  else{
    _fmemcpy((LPSTR FAR *)&DLLDacset[nDevice],
           (LPSTR FAR *)dacset,sizeof(DACSETTING));
    bDacset[nDevice] = TRUE;
  }
}

int APIENTRY GetDacSetting(DACSETTING *dacset, int nDevice)
{                                      // Get DACSettings stored in the DLL
  if (nDevice < 0 || nDevice >= MAXDEV) return 0;
  if (bDacset[nDevice]) {
    _fmemcpy((LPSTR FAR *)dacset,
           (LPSTR FAR *)&DLLDacset[nDevice],sizeof(DACSETTING));
  }
  return bDacset[nDevice];
}

VOID APIENTRY StoreReplaySetting(REPLAYSETTING *Repldat)
{
  if(Repldat == NULL) {
    bRepl = FALSE;
  }
  else{
    _fmemcpy((LPSTR FAR *)&DLLRepl,(LPSTR FAR *)Repldat,sizeof(REPLAYSETTING));
    bRepl = TRUE;
  }
}

int APIENTRY GetReplaySetting(REPLAYSETTING *Repldat)
{
  if (bRepl) {
    _fmemcpy((LPSTR FAR *)Repldat,(LPSTR FAR *)&DLLRepl,sizeof(REPLAYSETTING));
  }
  return bRepl;
}

int FAR PASCAL LVGetSpecLength(int nDisplay)
{
  if (bSetting[nDisplay]) 
	  return DLLSetting[nDisplay].range;
  else
	  return -1;
}

