// --------------------------------------------------------------------------
// TSTMCA3.C : DMCA3.DLL Software driver C example
// --------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#undef DLL
#include "dmca3.h"

#define MYRANGE 8192

HANDLE          hDLL = 0;

IMCA3GETSETTING  lpSet=NULL;
IMCA3NEWSTATUS   lpNewStat=NULL;
IMCA3GETSTATUS   lpStat=NULL;
IMCA3RUNCMD      lpRun=NULL;
IMCA3GETCNT      lpCnt=NULL;
IMCA3GETROI      lpRoi=NULL;
IMCA3GETDAT      lpDat=NULL;
IMCA3GETSTR      lpStr=NULL;
IMCA3SERVEXEC    lpServ=NULL;
IMCA3SMOOTH      lpSmooth=NULL;

ACQSETTING     Setting={0};
ACQDATA        Data={0};
ACQDEF         Def={0};
ACQSTATUS      Status={0};
unsigned long  Spec[MYRANGE];

short Board=0;

void help()
{
	printf("Commands:\n");
	printf("Q		Quit\n");
	printf("H		Help\n");
	printf("S       Status\n");
	printf("D       Data\n");
    printf("(... more see command language in MCDWIN help)\n");
    printf("\n");
}

void PrintStatus(ACQSTATUS *Stat)
{
  if(Stat->started) printf("ON\n"); else printf("OFF\n");
  printf("runtime= %.2lf\n", Stat->runtime);
  printf("total=   %lf\n", Stat->totalsum);
  printf("roi=     %lf\n", Stat->roisum);
  printf("totalrate= %.2lf\n", Stat->totalrate);
  printf("sweeps(livetime)=  %lf\n", Stat->sweeps);
}

void PrintSetting(ACQSETTING *Set)
{
  printf("range= %ld\n", Set->range);
  printf("prena= %x\n", Set->prena);
  printf("mcsmode= %d\n", Set->mcsmode);
  printf("roimin= %ld\n", Set->roimin);
  printf("roimax= %ld\n", Set->roimax);
  printf("eventpreset= %lg\n", Set->eventpreset);
  printf("rtpreset= %lg\n", Set->rtpreset);
  printf("savedata= %d\n", Set->savedata);
  printf("fmt= %d\n", Set->fmt);
  printf("autoinc= %d\n", Set->autoinc);
  printf("diguse= %x\n", Set->diguse);
  printf("digval= %d\n", Set->digval);
  printf("cycles= %d\n", Set->cycles);
  printf("mempart= %x\n", Set->mempart);
  printf("dwelltime= %x\n", Set->dwelltime);
  printf("dwellunit= %x\n", Set->dwellunit);
  printf("syncout= %x\n", Set->syncout);
  printf("ltpreset= %g\n", Set->ltpreset);

  printf("nregions= %d\n", Set->nregions);
  printf("caluse= %d\n", Set->caluse);
  printf("swpreset= %lg\n", Set->swpreset);
  printf("active= %d\n", Set->active);
  printf("calpoints= %d\n", Set->calpoints);
}

void PrintDat(unsigned long len)
{
  int i;
  printf("first 30 of %d datapoints\n", len);
  for (i=0; i<30; i++)
    printf("%lu\n", Spec[i]);
}

int run(char *command)
{
	int err;
	if (!stricmp(command, "H"))           help();
	else if (!stricmp(command,"Q"))       return 1;
	else if (!stricmp(command,"S")) {
      err = (*lpStat)(&Status, 0);
      PrintStatus(&Status);
	}
	else if (!stricmp(command,"M0")) (*lpSmooth)(0);
	else if (!stricmp(command,"M1")) (*lpSmooth)(1);
	else if (!stricmp(command,"D")) {
      (*lpSet)(&Setting, 0);  
	  if (Setting.range <= MYRANGE) {
	    (*lpDat)(Spec, 0);
	    PrintDat(Setting.range);
	  }
	  else printf("please check spectra range\n");
	}
	else {
		(*lpRun)(0, command);
		printf("%s\n", command);
	}
	return 0;
}

//int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmd, int nShow)
void main(int argc, char *argv[])  
{
  long Errset=0, Erracq=0, Errread=0;
  char command[80];

  hDLL = LoadLibrary("DMCA3.DLL");
  if(hDLL){
      lpSet=(IMCA3GETSETTING)GetProcAddress(hDLL,"GetSettingData");
	  lpNewStat=(IMCA3NEWSTATUS)GetProcAddress(hDLL,"GetStatus");
	  lpStat=(IMCA3GETSTATUS)GetProcAddress(hDLL,"GetStatusData");
	  lpRun=(IMCA3RUNCMD)GetProcAddress(hDLL,"RunCmd");
	  lpCnt=(IMCA3GETCNT)GetProcAddress(hDLL,"LVGetCnt");
	  lpRoi=(IMCA3GETROI)GetProcAddress(hDLL,"LVGetRoi");
	  lpDat=(IMCA3GETDAT)GetProcAddress(hDLL,"LVGetDat");
	  lpStr=(IMCA3GETSTR)GetProcAddress(hDLL,"LVGetStr");
	  lpServ=(IMCA3SERVEXEC)GetProcAddress(hDLL,"ServExec");
	  lpSmooth=(IMCA3SMOOTH)GetProcAddress(hDLL,"Smooth");
  }
  else return;

  // Initialize parameters
//  Errset = (*lpServ)(0);
  Errset = (*lpNewStat)(0);
  Errset = (*lpStat)(&Status, 0);
  PrintStatus(&Status);

  (*lpSet)(&Setting, 0);  
  //PrintSetting(&Setting);
 
  help();

  while(TRUE)
	{
		scanf("%s", command);
		if (run(command)) break;
	}

  FreeLibrary(hDLL);

  return;
}
