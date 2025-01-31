409b Controls

The 409b frequency synthesizer outputs arbitrary sine curves with customizable voltages, frequencies and phases on 4 channels.
Specific details can be found in accompanying files.

There are two modes of operation for the synthesizer, table mode and regular mode:

-Regular Mode means that the synthesizer outputs a constant curve until the user gives a command.
-Table mode means that the user first populates a table of commands inside the synthesizer, which the synthesizer then executes, waiting given periods of time between the steps, or waiting for a Table Step (TS) command. 

Table Mode/Dithering
Table mode occupies the first two channels. Each entry in the table therefore has the following fields: Voltage, Phase, Frequency, Channel, Memory Dwell.
Voltage, Phase, Frequency: Parameters of the curve. 
Channel: 1 or 0, which channel this command affects.
Dwell: How much time to spend on this command, in 100us, in hex. A command of 00 means 100us and also go back to commmand 1. A command of ff means wait for a TS signal.  

To dither, the table mode is used. One of the channels needs to be programmed to give one frequency until a TS (dwell=ff), then another frequency, looping back to entry 1 (dwell=00). Only one channel needs to be set like this, but by default both are.

AOM Controls

To control an AOM, regular mode needs to be used, at voltage and frequency appropriate to the situation.


PROGRAM DOCUMENTATION

Before anything, make sure that the port (bottom left). is set correctly.

Dither Control
The simplest program to control the synthesizer is 409b_main.vi , located on magnesium, Mi Yan's account, Documents/NOVATECH409bFREQSYNTH.
This program can be run in two modes, controlled by the left-right switch in the center. When the switch points left, it will command the 409b to set its channels as directed, and send the command in the cmd box.
The table on the left allows the user to set voltage, freqencies, and phase. If you want to alter a channel, make sure to check its check-box above the table. Please ignore the Blanck entry in the table.

As the program runs, the vi confirms that the synthesizer is responding correctly by recording its responses in the gray table at the top. which should be identical to the commands, only encoded. Make sure that the responses appear after running the program.

Table control is activated by putting switch to the right. The command table is populated by the user, where the result table is read back, to confirm accuracy. The "response" column is the undeciphered version of the table entry.

To turn Table Mode on or off, use the checkbox beneath the switch. It is independent of the switch, so it is possible to make regular mode adjustments as well as switch the table mode on/off, but note that in table mode, channels 0, 1 run the table commands, not the regular mode commands.

To alter the table when table mode (TM) is on, you must first uncheck the TM box and run the vi, to turn off table mode, and only then make adjustments and rerun the table.


PulseBlaster

Channels 2,3 will always be available to run aoms, and therefore will be available to alter in the pulse blaster array. To do this, use the PulseBlast_Modern_r3_synth2, located in C:\instrumentvi\cameratrigger. 
Some helper vi's had to be adjusted, so load them from C:\instrumentvi\NOVATECH409BFREQSYNTH, if there is ambiguity.

To select changing the synthsizer parameter, select "9" in the parameters to change box, then make an array normally, using the linear array generator, and use the synth control to set initial values/which channels to set.



