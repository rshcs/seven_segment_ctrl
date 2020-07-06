#include "segments.h"

SegmentsClass seg;

void setup()
{
	Serial.begin(9600);
	
	DDRL = 0xFF; // PORTL => output
	DDRC = 0xFF; // PORTC => output 
	DDRA = 0xFF; // PORTA => output

	PORTL = 0b00001111; // LEDs and LED control transistors
	PORTC = 0x7F; //7Segments
	PORTA = 0; // 7Segment control transistors
	
}

void loop()
{
	//segment_b(15);
	//Serial.println(powr(2,4));
	//delay(1000);
	//segment_on(&seg_a[0], 92);
	//segment_on(&seg_b[0], 45);
	//segment_on(&seg_c[0], 38);
	/*
	segment_out(1);
	for (int i = 0; i < 6; i++)
	{
		segment_ctrl(2 * a);
		a *= 2;
		delay(3000);
	}
	*/
	
	
	seg.test_segments(1000);
	//segment_b(25);
	
}



