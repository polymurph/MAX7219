/*
 * max7219.c
 *
 *  Created on: 25.11.2019
 *      Author: Edwin Koch
 */
#include <stdint.h>
#include <stdbool.h>
#include "max7219.h"

static fptr_u8_t spi_tx = 0;
static fptr_b_t chip_sel = 0;

static inline void _write_reg(max7219_t*    device,
                              max7219_reg_t reg,
                              uint8_t       data)
{
    device->chipselect(true);
    device->spi_tx(reg);
    device->spi_tx(data);
    device->chipselect(false);
}

void max7219_set_decode_mode(max7219_t*     device,
                             max7219_dec_t  decode_mode)
{
    _write_reg(device,max7219_reg_DECODE_MODE, decode_mode);
}

void max7219_test_display(max7219_t*    device,
                          bool          enable)
{
    _write_reg(device,max7219_reg_DISPLAY_TEST, (enable) ? (0x01) : (0x00));
}

void max7219_shutdown(max7219_t* device,
                      bool      enable)
{
    _write_reg(device, max7219_reg_SHUTDOWN, (enable) ? (0x00) : (0x01));
}

void max7219_set_intensity(max7219_t*    device,
                           uint8_t      intensity)
{
    _write_reg(device, max7219_reg_INTENSITY, intensity);
}

void max7219_set_digit(max7219_t*   device,
                       uint8_t      digit,
                       uint8_t      data)
{
    digit &= 0x03;
    _write_reg(device, (max7219_reg_DIGIT_0 + digit), data);
}

void max7219_set_digit_0(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_0, data);
}

void max7219_set_digit_1(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_1, data);
}

void max7219_set_digit_2(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_2, data);
}

void max7219_set_digit_3(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_3, data);
}

void max7219_set_digit_4(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_4, data);
}

void max7219_set_digit_5(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_5, data);
}

void max7219_set_digit_6(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_6, data);
}

void max7219_set_digit_7(max7219_t* device,
                         uint8_t    data)
{
    _write_reg(device, max7219_reg_DIGIT_7, data);
}

void max7219_set_all_digits(max7219_t* device,const uint8_t* reg)
{
    _write_reg(device, max7219_reg_DIGIT_0, reg[0]);
    _write_reg(device, max7219_reg_DIGIT_1, reg[1]);
    _write_reg(device, max7219_reg_DIGIT_2, reg[2]);
    _write_reg(device, max7219_reg_DIGIT_3, reg[3]);
    _write_reg(device, max7219_reg_DIGIT_4, reg[4]);
    _write_reg(device, max7219_reg_DIGIT_5, reg[5]);
    _write_reg(device, max7219_reg_DIGIT_6, reg[6]);
    _write_reg(device, max7219_reg_DIGIT_7, reg[7]);
}

void max7219_erase_all_digits(max7219_t* device)
{
    _write_reg(device, max7219_reg_DIGIT_0, 0x00);
    _write_reg(device, max7219_reg_DIGIT_1, 0x00);
    _write_reg(device, max7219_reg_DIGIT_2, 0x00);
    _write_reg(device, max7219_reg_DIGIT_3, 0x00);
    _write_reg(device, max7219_reg_DIGIT_4, 0x00);
    _write_reg(device, max7219_reg_DIGIT_5, 0x00);
    _write_reg(device, max7219_reg_DIGIT_6, 0x00);
    _write_reg(device, max7219_reg_DIGIT_7, 0x00);
}





