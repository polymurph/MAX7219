#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>
#include "HAL/hal_spi.h"
#include "HWO/max7219.h"

/**
 * main.c
 */

void chip_select_init()
{
    PM5CTL0 &= ~LOCKLPM5;
    P2DIR |= 0x10;
    P2OUT |= 0x10;
    PM5CTL0 |= LOCKLPM5;

}

void chip_select(bool enable)
{
    if(enable){
        P2OUT &= ~0x10;
    } else {
        P2OUT |= 0x10;
    }
}


void _write_reg(max7219_reg_t reg,uint8_t data)
{
    chip_select(true);
    hal_spi_tx_byte(reg);
    hal_spi_tx_byte(data);
    chip_select(false);
}

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	// read on rising clk edge
	// CS low to set data
	// MSB first
	//
	chip_select_init();
	hal_spi_init(spi_mode_MASTER, spi_clk_source_ACLK, spi_clk_mode_2, 0,true);

	//_write_reg(max7219_reg_SHUTDOWN, 0x00); // shut down
	//_write_reg(max7219_reg_SHUTDOWN, 0x01); // normal operation
	_write_reg(0x08,0x08);
	//_write_reg(max7219_reg_DIGIT_1, 0xAA);

	while(1);
	{

	}


	return 0;
}
