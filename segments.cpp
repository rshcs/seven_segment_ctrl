
#include "segments.h"

SegmentsClass::SegmentsClass()
{

}


void SegmentsClass::segment_out(uint8_t inVal)
{
	uint8_t port_val = 0x7F & ~inVal;
	PORTC = port_val;
}

void SegmentsClass::segment_ctrl(uint8_t inVal)
{
	uint8_t port_val = 0x3F & inVal;
	PORTA = port_val;

}

void SegmentsClass::test_segments(uint16_t delay_t)
{
	for (int i = 0; i < 7; i++)
	{
		segment_out(powr(2, i));
		for (int i = 0; i < 6; i++)
		{
			segment_ctrl(powr(2, i));
			delay(delay_t);
		}
	}
}

int16_t SegmentsClass::powr(int16_t inNum, int16_t inPow)
{

	int16_t outNum = 1;
	for (int16_t i = 0; i < inPow; i++)
	{
		outNum *= inNum;
	}
	return outNum;
}

void SegmentsClass::segment_b(uint8_t in_val)
{
	if (in_val > 99)
	{
		segment_out(nums[9]);
		segment_ctrl(8);
		delay(SEG_DELAY);

		segment_out(nums[9]);
		segment_ctrl(32);
		delay(SEG_DELAY);
	}
	else
	{
		segment_out(nums[in_val / 10]);
		segment_ctrl(8);
		delay(SEG_DELAY);

		segment_out(nums[in_val % 10]);
		segment_ctrl(32);
		delay(SEG_DELAY);
	}
}

void SegmentsClass::segment_on(int8_t* in_addr, int in_val)
{
	/*
	Serial.print(*in_addr, BIN);
	Serial.print("|");
	Serial.println(*(in_addr + 1), BIN);
	*/

	if (in_val > 99)
	{
		segment_out(nums[9]);
		segment_ctrl(*in_addr);
		delay(SEG_DELAY);

		segment_out(nums[9]);
		segment_ctrl(*(in_addr + 1));
		delay(SEG_DELAY);
	}
	else
	{
		segment_out(nums[in_val / 10]);
		segment_ctrl(*in_addr);
		delay(SEG_DELAY);

		segment_out(nums[in_val % 10]);
		segment_ctrl(*(in_addr + 1));
		delay(SEG_DELAY);
	}

}


