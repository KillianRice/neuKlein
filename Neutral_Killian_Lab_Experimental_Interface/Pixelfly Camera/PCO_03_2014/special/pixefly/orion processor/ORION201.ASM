;*******************************************************************
;***** PixelFly for ATMEL AT90S8515
;***** SAMPLE - PROGRAMM
;***** Title	:ORION
;***** Version	:2.01 Date: 27.09.00 EO
;*****		:
;***** for technical reference: http://www.atmel.com
;*******************************************************************
;
;PIN assignment:
;
;DSUB25 (ST6):    ORION:    action:
;----------------------------------
;OPTIN6  pin1  ---> PD3     trigger input
;I/O1    pin19 ---> PD5     blink LED
;I/O2    pin20 ---> PD4     busy output (LED)
;I/O3    pin21 ---> PD0     CCD exposure output
;I/O4    pin22 ---> PD1     CCD read output
;
.nolist
.include "c:\Source\Atmel\8515def.inc"
.list

;-------------------------------------------------------
;version:	vv.vv
;date:	dd.dd.yyyy

.EQU	vers = $0201
.EQU	date = $2709
.EQU	year = $2000

;-------------------------------------------------------
;DEFINITIONS:
;-------------------------------------------------------
.DEF	A     = r16
.DEF	flag  = r17
.DEF	B     = r18
.DEF	C     = r19
.DEF	D     = r20
.DEF	E     = r21
.DEF	H     = r22
.DEF	L     = r23
.DEF	I     = r24
.DEF	J     = r25
.DEF	XL    = r26
.DEF	XH    = r27
.DEF	YL    = r28
.DEF	YH    = r29
.DEF	ZL    = r30
.DEF	ZH    = r31
.DEF	LED   = r15


;-------------------------------------------------
;SPI Commands: (from PLUTO)
;-------------------------------------------------
.EQU	RD_PA      = $10	;read port A
.EQU	RD_PB      = $11	;read port B
.EQU	RD_PD      = $12	;read port D
.EQU	WR_PC      = $20	;write port C

;-------------------------------------------------
;MACRO Definitions:
;-------------------------------------------------
;++++++++
.macro	PUSHAF	;save a,SREG
	push	a		;save <a>
	in	a,SREG	;save flag-register
	push	a
.endmacro
;++++++++
.macro	POPAF		;save a,SREG
	pop	a		;restore register
	out	SREG,a
	pop	a
.endmacro
.listmac

;-------------------------------------------------
;Interrupt vectors:
;-------------------------------------------------
AAAA:	.org	0
	rjmp	START		;Reset
	rjmp	AAAA		;INT0
	rjmp	INT1_INT	;INT1		;TRIGGER input
	rjmp	AAAA		;TIM1_CAPT	;Timer1 capture
	rjmp	AAAA		;TIM1_COMPA	;Timer1 compare A
	rjmp	AAAA		;TIM1_COMPB	;Timer1 compare B
	rjmp	AAAA		;TIM1_OVF	;Timer1 overflow
	rjmp	T0_INT	;TIM0_OVF	;Timer0 overflow
	rjmp	SPI_INT	;SPI_TX	;SPI TX
	rjmp	AAAA		;UART_RX	;UART RX
	rjmp	AAAA		;UART_DE	;UART Data empty
	rjmp	AAAA		;UART_TX	;UART TX
	rjmp	AAAA		;ANA_COMP	;Analog Comperator

;---------------------------------------
;ASCII text area:
;---------------------------------------
.DB	$00,$00,$00,$00,$00,$00
.DB	$28,$63,$29,$50,$43,$4f,$20,$47	;"(c)PCO G"
.DB	$6d,$62,$48,$20,$20,$20,$20,$20	;"mbH     "
.DB	$76,$65,$72,$73,$2e,$20,$4f,$52	;"vers. OR"
.DB	$49,$4f,$4e,$20,$20,$20,$20,$20	;"ION     "
.DB	high(vers),low(vers)
.DB	high(date),low(date)
.DB	high(year),low(year)
.DB	$20,$20,$20,$20,$20,$20,$20,$20,$20,$20


;	********************************************
;	***                                      ***
;	***     I N I T    Hardware, Software    ***
;	***                                      ***
;	********************************************

START:
        ldi     a,low(RAMEND)
        out     SPL,a         ;init Stack Pointer Low     
        ldi     a,high(RAMEND)
        out     SPH,a         ;init Stack Pointer High

;portA = A0 output; A7..A1 input 
	ldi	a,0b00000001
	out	DDRA,a
	ldi	a,0b00000000	;set TRIG = 0 (trigger is rising edge)
	out	PORTA,a

;portB = B6 output; B7,B5..B0 input
	ldi	a,0b01000000
	out	DDRB,a
	ldi	a,0b01000000
	out	PORTB,a
;portC = all output
	ldi	a,0b11111111
	out	DDRC,a
	ldi	a,0b00000000	;High side = 0
	out	PORTC,a
