#include <REGX52.h>

#define INPUT 0xFF
#define OUTPUT 0x00

void delay(long ms)
{
	int i;
	
	for (i = 0; i < ms; i++)
	{
		TMOD = 0x01;    // Timer0 mode1
		TH0 = 0xFC;      //initial value for 1ms
		TL0 = 0x66;
		TR0 = 1;      // timer start
		while(TF0 == 0);  // check overflow condition
		TR0 = 0;     // Stop Timer
		TF0 = 0;    // Clear flag	
	}
}

void setup()
{
	P1_2 = 0x00;    // all pins of PORT2 declared as output
}

void loop()
{
	P1_2 = 1; // pin P1_2 high
	delay(100);
	P1_2 = 0; // pin P1_2 low
	delay(100);
}

void main()
{
	setup();
	
	while(1) 
	{
		loop();
	}
 }