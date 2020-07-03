#define SEG_DELAY 3

//Test function variables
int8_t a = 1; 
int8_t b = 1;

//PORTA values according to segment control transistors
int8_t seg_a[3] = { 4, 16 };
int8_t seg_b[3] = { 2, 1 };
int8_t seg_c[3] = { 32, 8 };

// 0 to 10
uint8_t nums[11] = { 0x6F, 0x48, 0x3E, 0x5E, 0x59, 0x57, 0x77, 0x4C, 0x7F, 0x5F };

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
	//Serial.println(numbers(0), HEX);
	segment_on(&seg_a[0], 92);
	segment_on(&seg_b[0], 45);
	segment_on(&seg_c[0], 38);
	/*
	segment_out(1);
	for (int i = 0; i < 6; i++)
	{
		segment_ctrl(2 * a);
		a *= 2;
		delay(3000);
	}
	delay(1000);
	*/
	//test_segments(500);
	//segment_b(25);
}

void segment_out(uint8_t inVal)
{
	uint8_t port_val = 0x7F & ~inVal;
	PORTC = port_val;
}

void segment_ctrl(uint8_t inVal)
{
	uint8_t port_val = 0x3F & inVal;
	PORTA = port_val;
	
}

void test_segments(uint16_t delay_t)
{
	for (int i = 1; i < 8; i++)
	{
		segment_out(a);
		a *= 2;
		delay(10);

		for (int j = 1; j < 8; j++)
		{
			segment_ctrl(b);
			b *= 2;
			delay(delay_t);
		}
		b = 1;
	}
}

void segment_b(uint8_t in_val)
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

void segment_on(int8_t* in_addr, int in_val)
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