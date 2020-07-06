#include "segments.h"

SegmentsClass seg;

void setup()
{
	//Serial.begin(9600);
	
	seg.init();
	//seg.disp_tmr_set();
}

void loop()
{
	
	seg.display_on(3, 45, 67);
	
	
}



