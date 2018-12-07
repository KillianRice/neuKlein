mcl_FreqCounter.dll - ActiveX COM Object for programmers

This DLL file can be used by programmers of Visual Basic,VC++,Delphi,C#
LabView or any other program that recognize ActiveX COM Object DLL file.

mcl_FreqCounter.dll file should be located on system folder eg: "c:\windows\system32"
the file should be registered using regsvr32 windows program.

The DLL file include the following Functions:

1. int Connect(Optional *string SN)  :

SN parameter is needed in case of using more than 1 Switch Box.
SN is the Serial Number of the Switch Box and can be ignored if using only one box.


2. void Disconnect()

Recommanded to Disconnect the device while end of program


3. Int Get_Available_SN_List(string SN_List)

string SN_List is returned with all avaliable line stretchers connected to USB.
the function return the Number of line stretchers.

4. int GetStatus()

Function return the connection status. when connected , status is >0.

5. int Read_ModelName(string ModelName) As Integer
The Model Name returned in ModelName parameter.
The function return non zero number on success.

6. int Read_SN(string SN ) 
The Serial Number returned in SN parameter.
The function return non zero number on success.

7. int ReadFreq( double RetFreq) as integer
RetFreq is the returned frequency value.
The function return non zero number on success.

8. int SetRange( int RequestedRange ) 
The Frequency Counter by default works with Auto Range
To set the range maually - use this method.
RequestedRange is the desired Range eg: 1,2,3 or 4. for AutoRange use 255.
The function return non zero number on success.

9. string (bstr) GetRange()
return the actual range of the frequency counter.

10. int SetSampleTime( float SampleTime_sec )

SampleTime_Sec is the sample time in sec request for the frequency counter eg: 0.1, 0.5, 1,2.
The function return non zero number on success.

program Example in VB:

Dim FCTR As New MCL_FreqCounter.USB_FreqCounter,Status as integer
dim Freq as double
Status=FCTR.Connect
Status = FCTR.ReadFreq(Freq)
FCTR.Disconnect

 

program Example in Visual C++:

MCL_FreqCounter::USB_FreqCounter ^FCTR = gcnew MCL_FreqCounter::USB_FreqCounter();
short Status = 0;
double Freq;
System::String ^SN = "";
Status = FCTR->Connect(SN);
Status = FCTR->ReadFreq(Freq);
FCTR->Disconnect();




      