;portD = D7,D5,D4,D1,D0 output; D6,D3,D2 input
	ldi	a,0b10110011
	out	DDRD,a
	ldi	a,0b00110011	;LED = off; SPI_ACKN (PD7) = 0
	out	PORTD,a
;set SPI as slave
	ldi	a,0b11000000	;set mode, clk/4, enable INT
	out	SPCR,a
	
;set HW Interrupt
	ldi	a,0b10000000	;INT1 (PD3)
	out	GIMSK,a
	ldi	a,0b00001010	;falling edge on INT1
	out	MCUCR,a

;set timers
	ldi	a,$42
	out	TIMSK,a		;enable timer0,1 int
	out	TIFR,a
	ldi	a,5			;start timer with clock/1024
	out	TCCR0,a

;set SW flags
;init sw variables
	clr	flag
	clr	LED



;	********************************************
;	***                                      ***
;	***         M A I N  -  Programm         ***
;	***                                      ***
;	********************************************

MAIN:	sei			;global interrupt enable

	sbrc	flag,0	;test SPI flag
	rcall	SPI
	rcall	CCD		;CCD status out
	rjmp	MAIN

;------------------------------------------------------------------
CCD:
	;read status from CIRCE
	;CCDbusy (PA7), CCDread (PA6), CCDexp (PA5)
	;and output to portD
	;PA7-->PD4; PA6-->PD1; PA5-->PD0
;------------------------------------------------------------------
	in	a,PINA
	com	a		;complement a
	asr	a
	asr	a
	ror	a
	ror	a
	ror	a
	andi	a,0b00010011
	in	b,PORTD
	andi	b,0b11101100
	or	a,b
	out	PORTD,a
	ret


;------------------------------------------------------------------
SPI:
	;Commands to SPI are sent with a 2 byte sequence.
	;The first byte is the command, the 2. byte is the data
	;which is read and at the same time written back
	;depending of the command value.
	;For acknowledging PLUTO the SPI_ACKN (PD7) must be pulsed.
;------------------------------------------------------------------
	andi	flag,$fe		;clr SPI flag

	in	a,SPDR		;get SPI 1.byte (cmnd)

	cpi	a,RD_PA		;scan commands
	breq	S_RD_PA
	cpi	a,RD_PB
	breq	S_RD_PB
	cpi	a,RD_PD
	breq	S_RD_PD
	cpi	a,WR_PC
	breq	S_WR_PC
	rjmp	S_none		;no valid command

S_RD_PA:	;read port A
	in	a,PINA
	out	SPDR,a		;write SPI
	rjmp	SPI_in	
S_RD_PB:	;read port B
	in	a,PINB
	out	SPDR,a		;write SPI
	rjmp	SPI_in	
S_RD_PD:	;read port D
	in	a,PIND
	out	SPDR,a		;write SPI
	rjmp	SPI_in	
S_none:	;send command back
	out	SPDR,a
	rjmp	SPI_in

S_WR_PC:	;write port C
	rcall	SPI_in		;read 2. byte
	out	PORTC,a		;set port C
	ret
	
SPI_in:	;read 2.byte
	sbi	PORTD,7		;P_ACKN=1
	mov	a,flag
	andi	a,1			;test SPI flag
	breq	SPI_in
	in	a,SPDR		;read it
	andi	flag,$fe		;clr SPI flag
	cbi	PORTD,7		;P_ACKN=0
	ret




;	********************************************
;	***                                      ***
;	***      Interrupt Service Routines      ***
;	***                                      ***
;	********************************************

;-------------------------------------------------------
;- 8 bit counter interrupt service routine
;-------------------------------------------------------
T0_INT:
	;toggle LED PD5 for demonstration

	sei			;enable global int for TRIGGER
	PUSHAF

	inc	LED
	mov	a,LED
	andi	a,$08		;/8
	breq	T0_INT1
	cbi	PORTD,5	;LED PD5 = on
	rjmp	T0_INT9

T0_INT1:			;LED PD5 = off
	sbi	PORTD,5

T0_INT9:
	POPAF
	reti

;-------------------------------------------------------
;- INT1 interrupt service routine
;-------------------------------------------------------
INT1_INT:
	;this routine has higher priority and can
	;interrupt the other interrupt-service-routines 
	;SREG and <a> register are not affected

	;make the trigger - logic here
	;in this sample pass it through PA0 (TRIG) with 500ns

	sbi	PORTA,0		;TRIG=1
	nop
	nop
	cbi	PORTA,0		;TRIG=0

	reti

;-------------------------------------------------------
;- SPI interrupt service routine
;-------------------------------------------------------
SPI_INT:
	;This routine can be interrupted by the INT1.
	;
	;set the flag to tell the main programm
	;that a byte from SPI is avaiable

	sei
	PUSHAF
	ori	flag,1
	POPAF
	reti


;*********************************************************
;*********************************************************
