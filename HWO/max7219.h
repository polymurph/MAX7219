/*
 * max7219.h
 *
 *  Created on: 25.11.2019
 *      Author: timon
 */

#ifndef HWO_MAX7219_H_
#define HWO_MAX7219_H_

#define MAX7219_REG_NO_OP 0x00
#define MAX7219_REG_
#define MAX7219_REG_
#define MAX7219_REG_


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



#endif /* HWO_MAX7219_H_ */
