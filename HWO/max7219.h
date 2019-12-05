/*
 * max7219.h
 *
 *  Created on: 25.11.2019
 *      Author: timon
 */

#ifndef HWO_MAX7219_H_
#define HWO_MAX7219_H_
#include <stdint.h>

#define MAX7219_REG_NO_OP 0x00

typedef void (*fptr_u8_t)(uint8_t);
typedef void (*fptr_b_t)(bool);

typedef struct{
    fptr_u8_t spi_tx;
    fptr_b_t chipselect;
}max7219_t;


typedef enum{
    max7219_reg_NO_OP = 0x00,
    max7219_reg_DIGIT_0,
    max7219_reg_DIGIT_1,
    max7219_reg_DIGIT_2,
    max7219_reg_DIGIT_3,
    max7219_reg_DIGIT_4,
    max7219_reg_DIGIT_5,
    max7219_reg_DIGIT_6,
    max7219_reg_DIGIT_7,
    max7219_reg_DECODE_MODE,
    max7219_reg_INTENSITY,
    max7219_reg_SCAN_LIMIT,
    max7219_reg_SHUTDOWN,
    max7219_reg_DISPLAY_TEST = 0x0F
}max7219_reg_t;


typedef enum{
    max7219_dec_NO_DECODE = 0x00,
    max7219_dec_CODE_B_DIGIT_0,
    max7219_dec_CODE_B_DIGIT_0_TO_3 = 0x0F,
    max7219_dec_CODE_B_ALL_DIGITS = 0xFF,

}max7219_dec_t;

void max7219_init(max7219_t* device);

void max7219_set_decode_mode(max7219_t*     device,
                             max7219_dec_t  decode_mode);

void max7219_shutdown(max7219_t* device,
                      bool      enable);

void max7219_set_intensity(max7219_t*   device,
                           uint8_t      intensity);

void max7219_set_digit_0(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_1(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_2(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_3(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_4(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_5(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_6(max7219_t* device,
                         uint8_t    data);

void max7219_set_digit_7(max7219_t* device,
                         uint8_t    data);


#endif /* HWO_MAX7219_H_ */
