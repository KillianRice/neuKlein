Programming Instruction of using mini-circuits USB Freq Counter

The USB Freq Counter is based on HID USB control.
LINUX and Windows Programmers who familiar with open connection to
USB HID devices can easily communicate with this device.

To create a connection to the USB Freq Counter -  Vendor ID and Product ID are required:

Mini-Circuits Vendor ID is: 0x20CE
USB Freq Counter Product ID is : 0x10


The communication with the device is done by USB Interrupt.
The Transmit and receive buffer size is 64 bytes.

Transmit Array should be 64 bytes
Receive  Array should be 64 bytes

the 1st byte of the Recieved array always will be the same as the 1st byte of the Trnsmit array.


commands:

1. Read Device Model Name:

To get the device model name you should send to the device code number 40 within the 1st byte of the 64 total.

1st byte=40 
2nd byte =0
3rd byte =0
.
.
.
#64 byte=0


The model name will be return in the receive array in ascii characters ending with 0.
1st byte=40
2nd byte to the byte with value=0 = [model name]


2. Get Device Serial Number
To get the device Serial Number , code number 41 should be send
1st byte=41
The Serial Number will be return in the receive array in ascii characters ending with 0.
1st byte=41
2nd byte to the byte with value=0 = Serial Number



3. Read The Freq or Range 
Reading the Freq is done by reading the 1st and 2nd LCD of the Frequency counter
1st line containg Range information, 2nd line is the Frequency result
the code should be send is 2
1st byte: 2
the returned 64 byte array is as follows:
1st byte: 2
2nd byte to Byte17 the ascii value of 16 characters of the 1st LCD line
Byte18 to Byte33  the ascii value of 16 characters of the 2nd LCD line

4. Set the Range  
By default Freq Counter is in "AutoRange" mode.
to set the range manually send the code 4
1st byte: 4
2nd byte: the range value. can be any legal range value. for auto range  need to be 255.
the 64 byte array is:
1st byte: 4

5. Set the Sample Time   
By default Freq Counter Sample Time is 1 sec.
you can set the sample time from 0.1 sec and up in step of 0.1 sec.

to set the Sample Time send the code 3
1st byte: 3
2nd byte: the sample value in sec double 10.
for example: to set the sample time  to 0.4 sec 2nd byte need to be: 4
the 64 byte array is:
1st byte: 3




























