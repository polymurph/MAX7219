#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>
#include "HAL/hal_spi.h"
#include "HAL/hal_clk.h"
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
    uint16_t i = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	// read on rising clk edge
	// CS low to set data
	// MSB first
	//
	chip_select_init();

	hal_clk_config_ACLK(clk_ACLK_src_LFXT, 0, true);

	hal_spi_init(spi_mode_MASTER, spi_clk_source_ACLK, spi_clk_mode_2, 0,true);

	_write_reg(0x0C, 0x00); // normal operation
	_write_reg(0x09, 0x00); // no decode
	_write_reg(0xFF, 0x00); // clear screen
	//_write_reg(max7219_reg_DISPLAY_TEST, 0x00);

	//_write_reg(0x0F,0xFF);
	while(1)
	{
	    for(i = 0; i < 0x2FFF; i++);
	    _write_reg(0xFF,0xFF);
	    for(i = 0; i < 0x2FFF; i++);
	    _write_reg(0xFF, 0x00);

	}
	while(1){
	    //_write_reg(max7219_reg_DISPLAY_TEST,0xAA);
	    //_write_reg(0x01,0x01);
	    //_write_reg(0xFE,0x00);
	    _write_reg((i = 0),0xFF);
	    _write_reg(i++,0xFF);
	    _write_reg(i++,0xFF);
	    _write_reg(i++,0xFF);
	    _write_reg(i++,0xFF);
	    _write_reg(i++,0xFF);
	}


	return 0;
}
