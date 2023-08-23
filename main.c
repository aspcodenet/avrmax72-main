#include "max72xx.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

// Hej    

//// https://wokwi.com/projects/296234816685212169

 //DSAASDFDAS
 //sdffsdfsd

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


unsigned char b[] = {
    0B01111000,
    0B01001000,
    0B01001000,
    0B01110000,
    0B01001000,
    0B01000100,
    0B01000100,
    0B01111100};


int main()
{
	init_serial();
	max7219_init();
	int x = 0;
	int y = 0;
	unsigned char toBeWritten;
	int rrr = 99;
 
	while (1) {
        for(int row = 0; row < 8;row++){
            toBeWritten = b[row];
            for(int bitNumber = 7; bitNumber >=0; bitNumber--){
				int col = 7-bitNumber;
				if(BIT_CHECK(toBeWritten,bitNumber)){
					max7219b_set(col, row);		
				}
				else{
					max7219b_clr(col, row);
				}
			}
		}
		printf("Hej %d\n", rrr);
		rrr++;
		max7219b_out();
			// max7219b_set(3, 5); // HÄR HÄNDER INGET - double buffer
			// max7219b_set(4, 5); // HÄR HÄNDER INGET - double buffer
			// max7219b_set(5, 5); // HÄR HÄNDER INGET- double buffer 
			// max7219b_out(); // NU HÄNDER DET FYSISKT
			// _delay_ms(1000);

			// max7219b_clr(3, 5); 
			// max7219b_clr(4, 5);
			// max7219b_clr(5, 5);
			// max7219b_out(); // 
			
			_delay_ms(1000);
		}
	return 0;
}